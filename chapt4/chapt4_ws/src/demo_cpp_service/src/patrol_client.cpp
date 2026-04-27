#include <rclcpp/rclcpp.hpp>
#include <chapt4_interfaces/srv/patrol.hpp>
#include <rcl_interfaces/msg/parameter.hpp>
#include <rcl_interfaces/msg/parameter_value.hpp>
#include <rcl_interfaces/msg/parameter_type.hpp>
#include <rcl_interfaces/srv/set_parameters.hpp>
#include<ctime>
#include<chrono>

using SetP = rcl_interfaces::srv::SetParameters;
using namespace std::chrono_literals;
using Patrol = chapt4_interfaces::srv::Patrol;

class PatrolClient: public rclcpp::Node
{
private:
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Client<Patrol>::SharedPtr patrol_client_;
    rclcpp::Client<SetP>::SharedPtr param_client;

public:
    PatrolClient() : Node("turtle_controller")
    {
        srand(time(NULL));
        patrol_client_ = this->create_client<Patrol>("patrol");
        timer_ = this->create_wall_timer(10s,[&]()->void{
            //检测服务端是否上线
            while (!this->patrol_client_->wait_for_service(1s)){
                if (!rclcpp::ok())
                {
                    RCLCPP_ERROR(this->get_logger(),"waiting for the service while the rclcpp went off");
                    return;
                }
                RCLCPP_INFO(this->get_logger(),"waiting for the service...");
            }
            //构造请求对象
            auto request = std::make_shared<Patrol::Request>();
            request->target_x = rand() %12;
            request->target_y = rand() %12;
            RCLCPP_INFO(this->get_logger(),"ready to publish target...");
            //发送请求
            this->patrol_client_->async_send_request(request,[&]
                (rclcpp::Client<Patrol>::SharedFuture result_future)->void{
                    auto response = result_future.get();
                    if (response->result==Patrol::Response::SUCCESS)
                    {
                        RCLCPP_INFO(this->get_logger(),"requesting patrol point success");
                    }
                    if (response->result==Patrol::Response::FAIL)
                    {
                        RCLCPP_INFO(this->get_logger(),"requesting patrol point fail");
                    }
                });
        });
    }
    SetP::Response::SharedPtr call_set_parameter(rcl_interfaces::msg::Parameter &param)
    {
        auto param_client = this->create_client<SetP>("/turtle_controller/set_parameters");
        //检测服务端是否上线
        while (!this->param_client->wait_for_service(1s)){
            if (!rclcpp::ok())
            {
                RCLCPP_ERROR(this->get_logger(),"waiting for the service while the rclcpp went off");
                return nullptr;
            }
            RCLCPP_INFO(this->get_logger(),"waiting for the service...");
        }
        //构造请求对象
        auto request = std::make_shared<SetP::Request>();
        request->parameters.push_back(param);
        //发送请求
        auto future = param_client->async_send_request(request);
        rclcpp::spin_until_future_complete(this->get_node_base_interface(), future);
        auto response = future.get();
        return response;
    }
    void update_server_param_k(double k)
    {
        auto param = rcl_interfaces::msg::Parameter();
        param.name = "k";
        auto param_value = rcl_interfaces::msg::ParameterValue();
        auto param_type = rcl_interfaces::msg::ParameterType::PARAMETER_DOUBLE;
        param_value.double_value = k;
        param_value = param_value;
        auto response = this->call_set_parameter(param);
        if (response ==NULL)
        {
            RCLCPP_INFO(this->get_logger(),"updating parameter failed...");
            return;
        }
        for (auto &result:response->results)
        {
            if (result.successful==false)
            {
                RCLCPP_INFO(this->get_logger(),"updating parameter failed...");
            }else{
                RCLCPP_INFO(this->get_logger(),"updating parameter succeed...");
            }
            
        }
    }
};

int main(int argc, char* argv[])
{
    rclcpp::init(argc,argv);
    auto node = std::make_shared<PatrolClient>();
    node->update_server_param_k(4.0);
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
