#include "../inc/CSCoreEngineer.h"

CSCoreEngineer::CSCoreEngineer() : Engineer::Engineer("CSCore Engineer"), _networkElement(NULL) {}

CSCoreEngineer::CSCoreEngineer(FaultsNMS* nms) : Engineer::Engineer("CSCore Engineer", nms), _networkElement(NULL), manage(nms) {}

CSCoreEngineer::~CSCoreEngineer() {}

void CSCoreEngineer::update() {
    if (_networkElement != NULL)
        alarmStatus = _networkElement->getAlarm();
}

void CSCoreEngineer::obsReg(MSC* b) {
    alarmStatus = b->getAlarm();
    _networkElement = b;
}

std::string CSCoreEngineer::getStatus() {
    return status;
}

void CSCoreEngineer::setStatus(std::string s) {
    status = s;
    statusChanged();
}

void CSCoreEngineer::statusChanged() {
    manage->notify(this);
}