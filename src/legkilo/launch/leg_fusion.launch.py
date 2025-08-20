# launch/leg_fusion.launch.py — ROS2 (Humble) equivalent of ROS1 leg_fusion.launch
import os
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    pkg_share = get_package_share_directory('legkilo')
    default_cfg  = os.path.join(pkg_share, 'config', 'leg_fusion.yaml')
    rviz_config  = os.path.join(pkg_share, 'rviz', 'legkilo.rviz')

    # Arguments (ROS1의 <arg name="config_file" ...> 대체)
    config_arg = DeclareLaunchArgument(
        'config_file',
        default_value=default_cfg,
        description='Path to YAML config for legkilo'
    )

    # 메인 노드 (일반 실행; 파라미터로 config 전달)
    legkilo_node = Node(
        package='legkilo',
        executable='legkilo_node',   # CMake에서 만든 실행파일명에 맞춰 필요시 수정
        name='legkilo',
        output='screen',
        emulate_tty=True,
        parameters=[{'config_file': LaunchConfiguration('config_file')}],
    )

    # RViz2 실행 (ROS1의 rviz 노드 대체)
    rviz_node = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        output='screen',
        arguments=['-d', rviz_config],
        prefix=['nice'],  # ROS1의 launch-prefix="nice" 대응
    )

    return LaunchDescription([
        config_arg,
        legkilo_node,
        rviz_node,
    ])
