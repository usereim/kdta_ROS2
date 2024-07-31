#ifndef PUBLISHER_H
#define PUBLISHER_H

#include <iostream>
#include <chrono>
#include "std_msgs/msg/string.hpp"
#include "rclcpp/rclcpp.hpp"

using namespace std::chrono_literals;
using namespace std;

class HelloPublisher : public rclcpp::Node {
private:
    int i_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub_;
    rclcpp::TimerBase::SharedPtr timer_;
    void publish_helloeorld_msg();

public:
    HelloPublisher();

};

#endif