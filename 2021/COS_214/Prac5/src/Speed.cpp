#include "../inc/Speed.h"

Speed::Speed(RemoteControlVehicle* v) : Command(v) {}

Speed::~Speed() {}

void Speed::execute() {
    getReceiver()->changeSpeed();
}

void Speed::undo() {
    //getReceiver()->off();
}