# launch/diter.launch.py  — ROS2 (Humble) version of ROS1 diter.launch
import os
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.conditions import IfCondition
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    pkg_share = get_package_share_directory('legkilo')

    # diter.yaml을 ROS2 파라미터로 변환해둔 파일(앞서 제공한 legkilo_params.yaml)
    default_params = os.path.join(pkg_share, 'config', 'legkilo_params.yaml')
    rviz_config    = os.path.join(pkg_share, 'rviz', 'legkilo.rviz')

    # ---- Launch arguments ----
    params_arg = DeclareLaunchArgument(
        'params_file',
        default_value=default_params,
        description='YAML parameters file (converted from diter.yaml).'
    )
    use_rviz_arg = DeclareLaunchArgument(
        'use_rviz',
        default_value='false',
        description='Launch RViz2 with a preset config.'
    )

    # ---- Main node ----
    legkilo_node = Node(
        package='legkilo',
        executable='legkilo_node',     # CMake에서 만든 실행파일명
        name='legkilo',
        output='screen',
        emulate_tty=True,
        # note: ROS2에서는 커맨드라인 인자 대신 파라미터 파일을 넘긴다.
        parameters=[LaunchConfiguration('params_file')],
    )

    # ---- RViz (optional) ----
    rviz_node = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        output='screen',
        arguments=['-d', rviz_config],
        condition=IfCondition(LaunchConfiguration('use_rviz')),
    )

    return LaunchDescription([
        params_arg,
        use_rviz_arg,
        legkilo_node,
        rviz_node,
    ])

