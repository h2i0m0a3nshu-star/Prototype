#pragma once
#include "entity.h"

typedef enum enemy_state {
	PURSUE,
	ATTACK,
	DEATH
};

class enemy :public entity {
private:

public:
	void enemyBehaviour(Vector2 heropos);
	void pursue();
	void attack();
	void death();
};