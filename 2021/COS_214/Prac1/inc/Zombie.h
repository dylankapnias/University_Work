#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "Zombie_Memento.h"
#include <string>

using namespace std;

class Zombie
{
private:
	int hp;
	string attackType;
	int damage;

public:
	Zombie(const char*,int);
	~Zombie();
		
	// reduces the zombie's hp and returns the new value of hp
	int takeDamage(int);
	
	// returns the zombie's damage
	int getDamage();

	// returns the zombie's name
	string getName();

	// Debugging print
	void print();

	// Trial setter
	//void setName(string inS);

	// Hp getter
	int getHp();

	// Cloner
	Zombie* clone();

	// Memento stuff
	ZMemento *createMemento();
	void reinstateMemento(ZMemento *mem);
};

#endif