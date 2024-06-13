#pragma once
#include "sprites.h"
#include <raylib.h>

// Entity class from which both the player and the enemy class will inherit
class entity {
private:

	// Paths for a the game sprites

	const char* idle_state_path = "C:\\College\\Game art\\Character Idle 48x48.png";
	
	const char* run_state_path = "C:\\College\\Game art\\run cycle 48x48.png";
	const char* sword_idle_state_path = "C:\\College\\Game art\\Player Sword Idle 48x48.png";
	
	const char* punch_cross_state_path = "C:\\College\\Game art\\Player Punch Cross 64x64.png";
	const char* sword_basic_attack_path = "C:\\College\\Game art\\player sword atk 64x64.png";
	const char* katana_attack_path = "C:\\College\\Game art\\player katana continuous attack 80x64.png";
	
	const char* death_path = "C:\\College\\Game art\\Player Death 64x64.png";

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

		idle_state = *entity_sprite.loadTexture(idle_state_path);
		sword_idle_state = *entity_sprite.loadTexture(sword_idle_state_path);
		run_state = *entity_sprite.loadTexture(run_state_path);

		punch_cross_state = *entity_sprite.loadTexture(punch_cross_state_path);
		sword_basic_attack_state = *entity_sprite.loadTexture(sword_basic_attack_path);
		katana_attack_state = *entity_sprite.loadTexture(katana_attack_path);

		death_state = *entity_sprite.loadTexture(death_path);
	}

	~entity() {
		
		
	}


};