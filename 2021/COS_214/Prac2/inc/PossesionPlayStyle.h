#ifndef POSSESIONPLAYSTLYE_H
#define POSSESIONPLAYSTLYE_H

#include "PlayStyle.h"

using namespace std;

class PossesionPlayStyle : public PlayStyle {
    public:
        PossesionPlayStyle();
        ~PossesionPlayStyle();

        virtual string play();
};

#endif
