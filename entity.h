#pragma once
#include <iostream>
#include "sprites.h"
#include <raylib.h>
#include <direct.h>
using namespace std;

// Entity class from which both the player and the enemy class will inherit
class entity {
private:

	// Paths for a the game sprites
	char buffer[1024];
	char* path = _getcwd(buffer, 1024);

	string idle_state_path = string(path) + "\\Game Art\\Character Idle 48x48.png";
	string run_state_path = string(path) + "\\Game Art\\run cycle 48x48.png";
	string sword_idle_state_path = string(path) + "\\Game Art\\Player Sword Idle 48x48.png";
	string punch_cross_state_path = string(path) + "\\Game Art\\Player Punch Cross 64x64.png";
	string sword_basic_attack_path = string(path) + "\\Game Art\\player sword atk 64x64.png";
	string katana_attack_path = string(path) + "\\Game Art\\player katana continuous attack 80x64.png";
	string death_path = string(path) + "\\Game Art\\Player Death 64x64.png";

protected:
	sprites entity_sprite;
	
	// Textures for the sprites
	Texture2D idle_state;
	Texture2D sword_idle_state;
	Texture2D run_state;
	Texture2D punch_cross_state;
	Texture2D sword_basic_attack_state;
	Texture2D katana_attack_state;
	Texture2D death_state;

	// Position of the entity
	Vector2 pos;

	// Function to check if the entity is alive or attacking
	virtual bool is_alive() = 0;
	virtual bool is_attacking() = 0;

public:
	
	// Loading the textures in the constructor
	entity() {

		pos = { 0 , 0 };

		idle_state = *entity_sprite.loadTexture(idle_state_path.c_str());
		sword_idle_state = *entity_sprite.loadTexture(sword_idle_state_path.c_str());
		run_state = *entity_sprite.loadTexture(run_state_path.c_str());
		punch_cross_state = *entity_sprite.loadTexture(punch_cross_state_path.c_str());
		sword_basic_attack_state = *entity_sprite.loadTexture(sword_basic_attack_path.c_str());
		katana_attack_state = *entity_sprite.loadTexture(katana_attack_path.c_str());
		death_state = *entity_sprite.loadTexture(death_path.c_str());
	}

	~entity() {
		
		
	}


};