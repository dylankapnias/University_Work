#include "../inc/Sniper.h"
#include <iostream>

Sniper::Sniper(string name)
{
    this->setName(name);
    this->setDamage(5);
    this->setHp(6);
    this->setPWeapon(".308 Rifle");
    cout << "Sniper created." << endl;
}

Sniper::~Sniper()
{
    //cout << "Sniper destroyed." << endl;
}

bool Sniper::hitZombie(Zombie * z)
{
    cout << "Sniper " << this->getName() << " fires a " << this->getPWeapon() << " at the zombie." << endl;

    if (z->takeDamage(this->getDamage()) <= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Sniper::getHit(Zombie * z)
{
    int dmgTaken = z->getDamage();
    cout << this->getName() << " swears in 13 different languages as he takes " << dmgTaken << " damage." << endl;
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
        
void Sniper::celebrate()
{
    cout << this->getName() << " exclaims \"Headshot!\"" << endl;
}

void Sniper::die()
{
    cout << this->getName() << " lead a good life. He will be missed." << endl;
}