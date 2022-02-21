#include "../inc/RemoteControlCar.h"

RemoteControlCar::RemoteControlCar() : next(NULL) {}

RemoteControlCar::~RemoteControlCar() {}

void RemoteControlCar::setNext(RemoteControlVehicle* v) {
    next = v;
}

void RemoteControlCar::changeSpeed() {
    if (getState()) {
        std::cout << "RC car changes speed." << std::endl;
    } else {
        std::cout << "The car is not currently turned on." << std::endl;
    }
}

void RemoteControlCar::on() {
    if (!getState()) {
        setState(true);
        std::cout << "RC car is turned on." << std::endl;
    } else {
        std::cout << "The car is already on." << std::endl;
    }
}

void RemoteControlCar::off() {
    if (getState()) {
        setState(false);
        std::cout << "RC car is turned off." << std::endl;
    } else {
        std::cout << "The car is already off." << std::endl;
    }
}

void RemoteControlCar::foward() {
    if (getState()) {
        std::cout << "RC car drives forward quickly." << std::endl;
    } else {
        std::cout << "The car is not currently turned on." << std::endl;
    }
}

void RemoteControlCar::backward() {
    if (getState()) {
        std::cout << "RC car reverses backward carefully." << std::endl;
    } else {
        std::cout << "The car is not currently turned on." << std::endl;
    }
}

void RemoteControlCar::handleRequest(std::string s) {
    if (s == "speed") {
        Speed* s = new Speed(this);
        s->execute();
        delete s;
    } else {
        if (next != NULL)
            next->handleRequest(s);
        else
            std::cout << "End of chain, request not completed." << std::endl;
    }
}
