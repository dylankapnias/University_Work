#include "../inc/RemoteControlPlane.h"

RemoteControlPlane::RemoteControlPlane() {}

RemoteControlPlane::~RemoteControlPlane() {}

void RemoteControlPlane::changeFlight() {
    if (getState()) {
        std::cout << "RC plane flys a bit faster." << std::endl;
    } else {
        std::cout << "The plane is not currently turned on." << std::endl;
    }
}

void RemoteControlPlane::on() {
    if (!getState()) {
        setState(true);
        std::cout << "RC plane is turned on." << std::endl;
    } else {
        std::cout << "The plane is already on." << std::endl;
    }
}

void RemoteControlPlane::off() {
    if (getState()) {
        setState(false);
        std::cout << "RC plane is turned off." << std::endl;
    } else {
        std::cout << "The plane is already off." << std::endl;
    }
}

void RemoteControlPlane::foward() {
    if (getState()) {
        std::cout << "RC plane pulls up into a vertical climb." << std::endl;
    } else {
        std::cout << "The plane is not currently turned on." << std::endl;
    }
}

void RemoteControlPlane::backward() {
    if (getState()) {
        std::cout << "RC plane points its nose down into a dive." << std::endl;
    } else {
        std::cout << "The plane is not currently turned on." << std::endl;
    }
}

void RemoteControlPlane::handleRequest(std::string s) {
    if (s == "fly") {
        Fly* f = new Fly(this);
        f->execute();
        delete f;
    } else {
        if (next != NULL)
            next->handleRequest(s);
        else
            std::cout << "End of chain, request not completed." << std::endl;
    }
}