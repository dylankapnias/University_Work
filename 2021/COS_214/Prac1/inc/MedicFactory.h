#ifndef MEDICFACTORY_H
#define MEDICFACTORY_H

#include "SoldierFactory.h"
#include "Medic.h"

using namespace std;

class MedicFactory : public SoldierFactory
{
    public:
        MedicFactory();
        virtual ~MedicFactory();
        
        virtual Soldier* createSoldier(string inName) const override;
};

#endif