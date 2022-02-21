#include "../inc/Zombie_Memento.h"

ZState::ZState(int val1, int val2, string val3)
{
    iVals[0] = val1;
    iVals[1] = val2;
    sVals[0] = val3;
}

int ZState::getFirst()
{
    return iVals[0];
}

int ZState::getSecond()
{
    return iVals[1];
}

string ZState::getThird()
{
    return sVals[0];
}

ZMemento::ZMemento(int val1, int val2, string val3)
{
    _state = new ZState(val1, val2, val3);
}

ZMemento::~ZMemento()
{
	delete _state;
	_state = 0;
}

void ZStore::storeMemento(ZMemento* mem)
{
	_mem = mem;
}

ZMemento* ZStore::retreiveMemento()
{
	return _mem;
}

ZStore::~ZStore()
{
	delete _mem;
}