#include "../inc/MoveFoward.h"

MoveFoward::MoveFoward(RemoteControlVehicle* v) : Command(v) {}

MoveFoward::~MoveFoward() {}

void MoveFoward::execute() {
    getReceiver()->foward();
}

void MoveFoward::undo() {
    getReceiver()->backward();
}