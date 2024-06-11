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
public:

	enemy();
	
	void enemyBehaviour(Vector2 heropos);
	void enemy_setState(enemy_state new_state);
	void enemy_setPos(int new_pos);
	bool reincarnate();

	Vector2 get_enemy_pos();
	
	bool is_alive() override;
	bool is_attacking() override;

	enemy_state get_enemy_state() const;

private:
	Rectangle DestRect;
	
	enemy_state curr_state;
	
	void pursue();
	void attack();
	void death();
	
	bool should_attack(Vector2 heropos);

};