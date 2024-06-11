#pragma once
#include "enemy.h"
#include <raylib.h>

class wave_system {
public:
	wave_system();

	bool wave_over;

	int get_wave_number() const;

	void reincarnate_enemy(enemy &e);
	void wave_handler(enemy& e);
	void wave_updater();

private:
	int curr_wave;
	int num_of_enemies;
	int curr_num_of_enemies;
	int delay = 0;

	void delay_handler();

};

