#ifndef NOCARDSTATE_H
#define NOCARDSTATE_H

#include "YellowCardState.h"
#include <iostream>

using namespace std;

class NoCardState : public CardState {
    public:
        NoCardState();
        virtual void handle();
        virtual CardState* changeCardState();
};

#endif