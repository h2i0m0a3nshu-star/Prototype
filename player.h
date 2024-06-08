#pragma once
#include <raylib.h>
#include"entity.h"

typedef enum player_state {
	IDLE,
	ATTACK_RIGHT,
	ATTACK_LEFT,
	COMBO,
	PUNISH,
	DEATH
};

// The player class
class player : public entity {
public:
	player();
	void set_state(player_state new_state);
	void player_behaviour();
	Vector2 get_pos() const;
	~player() {};
private:
	bool delay;

	Rectangle DestRect;

	typedef enum weapon {
		NORMAL,
		SWORD
	};

	player_state curr_state;
	weapon curr_weapon = NORMAL;

	void idle();
	void attack_right();
	void attack_left(); 
	void death();
};