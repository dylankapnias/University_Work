#ifndef LIVERPOOLFACTORY_H
#define LIVERPOOLFACTORY_H

#include "MerchandiseFactory.h"
#include "LiverpoolSoccerBall.h"
#include "LiverpoolShirt.h"

using namespace std;

class LiverpoolFactory : public MerchandiseFactory {
    public:
        LiverpoolFactory();
        ~LiverpoolFactory();

        virtual SoccerBall* createSoccerBall(bool) const override;
        virtual Shirt* createShirt(string) const override;
};

#endif