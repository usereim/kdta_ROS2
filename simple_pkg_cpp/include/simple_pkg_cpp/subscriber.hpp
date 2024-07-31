#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include <iostream>
#include <chrono>
#include "std_msgs/msg/string.hpp"
#include "rclcpp/rclcpp.hpp"

using namespace std::chrono_literals;
using namespace std;

class HelloSubscriber : public rclcpp::Node {
private:
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub_;
    void sub_helloworld_msg(const std_msgs::msg::String::SharedPtr msg);

public:
    HelloSubscriber();

};

#endif