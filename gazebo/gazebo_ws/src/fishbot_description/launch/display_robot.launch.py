import launch
import launch_ros
from ament_index_python.packages import get_package_share_directory
import os
import subprocess

def generate_launch_description():
    pkg_path = get_package_share_directory('fishbot_description')
    xacro_path = os.path.join(pkg_path, 'urdf', 'fishbot', 'fishbot.urdf.xacro')
    
    # 使用subprocess实时调用xacro转换
    result = subprocess.run(['xacro', xacro_path], capture_output=True, text=True)
    robot_description = result.stdout
    
    print(f"Robot description length: {len(robot_description)}")
    print(f"Links in robot: {[line.split('name=\"')[1].split('\"')[0] for line in robot_description.split('\\n') if '<link name=\"' in line]}")
    
    return launch.LaunchDescription([
        launch_ros.actions.Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            name='robot_state_publisher',
            output='screen',
            parameters=[{'robot_description': robot_description}]
        ),
        launch_ros.actions.Node(
            package='joint_state_publisher_gui',
            executable='joint_state_publisher_gui',
            name='joint_state_publisher_gui',
            output='screen'
        ),
        launch_ros.actions.Node(
            package='rviz2',
            executable='rviz2',
            name='rviz2',
            output='screen'
        )
    ])
