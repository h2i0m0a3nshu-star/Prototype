#include "mechanics.h"

void mechanics::input_handler()
{
	hero.player_behaviour();
	if (IsKeyDown(KEY_A) || IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_TRIGGER_1)) {
		hero.set_state(ATTACK_LEFT);
	}
	else if (IsKeyDown(KEY_D) || IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_TRIGGER_1)) {
		hero.set_state(ATTACK_RIGHT);
	}
}
