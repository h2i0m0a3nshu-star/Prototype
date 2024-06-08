#include "player.h"

player::player()
{
	pos.x = GetScreenWidth() / 2;
	pos.y = GetScreenHeight() / 2;
	
	curr_state = IDLE;
	curr_weapon = NORMAL;

	delay = false;

	DestRect = { pos.x, pos.y,48*3,48*3 };
}

void player::set_state(player_state new_state)
{
	entity_sprite.setctr(0);
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
		death();
		break;
	default:
		break;
	}
}

Vector2 player::get_pos() const
{
	return pos;
}

void player::idle()
{
	DestRect.width = 48 * 3;
	DestRect.height = 48 * 3;
	DestRect.y = GetScreenHeight() / 2 + 18;
	if (curr_weapon == NORMAL) {
		delay = entity_sprite.animate(idle_state, DestRect, 0, 10);
	}
	else if (curr_weapon == SWORD) {
		delay = entity_sprite.animate(sword_idle_state, DestRect, 0, 10);
	}
}

void player::attack_right()
{
	DestRect.width = 64 * 3;
	DestRect.height = 64 * 3;
	DestRect.y = GetScreenHeight() / 2;

	if (curr_weapon == NORMAL) {		
		delay = entity_sprite.animate(punch_cross_state, DestRect, 0, 7);
	}
	else if (curr_weapon == SWORD) {
		delay = entity_sprite.animate(sword_basic_attack_state, DestRect, 0, 6);
	}

	if (delay) {
		curr_state = IDLE;
	}
}

void player::attack_left()
{
	DestRect.width = 64 * 3;
	DestRect.height = 64 * 3;
	DestRect.y = GetScreenHeight() / 2;
	if (curr_weapon == NORMAL) {
		delay = entity_sprite.flipanimate(punch_cross_state, DestRect, 7);
	}
	else if (curr_weapon == SWORD) {
		delay = entity_sprite.flipanimate(sword_basic_attack_state, DestRect,6);
	}
	if (delay) {
		curr_state = IDLE;
	}
}

void player::death()
{
	DestRect.width = 64 * 3;
	DestRect.height = 64 * 3;
	DestRect.y = GetScreenHeight() / 2;
	entity_sprite.animate(death_state, DestRect, 0, 10);
}

