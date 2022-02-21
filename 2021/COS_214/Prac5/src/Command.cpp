#include "../inc/Command.h"

Command::Command(RemoteControlVehicle* v) : receiver(v) {}

Command::~Command() {}

RemoteControlVehicle* Command::getReceiver() {
    return receiver;
}