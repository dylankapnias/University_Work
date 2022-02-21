#include "../inc/TurnOff.h"

TurnOff::TurnOff(RemoteControlVehicle* v) : Command(v) {}

TurnOff::~TurnOff() {}

void TurnOff::execute() {
    getReceiver()->off();
}

void TurnOff::undo() {
    getReceiver()->on();
}