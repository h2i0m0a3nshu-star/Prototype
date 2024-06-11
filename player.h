#pragma once
#include <iostream>
#include <raylib.h>
#include"entity.h"

typedef enum player_state {
	IDLE,
	ATTACK_RIGHT,
	ATTACK_LEFT,
	PUNISH,
	DEATH
};

typedef enum weapon {
	NORMAL,
	SWORD,
	KATANA
};

// The player class
class player : public entity {
public:
	player();

	int XP;
	int HP;
	
	player_state get_state() const;

	Vector2 get_pos() const;

	void take_hit();
	void player_behaviour();
	void set_state(player_state new_state);
	void set_weapon(weapon new_weapon);
	void take_potion();

	bool is_attacking() override;
	bool is_invincible();
	bool is_alive() override;

	~player() {};
private:
	bool delay;
	
	int invincibility;

	Rectangle DestRect;

	player_state curr_state;
	weapon curr_weapon = NORMAL;

	
	void idle();
	void attack_right();
	void attack_left(); 
	void death();
};