#include "mechanics.h"

void mechanics::input_handler(player &hero)
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

void mechanics::combat_handler(player &hero, enemy &e)
{
	if (e.is_alive()
		&& (e.get_enemy_state() == PURSUE_RIGHT || e.get_enemy_state() == ENEMY_ATTACK_RIGHT)
		&& hero.get_state() == ATTACK_LEFT
		&& combat_checker(hero, e)) {
		e.enemy_setState(DEATH_STATE);  
	}
	else if (e.is_alive()
		&& (e.get_enemy_state() == PURSUE_LEFT || e.get_enemy_state() == ENEMY_ATTACK_LEFT)
		&& hero.get_state() == ATTACK_RIGHT
		&& combat_checker(hero, e)) {
		e.enemy_setState(DEATH_STATE);
		hero.XP++;
	}

	if (hero.is_alive() && e.get_enemy_state() != DEATH_STATE && e.is_attacking()) {
		hero.take_hit();
	}
}

void mechanics::behaviours(player &hero, enemy &e)
{
	hero.player_behaviour();
	e.enemyBehaviour(hero.get_pos());
}

bool mechanics::is_game_over(player &hero)
{
	return !hero.is_alive();
}

bool mechanics::combat_checker(player hero, enemy e)
{
	if ( e.get_enemy_pos().x + 110 > hero.get_pos().x 
		&& (e.get_enemy_state() == PURSUE_RIGHT || e.get_enemy_state() == ENEMY_ATTACK_RIGHT)) {
		return true;
	}
	else if (e.get_enemy_pos().x - 110 < hero.get_pos().x
		&& (e.get_enemy_state() == PURSUE_LEFT || e.get_enemy_state() == ENEMY_ATTACK_LEFT)) {
		return true;
	}
	return false;
}

bool mechanics::is_enemy_dead(enemy e)
{
	return e.get_enemy_state() == DEATH_STATE;
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
