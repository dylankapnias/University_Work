#include "../inc/BSC.h"

BSC::BSC(std::string n) : ALARM_STATES({"critical", "major", "minor", "clear"}), name(n) {}

BSC::~BSC() {}

void BSC::setAlarm(std::string s) {
    if (ALARM_STATES.count(s) != 1)
        throw std::invalid_argument("s must be in the set {\"critical\", \"major\", \"minor\", \"clear\"}.");

    alarmState = s;
}

std::string BSC::getName() {
    return name;
}

void BSC::setName(std::string n) {
    name = n;
}

std::string BSC::getAlarm() {
    return alarmState;
}
