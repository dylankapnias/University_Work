#include "../inc/SniperFactory.h"
#include <iostream>

SniperFactory::SniperFactory()
{
    //cout << "Created Sniper Factory" << endl;
}

SniperFactory::~SniperFactory()
{
    //cout << "Destroyed Sniper Factory" << endl;
}      

Soldier* SniperFactory::createSoldier(string inName) const
{
    return new Sniper(inName);
}