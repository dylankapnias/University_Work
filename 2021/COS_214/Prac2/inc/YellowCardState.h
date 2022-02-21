#ifndef YELLOWCARDSTATE_H
#define YELLOWCARDSTATE_H

#include "RedCardState.h"
#include <iostream>

using namespace std;

class YellowCardState : public CardState {
    public:
        YellowCardState();
        virtual void handle();
        virtual CardState* changeCardState();
};

#endif