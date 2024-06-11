#pragma once
#include "enemy.h"
#include <raylib.h>

class wave_system {
public:
	wave_system();

	int get_wave_number() const;

	bool is_wave_over();

	void set_cut_scene_time(bool new_value);
	void reincarnate_enemy(enemy &e);
	void wave_handler(enemy& e);
	void wave_updater();

private:
	int curr_wave;
	int num_of_enemies;
	int curr_num_of_enemies;
	int delay = 0;

	bool wave_over;
	bool is_cut_scene_active;

	void delay_handler();

};

