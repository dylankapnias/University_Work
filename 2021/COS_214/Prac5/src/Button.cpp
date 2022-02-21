#include "../inc/Button.h"

Button::Button(Command* c) : command(c) {}

Button::~Button() {}

void Button::press() {
    command->execute();
}