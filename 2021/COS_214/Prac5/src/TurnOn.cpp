#include "../inc/TurnOn.h"

TurnOn::TurnOn(RemoteControlVehicle* v) : Command(v) {}

TurnOn::~TurnOn() {}

void TurnOn::execute() {
    getReceiver()->on();
}

void TurnOn::undo() {
    getReceiver()->off();
}