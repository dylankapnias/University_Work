#include "../inc/Decorator.h"

Decorator::Decorator() : section(nullptr) {}

Decorator::~Decorator() { delete section;}

void Decorator::add(Section* s) {
    if (section == nullptr)
        section = s;
    else
        section->add(s);
}

void Decorator::remove() {
    if (section != nullptr) 
        section = nullptr;
}

void Decorator::print() const {
    section->print();
}