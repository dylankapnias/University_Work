#ifndef BERSERKER_H
#define BERSERKER_H

#include "Soldier.h"

using namespace std;

class Berserker : public Soldier
{
    public:
        Berserker(string name);
        virtual ~Berserker();

        bool hitZombie(Zombie * z);
        bool getHit(Zombie * z);
        void celebrate();
        void die();
};

#endif