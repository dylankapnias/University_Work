#include "../inc/Section.h"

Section::Section() {}

Section::~Section() {}

void Section::add(Section* s) {}

void Section::remove() {}

void Section::attach(Observer* o) {
    observerList.push_back(o);
}

void Section::detach(Observer* o) {
    bool done = false;
    
    for (std::vector<Observer*>::iterator it = observerList.begin(); it != observerList.end() && !done; it++) {
        if (*it == o) {
            done = true;
            observerList.erase(it);
        }
    }
}

void Section::notify() {
    for (auto el : observerList) {
        el->update();
    }
}   