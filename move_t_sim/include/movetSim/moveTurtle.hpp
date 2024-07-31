#ifndef MOVETURTLE_H
#define MOVETURTLE_H

#include <chrono>
#include "geometry_msgs/msg/twist.hpp"
#include "rclcpp/rclcpp.hpp"

using namespace std::chrono_literals;
using namespace std;

class MoveTurtleSim : public rclcpp::Node {
private:
    int i_;
    float execelaration;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr pub_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr pub2_;
    rclcpp::TimerBase::SharedPtr timer_;
    void publish_turtlesim_msg();

public:
    MoveTurtleSim();

};

#endif