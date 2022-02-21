#ifndef SOLDIER_MEMENTO_H
#define SOLDIER_MEMENTO_H

#include <string>

using namespace std;

class SState
{
    private:
        int iVals[2];
        string sVals[3];
    public:
        SState(int val1, int val2, string val3, string val4, string val5);
        int getFirst();
        int getSecond();
        string getThird();
        string getFourth();
        string getFifth();
};

class SMemento
{
	public:
		virtual ~SMemento();
	private:
		friend class Soldier;
        SState* _state;

		SMemento(int val1, int val2, string val3, string val4, string val5);
};

class SStore
{
    private:
        SMemento* _mem;
	public:
        ~SStore();

        void storeMemento(SMemento* mem);
        SMemento* retreiveMemento();
};

#endif