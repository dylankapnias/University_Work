#include "../inc/Fly.h"

Fly::Fly(RemoteControlVehicle* v) : Command(v) {}

Fly::~Fly() {}

void Fly::execute() {
    getReceiver()->changeFlight();
}

void Fly::undo() {
    //getReceiver()->off();
}