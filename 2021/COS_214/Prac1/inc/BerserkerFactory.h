#ifndef BERSERKERFACTORY_H
#define BERSERKERFACTORY_H

#include "SoldierFactory.h"
#include "Berserker.h"

using namespace std;

class BerserkerFactory : public SoldierFactory
{
    public:
        BerserkerFactory();
        virtual ~BerserkerFactory();
        
        virtual Soldier* createSoldier(string inName) const override;
};

#endif