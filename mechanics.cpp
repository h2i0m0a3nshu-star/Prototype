#include "mechanics.h"

void mechanics::input_handler(player hero)
{
	delay_handler();
	if ((IsKeyPressed(KEY_A) || IsGamepadButtonPressed(0, GAMEPAD_BUTTON_LEFT_TRIGGER_1)) && delay == 5) {
		delay = 0;
		hero.set_state(ATTACK_LEFT);
	}
	else if ((IsKeyPressed(KEY_D) || IsGamepadButtonPressed(0, GAMEPAD_BUTTON_RIGHT_TRIGGER_1)) && delay == 5) {
		delay = 0;
		hero.set_state(ATTACK_RIGHT);
	}
}

void mechanics::combat_handler(player hero, enemy e)
{
	e.enemyBehaviour(hero.get_pos());
	hero.player_behaviour();
	if (e.is_alive() && hero.get_state() == ATTACK_LEFT && combat_checker(hero,e)) {
		e.enemy_setState(DEATH_STATE);  
	}
	if (hero.is_alive() && e.get_enemy_state() != DEATH_STATE && e.is_attacking()) {
		hero.take_hit();
	}
}

bool mechanics::combat_checker(player hero, enemy e)
{
	if ( e.get_enemy_pos().x + 120 > hero.get_pos().x) {
		return true;
	}
	return false;
}

void mechanics::delay_handler()
{
	if (delay >= 0 && delay < 5) {
		delay++;
	}
	if (enemy_delay >= 0 && enemy_delay < 5) {
		enemy_delay++;
	}
}
