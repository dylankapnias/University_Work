#include "../inc/SoccerBall.h"
#include <iostream>

SoccerBall::SoccerBall(string c, double p, bool inf) : Merchandise(c, "Ball", p) {
    inflated = inf;
}

SoccerBall::~SoccerBall() {}

string SoccerBall::getDescription() {
    string ret = Merchandise::getDescription() + ", Inflated: ";
    ret += (inflated) ? "True" : "False";
    return ret;
}

Merchandise* SoccerBall::clone() {
    return new SoccerBall(this->getClub(), this->getPrice(), inflated);
}