#include "../inc/RocketAdapter.h"

RocketAdapter::RocketAdapter(RemoteControlRocket* r) : adaptee(r) {}

RocketAdapter::~RocketAdapter() {}

void RocketAdapter::on() {
    if (!getState()) {
        setState(true);
        adaptee->takeOff();
    } else {
        std::cout << "The rocket has already taken off." << std::endl;
    }
}

void RocketAdapter::off() {
    if (getState()) {
        setState(false);
        adaptee->stopLaunch();
    } else {
        std::cout << "The rocket is already on the ground." << std::endl;
    }
}

void RocketAdapter::foward() {
    if (getState()) {
        adaptee->increaseThrottle();
    } else {
        std::cout << "The rocket is not currently in the air." << std::endl;
    }
}

void RocketAdapter::backward() {
    if (getState()) {
        adaptee->decreaseThrottle();
    } else {
        std::cout << "The rocket is not currently in the air." << std::endl;
    }
}