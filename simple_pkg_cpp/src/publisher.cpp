#include "simple_pkg_cpp/publisher.hpp"

HelloPublisher::HelloPublisher()
: Node("hello_world"), i_(0)
    {
        auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));
        pub_ = this->create_publisher<std_msgs::msg::String>("helloworld", qos_profile);
        timer_ = this->create_wall_timer(1s, std::bind(&HelloPublisher::publish_helloeorld_msg,
        this));
    }

void HelloPublisher::publish_helloeorld_msg()
{
    auto msg = std_msgs::msg::String();
    msg.data = "Hellom world" + std::to_string(i_);
    pub_->publish(msg);
    ++i_;
}