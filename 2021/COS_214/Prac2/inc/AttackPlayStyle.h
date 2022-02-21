#ifndef ATTACKPLAYSTLYE_H
#define ATTACKPLAYSTLYE_H

#include "PlayStyle.h"

using namespace std;

class AttackPlayStyle : public PlayStyle {
    public:
        AttackPlayStyle();
        ~AttackPlayStyle();

        virtual string play();
};

#endif
