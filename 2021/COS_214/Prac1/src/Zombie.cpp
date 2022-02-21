#include "../inc/Zombie.h"
#include <iostream>

Zombie::Zombie(const char* att, int dam)
	: attackType(att), damage(dam)
{
	hp = 5;

	//cout << "Zombie " << attackType << " Created." << endl;
}

Zombie::~Zombie()
{
	//cout << "Zombie " << attackType << " Destroyed" << endl;
}

int Zombie::takeDamage(int amount)
{
	cout << "Zombie took " << amount << " damage." << endl;
	hp -= amount;
	return hp;
}

// Getters
int Zombie::getDamage()
{
	cout << "Zombie used " << attackType << "." << endl;
	return damage;
}

string Zombie::getName()
{
	return attackType;
}

/*void Zombie::setName(string inS)
{
	attackType = inS;
}*/

// Debugging print
void Zombie::print()
{
    cout << "My values are:- Attack Type->" << attackType << " HP->" << hp << " Damage->" << damage << endl;
}


int Zombie::getHp()
{
	return hp;
}

Zombie* Zombie::clone()
{
	return new Zombie(this->attackType.c_str(), this->damage);
}

// Memento stuff
ZMemento* Zombie::createMemento()
{
	return new ZMemento(hp, damage, attackType);
}
	
void Zombie::reinstateMemento(ZMemento *mem)
{
	ZState* s = mem->_state;

	hp = s->getFirst();
	damage = s->getSecond();
	attackType = s->getThird();
}