#include "../inc/ChelseaFactory.h"
#include <iostream>

ChelseaFactory::ChelseaFactory() {}
ChelseaFactory::~ChelseaFactory() {}

SoccerBall* ChelseaFactory::createSoccerBall(bool inf) const {
    SoccerBall* temp = new ChelseaSoccerBall(inf);
    cout << temp->getDescription() << endl;
    return temp;
}

Shirt* ChelseaFactory::createShirt(string s) const {
    Shirt* temp = new ChelseaShirt(s);
    cout << temp->getDescription() << endl;
    return temp;
}