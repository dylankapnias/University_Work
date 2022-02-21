#include "../inc/PowerEngineer.h"

PowerEngineer::PowerEngineer() : Engineer::Engineer("Power Engineer"), _networkElement(NULL) {}

PowerEngineer::PowerEngineer(FaultsNMS* nms) : Engineer::Engineer("CSCore Engineer", nms), _networkElement(NULL), manage(nms) {}

PowerEngineer::~PowerEngineer() {}

void PowerEngineer::update () {
    if (_networkElement != NULL)
        alarmStatus = _networkElement->getAlarm();
}

void PowerEngineer::obsReg(BTS* b) {
    alarmStatus = b->getAlarm();
    _networkElement = b;
}

std::string PowerEngineer::getStatus() {
    return status;
}

void PowerEngineer::setStatus(std::string s) {
    status = s;
    statusChanged();
}

void PowerEngineer::statusChanged() {
    manage->notify(this);
}