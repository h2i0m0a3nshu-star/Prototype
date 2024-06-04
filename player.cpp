#include "player.h"

player::player()
{
	pos.x = GetScreenWidth() / 2;
	pos.y = GetScreenHeight() / 2;
	
	curr_state = IDLE;

	delay = false;

	DestRect = { pos.x, pos.y,48*2,48*2 };
}

void player::set_state(state new_state)
{
	curr_state = new_state;
}

void player::player_behaviour()
{
	switch (curr_state)
	{
	case IDLE:
		idle();
		break;
	case ATTACK_RIGHT:
		attack_right();
		break;
	case ATTACK_LEFT:
		attack_left();
		break;
	case PUNISH:
		break;
	case DEATH:
		break;
	default:
		break;
	}
}

void player::idle()
{
	DestRect.width = 48 * 2;
	DestRect.height = 48 * 2;
	DestRect.y = GetScreenHeight() / 2+30;
	if (curr_weapon == NORMAL) {
		entity_sprite.animate(idle_state, DestRect, 0, 10);
	}
}

void player::attack_right()
{
	DestRect.width = 64*2;
	DestRect.height = 64*2;
	DestRect.y = GetScreenHeight() / 2;
	delay = entity_sprite.animate(punch_state, DestRect, 0, 8);
	if (delay) {
		curr_state = IDLE;
	}
}

void player::attack_left()
{
	DestRect.width = 64 * 2;
	DestRect.height = 64 * 2;
	DestRect.y = GetScreenHeight() / 2;
	delay = entity_sprite.flipanimate(punch_state, DestRect, 8);
	if (delay) {
		curr_state = IDLE;
	}
}

