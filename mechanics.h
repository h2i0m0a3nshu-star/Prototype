#pragma once
#include <iostream>
#include "player.h"
#include "entity.h"
#include "enemy.h"
#include "sprites.h"
#include <raylib.h>

class mechanics {

public:
	void combat_handler();
	bool combat_checker();
	void input_handler();
private:

	int delay = 5;

	int ctr = 0;

	player hero;
	enemy e1;

	int player_input_time = 0;
	int enemy_attack_time = 0;

	void delay_handler();
};