#include <iostream>
#include <chrono>
#include "std_msgs/msg/string.hpp"
#include "rclcpp/rclcpp.hpp"

using namespace std::chrono_literals;

class HelloPublisher : public rclcpp::Node {
private:
    int i_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub_;
    rclcpp::TimerBase::SharedPtr timer_;
    void publish_helloeorld_msg()
    {
        auto msg = std_msgs::msg::String();
        msg.data = "Hellom world" + std::to_string(i_);
        pub_->publish(msg);
        ++i_;
    }

public:
    HelloPublisher()
    : Node("hello_world"), i_(0)
    {
        auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));
        pub_ = this->create_publisher<std_msgs::msg::String>("helloworld", qos_profile);
        timer_ = this->create_wall_timer(1s, std::bind(&HelloPublisher::publish_helloeorld_msg,
        this));
    }

};

int main()
{
    rclcpp::init(0, nullptr);
    auto node = std::make_shared<HelloPublisher>();

    rclcpp::spin(node);
    rclcpp::shutdown();

    return 0;
}

