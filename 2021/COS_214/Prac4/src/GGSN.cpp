#include "../inc/GGSN.h"

GGSN::GGSN(std::string n) : ALARM_STATES({"critical", "major", "minor", "clear"}), name(n) {}

GGSN::~GGSN() {}

void GGSN::setAlarm(std::string s) {
    if (ALARM_STATES.count(s) != 1)
        throw std::invalid_argument("s must be in the set {\"critical\", \"major\", \"minor\", \"clear\"}.");

    alarmState = s;
}

std::string GGSN::getName() {
    return name;
}

void GGSN::setName(std::string n) {
    name = n;
}

std::string GGSN::getAlarm() {
    return alarmState;
}
