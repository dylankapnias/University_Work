#include "../inc/MSC.h"

MSC::MSC(std::string n) : ALARM_STATES({"critical", "major", "minor", "clear"}), name(n) {}

MSC::~MSC() {}

void MSC::setAlarm(std::string s) {
    if (ALARM_STATES.count(s) != 1)
        throw std::invalid_argument("s must be in the set {\"critical\", \"major\", \"minor\", \"clear\"}.");

    alarmState = s;
}

std::string MSC::getName() {
    return name;
}

void MSC::setName(std::string n) {
    name = n;
}

std::string MSC::getAlarm() {
    return alarmState;
}
