#include "../inc/EngineerFactory.h"
#include <iostream>

EngineerFactory::EngineerFactory()
{
    //cout << "Created Engineer Factory" << endl;
}

EngineerFactory::~EngineerFactory()
{
    //cout << "Destroyed Engineer Factory" << endl;
}   

Soldier* EngineerFactory::createSoldier(string inName) const
{
    return new Engineer(inName);
}