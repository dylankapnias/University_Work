#ifndef DEFENSIVEPLAYSTLYE_H
#define DEFENSIVEPLAYSTLYE_H

#include "PlayStyle.h"

using namespace std;

class DefensivePlayStyle : public PlayStyle {
    public:
        DefensivePlayStyle();
        ~DefensivePlayStyle();

        virtual string play();
};

#endif
