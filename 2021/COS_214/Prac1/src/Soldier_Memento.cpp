#include "../inc/Soldier_Memento.h"

SState::SState(int val1, int val2, string val3, string val4, string val5)
{
    iVals[0] = val1;
    iVals[1] = val2;
    sVals[0] = val3;
    sVals[1] = val4;
    sVals[2] = val5;
}

int SState::getFirst()
{
    return iVals[0];
}

int SState::getSecond()
{
    return iVals[1];
}

string SState::getThird()
{
    return sVals[0];
}

string SState::getFourth()
{
    return sVals[1];
}

string SState::getFifth()
{
    return sVals[2];
}

SMemento::SMemento(int val1, int val2, string val3, string val4, string val5)
{
    _state = new SState(val1, val2, val3, val4, val5);
}

SMemento::~SMemento()
{
	delete _state;
	_state = 0;
}

void SStore::storeMemento(SMemento* mem)
{
	_mem = mem;
}

SMemento* SStore::retreiveMemento()
{
	return _mem;
}

SStore::~SStore()
{
	delete _mem;
}