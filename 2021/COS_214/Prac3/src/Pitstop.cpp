#include "../inc/Pitstop.h"

Pitstop::Pitstop() : Decorator() {}

Pitstop::~Pitstop() {}

void Pitstop::print() const {
    Decorator::print();
    std::cout << "Pit stop";
}