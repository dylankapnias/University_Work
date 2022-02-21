#include "../inc/FlagObserver.h"

FlagObserver::FlagObserver(Track* t) : raceTrack(t), waving(false) {}

FlagObserver::~FlagObserver() {}

void FlagObserver::update() {
    if (raceTrack->hasCrash())
        waving = true;
    else
        waving = false;
}

void FlagObserver::print() {
    std::string out = (waving) ? "Is waving flag" : "Is not waving flag";
    std::cout << out << std::endl;
}