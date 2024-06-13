#pragma once
#include <raylib.h>
#include "entity.h"

// Defining the enemy states
typedef enum enemy_state {
	PURSUE_LEFT,
	PURSUE_RIGHT,
	ENEMY_ATTACK_LEFT,
	ENEMY_ATTACK_RIGHT,
	DEATH_STATE
};

// enemy class
class enemy :public entity {
public:

	enemy();											// Constructor
	
	void enemyBehaviour(Vector2 heropos);				// Function to handle the enemy behaviour
	void enemy_setState(enemy_state new_state);			// Function to set the enemy state
	void enemy_setPos(int new_pos);						// Function to set the enemy position
	
	Vector2 get_enemy_pos();							// Function to get the enemy position
	
	bool is_alive() override;							// Function to check if the enemy is alive or dead
	bool is_attacking() override;						// Function to check if the enemy is attacking or not

	enemy_state get_enemy_state() const;				// Function to get the enemy state

private:
	Rectangle DestRect;									// Dest Rect for drawing the character
	
	enemy_state curr_state;								// Variable to store the current state of the enemy
	
	void pursue();										// Function to pursue the player
	void attack();										// Function to attack the player
	void death();										// Function to kill the enemy
	
	bool should_attack(Vector2 heropos);				// Function to check if the enemy should attack or not

};