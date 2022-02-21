#include "../inc/Shirt.h"
#include <iostream>

Shirt::Shirt(string c, double p, string s) : Merchandise(c, "Shirt", p) {
    size = s;
}

Shirt::~Shirt() {}

string Shirt::getDescription() {
    string ret = Merchandise::getDescription() + ", Size: " + size;
    return ret;
}

Merchandise* Shirt::clone() {
    return new Shirt(this->getClub(), this->getPrice(), size);
}