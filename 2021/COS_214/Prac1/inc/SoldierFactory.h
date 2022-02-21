#ifndef SOLDIERFACTORY_H
#define SOLDIERFACTORY_H

#include "Soldier.h"

using namespace std;

class SoldierFactory
{
    public:
        SoldierFactory();
        virtual ~SoldierFactory();

        virtual Soldier* createSoldier(std::string inName) const = 0;
};

#endif