#include "../inc/BTS.h"

BTS::BTS(std::string n) : ALARM_STATES({"critical", "major", "minor", "clear"}), name(n) {}

BTS::~BTS() {}

void BTS::setAlarm(std::string s) {
    if (ALARM_STATES.count(s) != 1)
        throw std::invalid_argument("s must be in the set {\"critical\", \"major\", \"minor\", \"clear\"}.");

    alarmState = s;
}

std::string BTS::getName() {
    return name;
}

void BTS::setName(std::string n) {
    name = n;
}

std::string BTS::getAlarm() {
    return alarmState;
}