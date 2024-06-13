#pragma once
#include <iostream>
#include <raylib.h>
#include"entity.h"

// Defining player states
typedef enum player_state {
	IDLE,
	ATTACK_RIGHT,
	ATTACK_LEFT,
	PUNISH,
	DEATH
};

// Defining player weapons
typedef enum weapon {
	NORMAL,
	SWORD,
	KATANA
};

// The player class
class player : public entity {
public:
	player();										// Constructor

	player_state get_state() const;					// Function to get the player state

	Vector2 get_pos() const;						// Function to get the player position

	int get_XP() const;								// Function to get the player XP
	int get_HP() const;								// Function to get the player HP

	void take_hit();								// Function to handle if the player gets hit
	void player_behaviour();						// Function to handle the player behaviour
	void set_state(player_state new_state);			// Function to set the player state 
	void set_weapon(weapon new_weapon);				// Function to set the player weapon 
	void increase_XP(int value);					// Function to manipulate the player XP
	void take_potion();								// Function to handle if the player takes potions

	bool is_attacking() override;					// Function to check if the player is attacking
	bool is_invincible();							// Function to check if the player is invincible
	bool is_alive() override;						// Function to check if the player is alive or dead

private:
	bool delay;										
	
	int invincibility;

	Rectangle DestRect;

	player_state curr_state;
	weapon curr_weapon = NORMAL;

	
	void idle();									// Function to handle idle state
	void attack_right();							// Function to attack right
	void attack_left();								// Function to attack left
	void death();									// Function to handle death state

	int XP;
	int HP;

};