#pragma once
#include "player.h"
#include "entity.h"
#include "enemy.h"
#include "sprites.h"
#include <raylib.h>

// Class for handling the mechanics of the game
class mechanics {

public:
	void input_handler(player& hero);				// Function to handle the input of the game
	void combat_handler(player& hero, enemy& e);	// Function to hanlde combat situations
	void behaviours(player& hero, enemy& e);		// Function to hanlde the behaviours of all entity
	bool is_game_over(player& hero);				// Function to check game over condition
private:

	// Some other variables for delay and frame counting
	int delay = 5;									
	int enemy_delay = 0;
	int ctr = 0;

	bool combat_checker(player hero, enemy e);		// Function to check combat situations
	void delay_handler();							// Function to handle delay
};