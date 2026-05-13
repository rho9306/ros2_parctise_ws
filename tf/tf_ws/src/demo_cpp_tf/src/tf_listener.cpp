#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/transform_stamped.hpp> //消息接口
#include <tf2/LinearMath/Quaternion.h>             //提供tf2：quaternion类
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp> //消息类型转换函数
#include <tf2_ros/transform_listener.h>         //静态坐标广播器类
#include <tf2_ros/buffer.h>
#include <tf2/utils.h>
#include <chrono>
using namespace std::chrono_literals;

class TFListener : public rclcpp::Node
{
private:
    std::shared_ptr<tf2_ros::TransformListener> listener_;
    rclcpp::TimerBase::SharedPtr timer_;
    std::shared_ptr<tf2_ros::Buffer> buffer_;

public:
    TFListener() : Node("tf_listener")
    {
        buffer_ = std::make_shared<tf2_ros::Buffer>(this->get_clock());
        this->listener_ = std::make_shared<tf2_ros::TransformListener>(*buffer_,this);
        timer_ = this->create_wall_timer(1s, std::bind(&TFListener::get_transform,this));
    }

    void get_transform()
    {
        try
        {
            const auto transform = buffer_->lookupTransform("base_link","target_point",this->get_clock()->now()
            ,rclcpp::Duration::from_seconds(1.0f));
            auto translation = transform.transform.translation;
            auto rotation = transform.transform.rotation;
            double y,p,r;
            tf2::getEulerYPR(rotation,y,p,r);
            RCLCPP_INFO(get_logger(),"translation:%f,%f,%f",translation.x,translation.y,translation.z);
            RCLCPP_INFO(get_logger(),"rotation:%f,%f,%f",y,p,r);
        }
        catch(const std::exception& e)
        {
            RCLCPP_WARN(get_logger(),"%s",e.what());
        }
        
    }
};
int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<TFListener>();
    rclcpp::spin(node);
    rclcpp::shutdown();
}
