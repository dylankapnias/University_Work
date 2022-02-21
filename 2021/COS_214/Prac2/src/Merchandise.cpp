#include "../inc/Merchandise.h"
#include <iostream>

long Merchandise::ID = 0;

Merchandise::Merchandise(string c, string t, double p) : club(c), type(t), price(p), currentID(++ID) {}

Merchandise::~Merchandise() {
    //cout << "Item #" << currentID << " is being destroyed" << endl;
}

string Merchandise::getDescription() {
    return "Item #" + to_string(currentID) + ": " + club + " " + type + ", Price: " + to_string(price);
}

string Merchandise::getClub() {
    return club;
}

double Merchandise::getPrice() {
    return price;
}