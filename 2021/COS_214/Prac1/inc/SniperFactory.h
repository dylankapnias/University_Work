#ifndef SNIPERFACTORY_H
#define SNIPERFACTORY_H

#include "SoldierFactory.h"
#include "Sniper.h"

using namespace std;

class SniperFactory : public SoldierFactory
{
    public:
        SniperFactory();
        virtual ~SniperFactory();
        
        virtual Soldier* createSoldier(string inName) const override;
};

#endif