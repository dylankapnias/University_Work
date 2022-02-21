#include "../inc/Barrier.h"

Barrier::Barrier() : Decorator() {}

Barrier::~Barrier() {}

void Barrier::print() const {
    Decorator::print();
    std::cout << "Barriers";
}