#include "../inc/LiverpoolFactory.h"
#include <iostream>

LiverpoolFactory::LiverpoolFactory() {}
LiverpoolFactory::~LiverpoolFactory() {}

SoccerBall* LiverpoolFactory::createSoccerBall(bool inf) const {
    SoccerBall* temp = new LiverpoolSoccerBall(inf);
    cout << temp->getDescription() << endl;
    return temp;
}

Shirt* LiverpoolFactory::createShirt(string s) const {
    Shirt* temp = new LiverpoolShirt(s);
    cout << temp->getDescription() << endl;
    return temp;
}