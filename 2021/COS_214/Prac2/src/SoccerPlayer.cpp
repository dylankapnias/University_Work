#include "../inc/SoccerPlayer.h"

SoccerPlayer::SoccerPlayer() {}

SoccerPlayer::SoccerPlayer(string n, PlayStyle* s) : name(n), style(s) {
    state = new NoCardState();
}

SoccerPlayer::~SoccerPlayer() {}

void SoccerPlayer::commitFoul() {
    state->handle();
    state = state->changeCardState();
}

void SoccerPlayer::play() {
    if (state->getCardColour() != "red") {
        cout << name << " " << style->play() << endl;
    } else {
        cout << "This player cannot demonstrate their play-style, as the have been sent off." << endl;
    }
}

void SoccerPlayer::setStyle(PlayStyle* s) {
    style = s;
}