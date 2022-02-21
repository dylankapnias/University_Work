#include "../inc/ArsenalFactory.h"
#include <iostream>

ArsenalFactory::ArsenalFactory() {}
ArsenalFactory::~ArsenalFactory() {}

SoccerBall* ArsenalFactory::createSoccerBall(bool inf) const {
    SoccerBall* temp = new ArsenalSoccerBall(inf);
    cout << temp->getDescription() << endl;
    return temp;
}

Shirt* ArsenalFactory::createShirt(string s) const {
    Shirt* temp = new ArsenalShirt(s);
    cout << temp->getDescription() << endl;
    return temp;
}