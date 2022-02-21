#include "../inc/Medic.h"
#include <iostream>

Medic::Medic(string name)
{
    this->setName(name);
    this->setDamage(2);
    this->setHp(8);
    this->setPWeapon("Syringe");
    cout << "Medic created." << endl;
}

Medic::~Medic()
{
    //cout << "Medic destroyed." << endl;
}

bool Medic::hitZombie(Zombie * z)
{
    cout << "Medic " << this->getName() << " frantically stabs at the zombie with a " << this->getPWeapon() << endl;

    if (z->takeDamage(this->getDamage()) <= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Medic::getHit(Zombie * z)
{
    int dmgTaken = z->getDamage();
    cout << this->getName() << " gives himself painkillers to numb the " << dmgTaken << " damage suffered." << endl;
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
        
void Medic::celebrate()
{
    cout << this->getName() << " sighs in relief." << endl;
}

void Medic::die()
{
    cout << "After saving so many lives, " << this->getName() << " could not save himself." << endl;
}