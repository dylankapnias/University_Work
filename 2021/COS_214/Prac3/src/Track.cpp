#include "../inc/Track.h"

Track::Track() : Section(), sections(), crash(false) {}

Track::~Track() {}

void Track::add(Section* s) {
    sections.push_back(s);
}

void Track::remove() {
    delete sections.back();
    sections.pop_back();
}

void Track::print() const {
    std::cout << "Section\t\tAdded decorations" << std::endl;
    for (auto & el : sections) {
        el->print();
        std::cout << std::endl;
    }
}

bool Track::hasCrash() {
    return crash;
}

void Track::setCrash(bool b) {
    crash = b;
}