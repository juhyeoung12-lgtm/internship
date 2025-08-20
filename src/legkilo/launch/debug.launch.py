# launch/debug.launch.py  — ROS2 (Humble) equivalent of ROS1 debug.launch
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():
    # 패키지 공유 경로(ROS1의 $(find legkilo) 대체)
    pkg_share = get_package_share_directory('legkilo')
    default_cfg = os.path.join(pkg_share, 'config', 'leg_fusion.yaml')

    # --- launch args ---
    config_file_arg = DeclareLaunchArgument(
        'config_file',
        default_value=default_cfg,
        description='Path to YAML config for legkilo'
    )

    # --- node (gdb로 실행) ---
    legkilo_node = Node(
        package='legkilo',
        executable='legkilo_node',
        name='legkilo',
        output='screen',
        emulate_tty=True,  # 터미널 컬러/줄바꿈 보기 좋게
        # ROS2에서는 CLI 인자 대신 파라미터로 넘기는 게 자연스럽다.
        parameters=[{'config_file': os.environ.get('LEGKILO_CONFIG', '') or
                     launch.substitutions.LaunchConfiguration('config_file')}],
        # ROS1 debug.launch의 `launch-prefix="gdb -ex run --args"` 대응
        prefix=['gdb', '-ex', 'run', '--args'],
    )

    return LaunchDescription([
        config_file_arg,
        legkilo_node
    ])
