#include "../inc/NoCardState.h"

using namespace std;

NoCardState::NoCardState() {
    cardColour = "none";
}

void NoCardState::handle() {
    cout << "This player hasn't commited any previous fouls, and will now be given a yellow card." << endl;
}

CardState* NoCardState::changeCardState() {
    return new YellowCardState();
}