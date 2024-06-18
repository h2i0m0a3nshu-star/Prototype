#pragma once
#include "enemy.h"
#include <raylib.h>

// Wave class
class wave_system {
public:
	wave_system();									// Constructor

	int get_wave_number() const;					// Function to get the current wave number

	bool is_wave_over();							// Function to check if the wave is over
		
	void set_cut_scene_time(bool new_value);		// Function to preview the cut scene
	void reincarnate_enemy(enemy &e);				// Function to reincarnate the enemy
	void wave_handler(enemy& e);					// Funciton to handle the waves
	void wave_updater();							// Function to update the wave

private:
	int curr_wave;									// Variable to store the current wave 
	int num_of_enemies;
	int curr_num_of_enemies;
	int delay = 0;

	bool wave_over;
	bool is_cut_scene_active;

	void delay_handler();

};

