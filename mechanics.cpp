#include "mechanics.h"

// Function to handle the input of the game
void mechanics::input_handler(player &hero)
{
	// Calling in delay handler 
	delay_handler();

	// If A or L2 is pressed the player character will attack left 
	if ((IsKeyPressed(KEY_A) || IsGamepadButtonPressed(0, GAMEPAD_BUTTON_LEFT_TRIGGER_1)) && delay == 5) {
		delay = 0;
		hero.set_state(ATTACK_LEFT);
	}
	// If D or R2 is pressed the player character will attack right
	else if ((IsKeyPressed(KEY_D) || IsGamepadButtonPressed(0, GAMEPAD_BUTTON_RIGHT_TRIGGER_1)) && delay == 5) {
		delay = 0;
		hero.set_state(ATTACK_RIGHT);
	}
}

// Function to hanlde combat situations
void mechanics::combat_handler(player &hero, enemy &e)
{
	// If the enemy is alive and in combat situation and if the player attacks the enemy dies
	if (e.is_alive()
		&& (e.get_enemy_state() == PURSUE_RIGHT || e.get_enemy_state() == ENEMY_ATTACK_RIGHT)
		&& hero.get_state() == ATTACK_LEFT
		&& combat_checker(hero, e)) {
		hero.increase_XP(2);
		e.enemy_setState(DEATH_STATE);  
	}
	else if (e.is_alive()
		&& (e.get_enemy_state() == PURSUE_LEFT || e.get_enemy_state() == ENEMY_ATTACK_LEFT)
		&& hero.get_state() == ATTACK_RIGHT
		&& combat_checker(hero, e)) {
		hero.increase_XP(2);
		e.enemy_setState(DEATH_STATE);
	}
	// If the player is alive and in combat situation and if the enemy attacks player HP decreases
	if (hero.is_alive() && e.get_enemy_state() != DEATH_STATE && e.is_attacking()) {
		hero.take_hit();
	}
}

// Function to hanlde the behaviours of all entity
void mechanics::behaviours(player &hero, enemy &e)
{
	hero.player_behaviour();
	e.enemyBehaviour(hero.get_pos());
}

// Function to check game over condition
bool mechanics::is_game_over(player &hero)
{
	return !hero.is_alive();	// If the hero dies the game is over
}

// Function to check combat situations
bool mechanics::combat_checker(player hero, enemy e)
{
	// If the enemy is in a range of 110 units it is a combat situation
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

// Function to handle delay
void mechanics::delay_handler()
{
	if (delay >= 0 && delay < 5) {
		delay++;
	}
	if (enemy_delay >= 0 && enemy_delay < 5) {
		enemy_delay++;
	}
}