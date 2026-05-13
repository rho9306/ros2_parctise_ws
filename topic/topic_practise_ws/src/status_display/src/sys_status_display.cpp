#include <QApplication>
#include <QLabel>
#include <QString>
#include <rclcpp/rclcpp.hpp>
#include <status_interfaces/msg/system_status.hpp>
#include <thread>
using namespace std;
using SystemStatus = status_interfaces::msg::SystemStatus;
class SysStatusDisplay : public rclcpp::Node
{
private:
    rclcpp::Subscription<SystemStatus>::SharedPtr subscriber_;
    QLabel* label_;
public:
    SysStatusDisplay():Node("sys_status_display")
    {
        subscriber_ = this->create_subscription<SystemStatus>("sys_status",10,[&](const SystemStatus::SharedPtr msg)->void
        {
            label_->setText(get_qstr_from_msg(msg));
        });
        label_ = new QLabel(get_qstr_from_msg(std::make_shared<SystemStatus>()));
        label_->show();
    };
    QString get_qstr_from_msg(const SystemStatus::SharedPtr msg){stringstream show_str;
        show_str <<"============提供状态可视化工具============" <<endl
                 <<"数据时间\t"<< msg->stamp.sec << endl
                 <<"主机名字\t"<< msg->host_name << endl
                 <<"cpu使用率\t"<< msg->cpu_percent << endl
                 <<"内存使用率\t"<< msg->memory_percent << endl
                 <<"内存大小\t"<< msg->memory_total << endl
                 <<"剩余内存\t"<< msg->memory_available << endl
                 <<"网络发送量\t"<< msg->net_cent << endl
                 <<"网络接受量\t"<< msg->net_recv << endl
                 << "=========================================";
        return QString::fromStdString(show_str.str());
    }
};
int main(int argc,char* argv[])
{
    rclcpp::init(argc, argv);
    QApplication app(argc,argv);
    auto node = std::make_shared<SysStatusDisplay>();
    thread spin_thread([&]()->void{
        rclcpp::spin(node);
    });
    spin_thread.detach();
    app.exec();
    return 0;
}