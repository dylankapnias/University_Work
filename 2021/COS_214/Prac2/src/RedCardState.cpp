#include "../inc/RedCardState.h"

using namespace std;

RedCardState::RedCardState() {
    cardColour = "red";
}

void RedCardState::handle() {
    cout << "This player has already been sent of with a red card." << endl;
}

CardState* RedCardState::changeCardState() {
    return nullptr;
}