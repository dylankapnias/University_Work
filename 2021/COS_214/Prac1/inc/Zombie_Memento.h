#ifndef ZOMBIE_MEMENTO_H
#define ZOMBIE_MEMENTO_H

#include <string>

using namespace std;

class ZState
{
    private:
        int iVals[2];
        string sVals[1];
    public:
        ZState(int val1, int val2, string val3);
        int getFirst();
        int getSecond();
        string getThird();
};

class ZMemento
{
	public:
		virtual ~ZMemento();
	private:
		friend class Zombie;
        ZState* _state;

		ZMemento(int val1, int val2, string val3);
};

class ZStore
{
    private:
        ZMemento* _mem;
	public:
        ~ZStore();

        void storeMemento(ZMemento* mem);
        ZMemento* retreiveMemento();
};

#endif