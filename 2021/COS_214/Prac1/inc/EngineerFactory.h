#ifndef ENGINEERFACTORY_H
#define ENGINEERFACTORY_H

#include "SoldierFactory.h"
#include "Engineer.h"

using namespace std;

class EngineerFactory : public SoldierFactory
{
    public:
        EngineerFactory();
        virtual ~EngineerFactory();
        
        virtual Soldier* createSoldier(string inName) const override;
};

#endif