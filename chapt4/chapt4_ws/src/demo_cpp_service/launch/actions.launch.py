import launch
import launch_ros
from ament_index_python import get_package_share_directory
import os

def generate_launch_description():
    action_declare_start_rqt = launch.actions.DeclareLaunchArgument('start_rqt',default_value = "False")
    startup_rqt = launch.substitutions.LaunchConfiguration("startup_rqt", default = "False")

    #启动其他launch
    multisim_launch_path = os.path.join(
        get_package_share_directory('turtlesim'),
        'launch',
        'multisim.launch.py'
    )
    action_include_path = launch.actions.IncludeLaunchDescription(
        launch.launch_description_sources.PythonLaunchDescriptionSource(
            multisim_launch_path
        )
    )

    #打印数据
    action_log_info = launch.actions.LogInfo(msg=str(multisim_launch_path))

    #执行一个命令行
    action_topic_list = launch.actions.ExecuteProcess(
        condition=launch.conditions.IfCondition(startup_rqt),
        cmd=['rqt']
    )
    
    #组织动作成组
    action_group = launch.actions.GroupAction([
        #定时器
        launch.actions.TimerAction(period=2.0,actions=[action_include_path]),
        launch.actions.TimerAction(period=2.0,actions=[action_topic_list]),
    ])
    return launch.LaunchDescription([
        action_declare_start_rqt
        action_log_info,
        action_group,
    ])
