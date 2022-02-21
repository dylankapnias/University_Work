#include "../inc/Soldier.h"
#include <iostream>

Soldier::Soldier()
{
    //cout << "Soldier no param created." << endl;
}

Soldier::Soldier(string n, int h, int d) : name(n), hp(h), damage(d)
{
    //cout << "Soldier with param created." << endl;
}

Soldier::~Soldier()
{
    //cout << "Soldier destroyed" << endl;
}

void Soldier::attack(Zombie* z)
{
    while ((hp > 0) && (z->getHp() > 0))
    {
        //cout << "Start: ";
        //this->print();

        if (this->hitZombie(z))
        {
            this->celebrate();
        } 
        else if (this->getHit(z))
        {
            this->die();
        }

        //cout << "End: ";
        //this->print();
    }
}

// Debugging print
void Soldier::print()
{
    cout << "My values are:- Name->" << name << " HP->" << hp << " Damage->" << damage << " Primary->" << primaryWeapon << endl;
}

// Getters
string Soldier::getName()
{
    return name;
}

string Soldier::getPWeapon()
{
    return primaryWeapon;
}

string Soldier::getSWeapon()
{
    return secondaryWeapon;
}

int Soldier::getDamage()
{
    return damage;
}

int Soldier::getHp()
{
    return hp;
}
// Setters
void Soldier::setName(string na)
{
    name = na;
}

void Soldier::setPWeapon(string pw)
{
    primaryWeapon = pw;
}

void Soldier::setSWeapon(string sw)
{
    secondaryWeapon = sw;
}

void Soldier::setDamage(int da)
{
    damage = da;
}

void Soldier::setHp(int val)
{
    hp = val;
}

SMemento* Soldier::createMemento()
{
	return new SMemento(hp, damage, name, primaryWeapon, secondaryWeapon);
}
	
void Soldier::reinstateMemento(SMemento *mem)
{
	SState* s = mem->_state;

	hp = s->getFirst();
	damage = s->getSecond();
	name = s->getThird();
    primaryWeapon = s->getFourth();
    secondaryWeapon = s->getFifth();
}