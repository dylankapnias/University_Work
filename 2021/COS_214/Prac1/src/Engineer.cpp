#include "../inc/Engineer.h"
#include <iostream>

Engineer::Engineer(string name)
{
    this->setName(name);
    this->setDamage(3);
    this->setHp(7);
    this->setPWeapon("Wrench");
    cout << "Engineer created." << endl;
}

Engineer::~Engineer()
{
    //cout << "Engineer destroyed." << endl;
}

bool Engineer::hitZombie(Zombie * z)
{
    cout << "Engineer " << this->getName() << " bludgeons the zombie with a " << this->getPWeapon() << endl;

    if (z->takeDamage(this->getDamage()) <= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Engineer::getHit(Zombie * z)
{
    int dmgTaken = z->getDamage();
    cout << this->getName() << " hides behind the nearest rock after taking " << dmgTaken << " damage." << endl;
    this->setHp(this->getHp() - dmgTaken);   

    if (this->getHp() <= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
        
void Engineer::celebrate()
{
    cout << this->getName() << " shakes his " << this->getPWeapon() << " at the zombie's remains." << endl;
}

void Engineer::die()
{
    cout << this->getName() << " was eaten by a zombie." << endl;
}