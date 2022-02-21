#ifndef MEDIC_H
#define MEDIC_H

#include "Soldier.h"

using namespace std;

class Medic : public Soldier
{
    private:
    public:
        Medic(string name);
        virtual ~Medic();

        bool hitZombie(Zombie * z);
        bool getHit(Zombie * z);
        void celebrate();
        void die();
};

#endif