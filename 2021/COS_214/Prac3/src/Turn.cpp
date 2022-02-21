#include "../inc/Turn.h"

Turn::Turn(int i) : deg(i) {}

Turn::~Turn() {}

void Turn::print() const {
    std::cout << std::string((deg == 0) ? "Right Turn\t" : "Left Turn\t");
}