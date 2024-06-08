#pragma once
#include <raylib.h>
#include "entity.h"

typedef enum enemy_state {
	PURSUE_LEFT,
	PURSUE_RIGHT,
	ENEMY_ATTACK_LEFT,
	ENEMY_ATTACK_RIGHT,
	DEATH_STATE
};

class enemy :public entity {
private:
	Rectangle DestRect;
	enemy_state curr_state;
public:
	enemy();
	void enemyBehaviour(Vector2 heropos);
	void enemy_setState(enemy_state new_state);
	Vector2 get_enemy_pos();
	void pursue();
	void attack();
	void death();
};