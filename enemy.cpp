#include "enemy.h"

// Constructor
enemy::enemy()
{
	// Setting the Initial mechanics to determine the enemy position
	int rand = GetRandomValue(0, 51);				
	if (rand%2 == 0) {
		pos.x = 0;
	}
	else {
		pos.x = GetScreenWidth() - 40;
	}
	pos.y = GetScreenHeight() / 2;
	curr_state = PURSUE_RIGHT;
	DestRect = {pos.x,pos.y,48 * 3,48 * 3 };

	// Setting the enemy color to red
	entity_sprite.setColor(RED);
}

// Function to handle the enemy behaviour
void enemy::enemyBehaviour(Vector2 heropos)
{
	// Mechanics to set the enemy state to fight
	if (should_attack(heropos) && curr_state == PURSUE_RIGHT && curr_state != DEATH_STATE) {
		curr_state = ENEMY_ATTACK_RIGHT;
	}
	else if (should_attack(heropos) && curr_state == PURSUE_LEFT && curr_state != DEATH_STATE) {
		curr_state = ENEMY_ATTACK_LEFT;
	}

	// Mechanics to set the enemy state to pursue
	if (heropos.x > pos.x && curr_state != ENEMY_ATTACK_RIGHT && curr_state != DEATH_STATE) {
		curr_state = PURSUE_RIGHT;
	}
	else if (heropos.x < pos.x && curr_state != ENEMY_ATTACK_LEFT && curr_state != DEATH_STATE) {
		curr_state = PURSUE_LEFT;
	}

	// Swicth statement to check the enemy state and perform suitable actions
	switch (curr_state)
	{
	case PURSUE_LEFT:
	case PURSUE_RIGHT:
		pursue();
		break;
	case ENEMY_ATTACK_LEFT:
	case ENEMY_ATTACK_RIGHT:
		attack();
		break;
	case DEATH_STATE:
		death();
		break;
	default:
		break;
	}

}

// Function to set the enemy state
void enemy::enemy_setState(enemy_state new_state)
{
	curr_state = new_state;
}

// Function to set the enemy position
void enemy::enemy_setPos(int new_pos)
{
	pos.x = new_pos;
	DestRect.x = new_pos;
}

// Function to get the enemy position
Vector2 enemy::get_enemy_pos()
{
	return pos;
}

// Function to check if the enemy is alive or dead
bool enemy::is_alive()
{
	return (curr_state != DEATH_STATE);
}

// Function to check if the enemy is attacking or not
bool enemy::is_attacking()
{
	return (curr_state == ENEMY_ATTACK_LEFT || curr_state == ENEMY_ATTACK_RIGHT);
}

// Function to get the enemy state
enemy_state enemy::get_enemy_state() const
{
	return curr_state;
}

// Function to kill the enemy
void enemy::death()
{
	DestRect.width = 64 * 3;
	DestRect.height = 64 * 3;
	DestRect.y = 410 - 22;
	entity_sprite.animate(death_state, DestRect, 0, 10);
}

// Function to pursue the player
void enemy::pursue()
{
	DestRect.width = 48 * 3;
	DestRect.height = 48 * 3;
	DestRect.y = 410;

	// Function to handle the left and right mechanics
	if (curr_state == PURSUE_RIGHT) {
		entity_sprite.animate(run_state, DestRect, 0, 8);
		pos.x += 10;
		DestRect.x += 10;
	}
	else if (curr_state == PURSUE_LEFT) {
		entity_sprite.flipanimate(run_state, DestRect, 8);
		pos.x -= 10;
		DestRect.x -= 10;

	}
}

// Function to attack the player
void enemy::attack()
{
	DestRect.width = 64 * 3;
	DestRect.height = 64 * 3;
	DestRect.y = 410 - 22;

	// Handling if the left and right mechanics
	if (curr_state == ENEMY_ATTACK_RIGHT) {
		entity_sprite.animate(punch_cross_state, DestRect, 0, 7);
	}
	else if(curr_state == ENEMY_ATTACK_LEFT)
	{
		entity_sprite.flipanimate(punch_cross_state, DestRect, 7);
	}
}

// Function to check if the enemy should attack or not
bool enemy::should_attack(Vector2 heropos)
{
	if (pos.x + 110 > heropos.x && curr_state == PURSUE_RIGHT) {
		return true;
	}
	else if (pos.x - 110 < heropos.x && curr_state == PURSUE_LEFT) {
		return true;
	}
	return false;
}