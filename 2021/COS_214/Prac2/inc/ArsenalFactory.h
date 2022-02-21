#ifndef ARSENALFACTORY_H
#define ARSENALFACTORY_H

#include "MerchandiseFactory.h"
#include "ArsenalSoccerBall.h"
#include "ArsenalShirt.h"

using namespace std;

class ArsenalFactory : public MerchandiseFactory {
    public:
        ArsenalFactory();
        ~ArsenalFactory();

        virtual SoccerBall* createSoccerBall(bool) const override;
        virtual Shirt* createShirt(string) const override;
};

#endif