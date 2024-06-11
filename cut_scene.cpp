#include "cut_scene.h"

cut_scene_system::cut_scene_system()
{
	cut_scene_time = 0;
}

void cut_scene_system::cut_scene_handler(int wave_number)
{
	
	switch (wave_number)
	{
	case 1:
		DrawText("WORKING", 10, 10, 30, WHITE);
		break;
	case 2:
		DrawText("WORKING", 10, 10, 30, GREEN);
		break;
	case 3:
		DrawText("WORKING", 10, 10, 30, RED);
		break;

	}
	input_handler();
}

void cut_scene_system::input_handler()
{
	if (IsKeyPressed(KEY_O) ||
		IsGamepadButtonPressed(0, GAMEPAD_BUTTON_RIGHT_TRIGGER_2)) {
		cut_scene_time = 0;
	}
}
