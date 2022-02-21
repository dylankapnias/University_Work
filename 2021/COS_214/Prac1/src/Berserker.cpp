#include "../inc/Berserker.h"
#include <iostream>

Berserker::Berserker(string name)
{
    this->setName(name);
    this->setDamage(4);
    this->setHp(10);
    this->setPWeapon("Big Chainsaw");
    cout << "Berserker created." << endl;
}

Berserker::~Berserker()
{
    //cout << "Berserker destroyed." << endl;
}

bool Berserker::hitZombie(Zombie * z)
{
    cout << "Berserker " << this->getName() << " swings a " << this->getPWeapon() << " at the zombie's head." << endl;

    if (z->takeDamage(this->getDamage()) <= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Berserker::getHit(Zombie * z)
{
    int dmgTaken = z->getDamage();
    cout << this->getName() << " pretends not to notice the " << dmgTaken << " damage he takes." << endl;
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
        
void Berserker::celebrate()
{
    cout << this->getName() << " slices the zombie in half!" << endl;
}

void Berserker::die()
{
    cout << "Nobody really liked " << this->getName() << "'s company, anyway" << endl;
}