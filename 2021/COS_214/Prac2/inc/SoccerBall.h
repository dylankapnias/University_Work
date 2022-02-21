#ifndef SOCCERBALL_H
#define SOCCERBALL_H

#include "Merchandise.h"
#include <string>

using namespace std;

class SoccerBall : public Merchandise {
    private:
        bool inflated;

    public:
        SoccerBall(string, double, bool);
        virtual ~SoccerBall();

        virtual string getDescription() override;
        Merchandise* clone();
};

#endif