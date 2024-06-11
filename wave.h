#pragma once
#include <raylib.h>
#include "enemy.h"

class wave_system {
public:
	wave_system();
	void reincarnate_enemy(enemy &e);
	void wave_handler(enemy& e);
	void wave_updater();
private:
	int curr_wave;
	int num_of_enemies;
	int curr_num_of_enemies;

	int delay = 0;

	bool wave_over;

	void delay_handler();

};

