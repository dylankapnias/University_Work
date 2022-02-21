#ifndef REDCARDSTATE_H
#define REDCARDSTATE_H

#include "CardState.h"
#include <iostream>

using namespace std;

class RedCardState : public CardState {
    public:
        RedCardState();
        virtual void handle();
        virtual CardState* changeCardState();
};

#endif