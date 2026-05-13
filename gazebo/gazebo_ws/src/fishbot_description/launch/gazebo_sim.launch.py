import launch
import launch_ros
from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import ExecuteProcess, TimerAction
from ament_index_python.packages import get_package_share_directory
import subprocess
import os

def generate_launch_description():
    pkg_path = get_package_share_directory('fishbot_description')
    xacro_path = os.path.join(pkg_path, 'urdf', 'fishbot', 'fishbot.urdf.xacro')
    
    world_path_install = os.path.join(pkg_path, 'world', 'three_room_world.sdf')
    world_path_src = '/home/rho9/chapt6/chapt6_ws/src/fishbot_description/world/three_room_world.sdf'
    world_path = world_path_install if os.path.exists(world_path_install) else world_path_src
    
    urdf_result = subprocess.run(['xacro', xacro_path], capture_output=True, text=True)
    robot_description = urdf_result.stdout
    
    print(f"Robot description length: {len(robot_description)}")
    print(f"World file: {world_path}")
    
    # 去掉-s参数，启动GUI界面
    gazebo = ExecuteProcess(
        cmd=['gz', 'sim', '-r', world_path],  # 去掉了-s
        output='screen'
    )
    
    robot_state_publisher = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        name='robot_state_publisher',
        parameters=[{'robot_description': robot_description}],
        output='screen'
    )
    
    joint_state_publisher = Node(
        package='joint_state_publisher',
        executable='joint_state_publisher',
        name='joint_state_publisher',
        parameters=[{'use_gui': False}],
        output='screen'
    )
    
    spawn_robot = Node(
        package='ros_gz_sim',
        executable='create',
        arguments=[
            '-name', 'fishbot',
            '-topic', '/robot_description',
            '-x', '0.0',
            '-y', '0.0',
            '-z', '0.2'
        ],
        output='screen'
    )
    
    delayed_spawn = TimerAction(
        period=5.0,
        actions=[spawn_robot]
    )
    
    return LaunchDescription([
        gazebo,
        robot_state_publisher,
        joint_state_publisher,
        delayed_spawn
    ])
