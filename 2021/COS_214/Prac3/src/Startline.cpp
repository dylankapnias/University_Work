#include "../inc/Startline.h"

Startline::Startline() : Decorator() {}

Startline::~Startline() {}

void Startline::print() const {
    Decorator::print();
    std::cout << "Starting line";
}