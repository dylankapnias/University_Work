#include "../inc/Engineer.h"

Engineer::Engineer(std::string n) : name(n), nextEngineer(NULL) {}

Engineer::Engineer(std::string n, NMS* nms) : name(n), nextEngineer(NULL), manage(nms) {}

Engineer::~Engineer() {}

std::string Engineer::getName() {
    return name;
}

std::string Engineer::getStatus() {
    return status;
}

void Engineer::setStatus(std::string s) {
    status = s;
}

Engineer* Engineer::getNext() {
    return nextEngineer;
}

void Engineer::setNext(Engineer* e) {
    nextEngineer = e;
}