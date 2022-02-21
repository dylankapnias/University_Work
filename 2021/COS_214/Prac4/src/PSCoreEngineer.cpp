#include "../inc/PSCoreEngineer.h"

PSCoreEngineer::PSCoreEngineer() : Engineer::Engineer("PSCore Engineer"), _networkElement(NULL) {}

PSCoreEngineer::PSCoreEngineer(FaultsNMS* nms) : Engineer::Engineer("CSCore Engineer", nms), _networkElement(NULL), manage(nms) {}

PSCoreEngineer::~PSCoreEngineer() {}

void PSCoreEngineer::update() {
    if (_networkElement != NULL)
        alarmStatus = _networkElement->getAlarm();
}

void PSCoreEngineer::obsReg(GGSN* b) {
    alarmStatus = b->getAlarm();
    _networkElement = b;
}

std::string PSCoreEngineer::getStatus() {
    return status;
}

void PSCoreEngineer::setStatus(std::string s) {
    status = s;
    statusChanged();
}

void PSCoreEngineer::statusChanged() {
    manage->notify(this);
}