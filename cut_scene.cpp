#include "cut_scene.h"

cut_scene_system::cut_scene_system()
{

}

void cut_scene_system::cut_scene_handler(wave_system &wave)
{

	if (IsKeyPressed(KEY_O) ||
		IsGamepadButtonPressed(0, GAMEPAD_BUTTON_RIGHT_TRIGGER_2)) {
		wave.set_cut_scene_time(0);
		DrawText("O PRESSED", 400, 400, 30, RED);
	}

	switch (wave.get_wave_number())
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
}
