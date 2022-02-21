#include "../inc/RemoteControlRocket.h"

RemoteControlRocket::RemoteControlRocket() {}

RemoteControlRocket::~RemoteControlRocket() {}

void RemoteControlRocket::takeOff() {
    std::cout << "The RC rocket blasts off its take-off platform." << std::endl;
}

void RemoteControlRocket::stopLaunch() {
    std::cout << "The RC rocket deploys its parachute and floats down to the ground." << std::endl;
}

void RemoteControlRocket::increaseThrottle() {
    std::cout << "The RC rocket increases its throttle and accelerates." << std::endl;
}

void RemoteControlRocket::decreaseThrottle() {
    std::cout << "The RC rocket decreases its throttle and ascends at a slower rate." << std::endl;
}