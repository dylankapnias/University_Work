#include "../inc/BerserkerFactory.h"
#include <iostream>

BerserkerFactory::BerserkerFactory()
{
    //cout << "Created Beserker Factory" << endl;
}
    
BerserkerFactory::~BerserkerFactory()
{
    //cout << "Destroyed Beserker Factory" << endl;
}
        
Soldier* BerserkerFactory::createSoldier(string inName) const
{
    return new Berserker(inName);
}