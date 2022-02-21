#include "../inc/MedicFactory.h"
#include <iostream>

MedicFactory::MedicFactory()
{
    //cout << "Created Medic Factory" << endl;
}

MedicFactory::~MedicFactory()
{
    //cout << "Destroyed Medic Factory" << endl;
}

Soldier* MedicFactory::createSoldier(string inName) const
{
    return new Medic(inName);
}