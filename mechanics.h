#pragma once
#include "player.h"
#include "entity.h"
#include "sprites.h"
#include <raylib.h>

class mechanics {

public:
	void combat_handler();
	bool combat_checker();
	void input_handler();
private:
	bool player_delay = true;

	player hero;

};