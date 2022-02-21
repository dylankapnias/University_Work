#include "../inc/YellowCardState.h"

using namespace std;

YellowCardState::YellowCardState() {
    cardColour = "yellow";
}

void YellowCardState::handle() {
    cout << "This player has already recieved a yellow card, and will now be given a red card." << endl;
}

CardState* YellowCardState::changeCardState() {
    return new RedCardState();
}