#include "../inc/Soldier.h"
#include "../inc/Zombie.h"
#include "../inc/SniperFactory.h"
#include "../inc/BerserkerFactory.h"
#include "../inc/MedicFactory.h"
#include "../inc/EngineerFactory.h"
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Finding the number of simulations
int fact(int n)
{
   	if (n == 0)
       	return 1;
   	return n * fact(n - 1);
}

// Main program
int main()
{
	
	// This main provides a nice interface for testing your completed code.

	// initialize soldier factories (creators)
	const int numFactories = 4;
	SoldierFactory* factories[numFactories];
	factories[0] = new SniperFactory();
	factories[1] = new BerserkerFactory();
	factories[2] = new MedicFactory();
	factories[3] = new EngineerFactory();
	
	short numSoldiers;
	cout << "How may soldiers in your squad? ";
	cin >> numSoldiers;
	
	Soldier** soldiers = new Soldier*[numSoldiers];
	short type;
	char name[30];
	
	for (short i = 0; i < numSoldiers; i++)
	{
		cout << "What is the name of soldier " << i+1 << "? ";
		cin >> name;
		cout << endl;
		cout << "0 - Sniper" << endl;
		cout << "1 - Berserker" << endl;
		cout << "2 - Medic" << endl;
		cout << "3 - Engineer" << endl;
		cout << "What class is soldier " << i+1 << "? ";
		cin >> type;
		
		// The following line of code is a good example of the usefulness of the Factory Method.
		// Here, we are constructing an instance of a different class depending on use input.
		soldiers[i] = factories[type]->createSoldier(name);
	}
	
	// initialize zombie prototypes
	const short numZombieTypes = 4;
	Zombie** zombiePrototypes = new Zombie*[numZombieTypes];
	zombiePrototypes[0] = new Zombie("bite",2);
	zombiePrototypes[1] = new Zombie("slash",3);
	zombiePrototypes[2] = new Zombie("spit",4);
	zombiePrototypes[3] = new Zombie("pounce",5);
	
	Zombie** zombies = new Zombie*[numSoldiers];
	
	for (short i = 0; i < numSoldiers; i++)
	{
		cout << "0 - Biting zombie" << endl;
		cout << "1 - Slashing zombie" << endl;
		cout << "2 - Spitting zombie" << endl;
		cout << "3 - Pouncing zombie" << endl;
		cout << "What type is zombie #" << i+1 << "? ";
		cin >> type;
		
		// The following line of code is a good example of the usefulness of the Prototype design.
		// Since there can be a lot of the same kind of zombie (as is zombie nature), it is natural
		// to be able to duplicate them at will!
		zombies[i] = zombiePrototypes[type]->clone();
	}

	// Implementing memento vars
	SStore s_tmp[numSoldiers];
	ZStore z_tmp[numSoldiers];
	SMemento* s_mem = nullptr;
	ZMemento* z_mem = nullptr;

	int order[numSoldiers]; 
	int iCount = 1;
	int solCount = 0;
	int zomCount = 0;
	int numSim = fact(numSoldiers);

	string winners[numSim];
	string strWin = "";
	string solNames = "";
	string zomNames = "";

	// Creating Momento
	for (int i = 0; i < numSoldiers; i++)
	{
		s_tmp[i].storeMemento(soldiers[i]->createMemento());
		z_tmp[i].storeMemento(zombies[i]->createMemento());
		order[i] = i;
	}

	int orderSize = sizeof(order) / sizeof(order[0]);

	// Start of apocalypse
	cout << "The long and bloody battle commences!" << endl << endl;

	// Start of simulations
	do
	{
		// Attacking in order
		cout << "Simulation " << iCount << " :" << endl;
    	for (int i = 0; i < numSoldiers; i++)
		{
			soldiers[i]->attack(zombies[order[i]]);

			// Finding the winners
			if (soldiers[i]->getHp() > 0)
			{
				solCount++;
			}
			else
			{
				zomCount++;
			}
			cout << endl;
		}
		
		//Storing names
		if (solCount > (zomCount * 2))
		{
			for (int i = 0; i < numSoldiers; i++)
			{
				solNames += soldiers[i]->getName() + ",";
				zomNames += zombies[i]->getName() + ",";
			}
		}
		winners[iCount - 1] = solNames + zomNames;

		// Restoring from Memento
		for (short i = 0; i < numSoldiers; i++)
		{
			s_mem = s_tmp[i].retreiveMemento();
			z_mem = z_tmp[i].retreiveMemento();

			soldiers[i]->reinstateMemento(s_mem);
			zombies[i]->reinstateMemento(z_mem);
		}

		solNames = "";
		zomNames = "";
		iCount++;
    } while (next_permutation(order, order + orderSize));

	// Displaying winners
	for (int i = 0; i < numSim; i++)
	{
		if (winners[i] != "")
		{
			cout << winners[i] << endl;
		}
	}
	

	// cleanup
	for (int i = 0; i < numSoldiers; i++)
	{
		delete soldiers[i];
		delete zombies[i];
	}
	delete [] soldiers;
	delete [] zombies;
	
	for (int i = 0; i < numFactories; i++)
	{
		delete factories[i];
	}
	//delete [] factories;

	for (int i = 0; i < numZombieTypes; i++)
	{
		delete zombiePrototypes[i];
	}
	delete [] zombiePrototypes;

	return 0;
}



	/*Zombie * newZom = zombiePrototypes[0]->clone();
	cout << "Proto HP->" << zombiePrototypes[0]->getHp() << "  newZom HP->" << newZom->getHp() << endl;

	int newHP = newZom->takeDamage(3);
	cout << "newZom should be on " << newHP << " HP and Proto should still be the same as initial" << endl;

	cout << "Proto HP->" << zombiePrototypes[0]->getHp() << "  newZom HP->" << newZom->getHp() << endl;

	cout << "Proto-> " << &zombiePrototypes[0] << "    newZom-> " << &newZom << endl;*/

	// Debugging print template
	/*cout << "------------Post restoration------------" << endl;
	for (short i = 0; i < numSoldiers; i++)
	{
		soldiers[i]->print();
		zombies[i]->print();
		cout << endl;
	}*/

	//cout << "HERE!" << endl << endl;