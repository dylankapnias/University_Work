#ifndef ENGINEER_H
#define ENGINEER_H

#include "Soldier.h"

using namespace std;

class Engineer : public Soldier
{
    private:
    public:
        Engineer(string name);
        virtual ~Engineer();

        bool hitZombie(Zombie * z);
        bool getHit(Zombie * z);
        void celebrate();
        void die();
};

#endif