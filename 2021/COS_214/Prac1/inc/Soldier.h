#ifndef SOLDIER_H
#define SOLDIER_H

#include "Zombie.h"
#include "Soldier_Memento.h"

using namespace std;

class Soldier
{
    private:
        string name;
        string primaryWeapon;
        string secondaryWeapon;
        int hp;
        int damage = 0;

    public:
        // Constructor and destructor
        Soldier();
        Soldier(string n, int h, int d);
        virtual ~Soldier();

        //Functions
        void attack(Zombie * z);
        virtual bool hitZombie(Zombie * z) = 0;
        virtual bool getHit(Zombie * z) = 0;
        virtual void celebrate() = 0;
        virtual void die() = 0;

        // Debuging print
        void print();

        // Getter
        string getName();
        string getPWeapon();
        string getSWeapon();
        int getDamage();
        int getHp();

        //Setter
        void setName(string na);
        void setPWeapon(string pw);
        void setSWeapon(string sw);
        void setDamage(int da);
        void setHp(int val);

        // Memento stuff
	    SMemento *createMemento();
	    void reinstateMemento(SMemento *mem);
};

#endif