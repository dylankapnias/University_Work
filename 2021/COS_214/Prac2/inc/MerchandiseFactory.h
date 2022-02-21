#ifndef MERCHANDISEFACTORY_H
#define MERCHANDISEFACTORY_H

#include "SoccerBall.h"
#include "Shirt.h"

using namespace std;

class MerchandiseFactory
{
    public:
        MerchandiseFactory();
        virtual ~MerchandiseFactory();

        virtual SoccerBall* createSoccerBall(bool) const = 0;
        virtual Shirt* createShirt(string) const = 0;
};

#endif