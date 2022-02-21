#ifndef SOCCERPLAYER_H
#define SOCCERPLAYER_H

#include <string>
#include <iostream>
#include "NoCardState.h"
#include "PlayStyle.h"

using namespace std;

class SoccerPlayer {
    private:
        string name;
        CardState* state;
        PlayStyle* style;

    public:
        SoccerPlayer();
        SoccerPlayer(string, PlayStyle*);
        ~SoccerPlayer();
        void commitFoul();
        void play();
        void setStyle(PlayStyle*);
};

#endif