#ifndef CHELSEAFACTORY_H
#define CHELSEAFACTORY_H

#include "MerchandiseFactory.h"
#include "ChelseaSoccerBall.h"
#include "ChelseaShirt.h"

using namespace std;

class ChelseaFactory : public MerchandiseFactory {
    public:
        ChelseaFactory();
        ~ChelseaFactory();

        virtual SoccerBall* createSoccerBall(bool) const override;
        virtual Shirt* createShirt(string) const override;
};

#endif