#include "../inc/GravelTrap.h"

GravelTrap::GravelTrap() : Decorator() {}

GravelTrap::~GravelTrap() {}

void GravelTrap::print() const {
    Decorator::print();
    std::cout << "GravelTraps";
}