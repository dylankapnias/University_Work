#include "../inc/MoveBackward.h"

MoveBackward::MoveBackward(RemoteControlVehicle* v) : Command(v) {}

MoveBackward::~MoveBackward() {}

void MoveBackward::execute() {
    getReceiver()->backward();
}

void MoveBackward::undo() {
    getReceiver()->foward();
}