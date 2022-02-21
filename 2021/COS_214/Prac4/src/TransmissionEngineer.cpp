#include "../inc/TransmissionEngineer.h"

TransmissionEngineer::TransmissionEngineer() : Engineer::Engineer("Transmission Engineer"), _networkElement(NULL) {}

TransmissionEngineer::TransmissionEngineer(FaultsNMS* nms) : Engineer::Engineer("CSCore Engineer", nms), _networkElement(NULL), manage(nms) {}

TransmissionEngineer::~TransmissionEngineer() {}

void TransmissionEngineer::update() {
    if (_networkElement != NULL)
        alarmStatus = _networkElement->getAlarm();
}

void TransmissionEngineer::obsReg(BTS* b) {
    alarmStatus = b->getAlarm();
    _networkElement = b;
}

std::string TransmissionEngineer::getStatus() {
    return status;
}

void TransmissionEngineer::setStatus(std::string s) {
    status = s;
    statusChanged();
}

void TransmissionEngineer::statusChanged() {
    manage->notify(this);
}