#pragma once
#include "sprites.h"
#include <raylib.h>

class entity {
private:
	const char* idle_state_path = "C:\\College\\Game art\\Character Idle 48x48.png";
	const char* punch_state_path = "C:\\College\\Game art\\Player Punch 64x64.png";
	const char* punch_cross_state_path = "C:\\College\\Game art\\Player Punch Cross 64x64.png";
	const char* punch_jab_state_path = "C:\\College\\Game art\\Player Jab 48x48.png";

protected:
	sprites entity_sprite;
	
	Texture2D idle_state;
	Texture2D punch_state;
	Texture2D punch_cross_state;
	Texture2D punch_jab_state;

	Vector2 pos;
	Vector2 vel;

public:
	
	entity() {
		pos = { 0 , 0 };
		vel = { 0 , 0 };

		idle_state = *entity_sprite.loadTexture(idle_state_path);
		punch_state = *entity_sprite.loadTexture(punch_state_path);
		punch_cross_state = *entity_sprite.loadTexture(punch_cross_state_path);
		punch_jab_state = *entity_sprite.loadTexture(punch_jab_state_path);

	};
	~entity() {};


};