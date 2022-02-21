#include "../inc/RemoteControlVehicle.h"

RemoteControlVehicle::RemoteControlVehicle() : onState(false) {}

RemoteControlVehicle::~RemoteControlVehicle() {}

bool RemoteControlVehicle::getState() {
    return onState;
}

void RemoteControlVehicle::setState(bool b) {
    onState = b;
}

void RemoteControlVehicle::handleRequest(std::string s) {
    
}

void RemoteControlVehicle::changeSpeed() {

}

void RemoteControlVehicle::changeFlight() {

}
