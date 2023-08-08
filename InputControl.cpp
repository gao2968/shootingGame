#include "InputControl.h"

char InputControl::now_key[BUTTONS];
char InputControl::old_key[BUTTONS];
XINPUT_STATE InputControl::input;
Stick InputControl::r_stick;
Stick InputControl::l_stick;