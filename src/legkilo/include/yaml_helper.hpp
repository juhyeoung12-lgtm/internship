#ifndef LEG_KILO_YAML_HELPER_HPP
#define LEG_KILO_YAML_HELPER_HPP

#include <string>
#include <vector>
#include <array>
#include <type_traits>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <system_error>

#include <Eigen/Core>
#include <Eigen/Geometry>

#include "glog_utils.hpp"

#if __has_include(<yaml-cpp/yaml.h>)
  #include <yaml-cpp/yaml.h>
#else
  #error "yaml-cpp not found. Please install libyaml-cpp-dev and add find_package(yaml-cpp) in CMake."
#endif

namespace legkilo {
namespace yaml {

// ------------------------------
// Path helpers
// ------------------------------
inline std::string dirname(const std::string& p) {
  auto pos = p.find_last_of("/\\");
  return (pos == std::string::npos) ? std::string() : p.substr(0, pos);
}
inline std::string joinPath(const std::string& a, const std::string& b) {
  if (a.empty()) return b;
  if (b.empty()) return a;
  const bool a_sep = a.back() == '/' || a.back() == '\\';
  const bool b_sep = b.front() == '/' || b.front() == '\\';
  if (a_sep && b_sep) return a + b.substr(1);
  if (!a_sep && !b_sep) return a + "/" + b;
  return a + b;
}
inline std::string resolvePath(const std::string& base_file, const std::string& maybe_rel) {
  if (maybe_rel.empty()) return maybe_rel;
  // absolute?
  if (maybe_rel.size() >= 1 && (maybe_rel[0] == '/' || maybe_rel[0] == '\\')) return maybe_rel;
#ifdef _WIN32
  if (maybe_rel.size() >= 2 && std::isalpha((unsigned char)maybe_rel[0]) && maybe_rel[1] == ':') return maybe_rel;
#endif
  return joinPath(dirname(base_file), maybe_rel);
}

// ------------------------------
// File load
// ------------------------------
inline YAML::Node loadFile(const std::string& file) {
  try {
    LOG(INFO) << "[yaml] load " << file;
    return YAML::LoadFile(file);
  } catch (const std::exception& e) {
    LOG(ERROR) << "[yaml] fail to load " << file << " : " << e.what();
    throw;
  }
}

// ------------------------------
// Scalar/sequence getters
// ------------------------------
template <typename T>
inline bool tryGet(const YAML::Node& node, const std::string& key, T& out) {
  if (!node || !node[key]) return false;
  try {
    out = node[key].as<T>();
    return true;
  } catch (const std::exception& e) {
    LOG(ERROR) << "[yaml] key '" << key << "' parse error: " << e.what();
    return false;
  }
}

template <typename T>
inline T get(const YAML::Node& node, const std::string& key, const T& fallback) {
  T val{};
  if (tryGet(node, key, val)) return val;
  return fallback;
}

template <typename T>
inline T require(const YAML::Node& node, const std::string& key, const char* hint = nullptr) {
  if (!node || !node[key]) {
    std::ostringstream oss; oss << "Missing key '" << key << "'";
    if (hint) oss << " (" << hint << ")";
    throw std::runtime_error(oss.str());
  }
  try { return node[key].as<T>(); }
  catch (const std::exception& e) {
    std::ostringstream oss; oss << "Key '" << key << "' parse error: " << e.what();
    throw std::runtime_error(oss.str());
  }
}

template <typename T>
inline std::vector<T> getVec(const YAML::Node& node, const std::string& key, const std::vector<T>& fallback = {}) {
  if (!node || !node[key]) return fallback;
  std::vector<T> v;
  try {
    for (const auto& n : node[key]) v.emplace_back(n.as<T>());
  } catch (const std::exception& e) {
    LOG(ERROR) << "[yaml] key '" << key << "' vector parse error: " << e.what();
    return fallback;
  }
  return v;
}

template <typename T, std::size_t N>
inline std::array<T, N> getArray(const YAML::Node& node, const std::string& key, const std::array<T, N>& fallback = {}) {
  if (!node || !node[key]) return fallback;
  std::array<T, N> a{};
  try {
    if (!node[key].IsSequence() || node[key].size() != N) return fallback;
    for (std::size_t i = 0; i < N; ++i) a[i] = node[key][i].as<T>();
  } catch (const std::exception& e) {
    LOG(ERROR) << "[yaml] key '" << key << "' array<" << N << "> parse error: " << e.what();
    return fallback;
  }
  return a;
}

// ------------------------------
// Eigen helpers
// ------------------------------
inline Eigen::Vector3d getVec3(const YAML::Node& node, const std::string& key,
                               const Eigen::Vector3d& fallback = Eigen::Vector3d::Zero()) {
  auto a = getArray<double, 3>(node, key);
  if (a == std::array<double,3>{}) return fallback;
  return Eigen::Vector3d(a[0], a[1], a[2]);
}

inline Eigen::Quaterniond getQuatXYZW(const YAML::Node& node, const std::string& key,
                                      const Eigen::Quaterniond& fallback = Eigen::Quaterniond::Identity()) {
  auto a = getArray<double, 4>(node, key);
  if (a == std::array<double,4>{}) return fallback;
  Eigen::Quaterniond q(a[3], a[0], a[1], a[2]); // [x,y,z,w] -> (w,x,y,z)
  q.normalize(); if (q.w() < 0) q.coeffs() *= -1.0;
  return q;
}

inline Eigen::Matrix3d getMat3x3(const YAML::Node& node, const std::string& key,
                                 const Eigen::Matrix3d& fallback = Eigen::Matrix3d::Identity()) {
  if (!node || !node[key]) return fallback;
  const auto& m = node[key];
  try {
    if (!m.IsSequence() || m.size() != 9) return fallback;
    Eigen::Matrix3d R;
    for (int i = 0; i < 9; ++i) R(i/3, i%3) = m[i].as<double>();
    return R;
  } catch (const std::exception& e) {
    LOG(ERROR) << "[yaml] key '" << key << "' 3x3 parse error: " << e.what();
    return fallback;
  }
}

// ------------------------------
// Nested helpers
// ------------------------------
inline const YAML::Node child(const YAML::Node& node, const std::string& key) {
  return (node ? node[key] : YAML::Node());
}

inline YAML::Node requireChild(const YAML::Node& node, const std::string& key, const char* hint = nullptr) {
  if (!node || !node[key]) {
    std::ostringstream oss; oss << "Missing section '" << key << "'";
    if (hint) oss << " (" << hint << ")";
    throw std::runtime_error(oss.str());
  }
  return node[key];
}

// ------------------------------
// Example: config struct fill (사용 예시)
// ------------------------------
template <typename ConfigT>
inline bool fillIfPresent(const YAML::Node& node, const std::string& key, ConfigT& field) {
  if (!node || !node[key]) return false;
  try { field = node[key].as<Co

