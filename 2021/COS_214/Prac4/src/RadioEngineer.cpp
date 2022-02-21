#include "../inc/RadioEngineer.h"

RadioEngineer::RadioEngineer() : Engineer("Radio Engineer"), _networkElement_BTS(NULL), _networkElement_BSC(NULL) {}

RadioEngineer::RadioEngineer(FaultsNMS* nms) : Engineer::Engineer("CSCore Engineer", nms), _networkElement_BTS(NULL), _networkElement_BSC(NULL), manage(nms) {}

RadioEngineer::~RadioEngineer() {}

void RadioEngineer::update() {
    if (_networkElement_BTS != NULL)
        alarmStatus_BTS = _networkElement_BTS->getAlarm();

    if (_networkElement_BSC != NULL)
        alarmStatus_BSC = _networkElement_BSC->getAlarm();
}

void RadioEngineer::obsReg(BTS* b) {
    alarmStatus_BTS = b->getAlarm();
    _networkElement_BTS = b;
}

void RadioEngineer::obsReg(BSC* b) {
    alarmStatus_BSC = b->getAlarm();
    _networkElement_BSC = b;
}

std::string RadioEngineer::getStatus() {
    return status;
}

void RadioEngineer::setStatus(std::string s) {
    status = s;
    statusChanged();
}

void RadioEngineer::statusChanged() {
    //manage->notify(this);
}