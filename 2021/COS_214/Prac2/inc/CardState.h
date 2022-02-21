#ifndef CARDSTATE_H
#define CARDSTATE_H

#include <string>
#include <iostream>

using namespace std;

class CardState {
    protected:
        string cardColour;

    public:
        CardState();
        virtual ~CardState();
        virtual void handle() = 0;
        virtual CardState* changeCardState() = 0;
        string getCardColour();
};

#endif