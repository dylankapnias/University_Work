#ifndef SNIPER_H
#define SNIPER_H

#include "Soldier.h"

using namespace std;

class Sniper : public Soldier
{
    public:
        Sniper(string name);
        virtual ~Sniper();

        bool hitZombie(Zombie * z);
        bool getHit(Zombie * z);
        void celebrate();
        void die();
};

#endif