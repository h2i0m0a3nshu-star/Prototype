#include "enemy.h"

enemy::enemy()
{
	curr_state = PURSUE_RIGHT;

	pos.x = 100;
	pos.y = GetScreenHeight() / 2;

	DestRect = {pos.x,pos.y,48 * 3,48 * 3 };
}

void enemy::enemyBehaviour(Vector2 heropos)
{
	if (heropos.x > pos.x && (curr_state != ENEMY_ATTACK_LEFT && curr_state != ENEMY_ATTACK_RIGHT)) {
		curr_state = PURSUE_RIGHT;
	}
	else if (heropos.x < pos.x && (curr_state != ENEMY_ATTACK_LEFT && curr_state != ENEMY_ATTACK_RIGHT)) {
		curr_state = PURSUE_LEFT;
	}

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
		break;
	default:
		break;
	}
}

void enemy::enemy_setState(enemy_state new_state)
{
	curr_state = new_state;
}

Vector2 enemy::get_enemy_pos()
{
	return pos;
}

void enemy::pursue()
{
	DestRect.width = 48 * 3;
	DestRect.height = 48 * 3;
	DestRect.y = GetScreenHeight() / 2 + 18;

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

void enemy::attack()
{
	DestRect.width = 64 * 3;
	DestRect.height = 64 * 3;
	DestRect.y = GetScreenHeight() / 2;

	if (curr_state == ENEMY_ATTACK_RIGHT) {
		entity_sprite.animate(punch_cross_state, DestRect, 0, 7);
	}
	else if(curr_state == ENEMY_ATTACK_LEFT)
	{
		entity_sprite.flipanimate(punch_cross_state, DestRect, 7);
	}
}
