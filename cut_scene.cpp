#include "cut_scene.h"

// Constructor defination
cut_scene_system::cut_scene_system()
{
	frame_ctr = 0;					// Initializing the value to 0
	transparency_value = 255;		// Initializing the value to 255
}

// Cut Scene handling function declration
void cut_scene_system::cut_scene_handler(wave_system &wave)
{

	// Basic input handling 
	if (IsKeyPressed(KEY_O) ||
		IsGamepadButtonPressed(0, GAMEPAD_BUTTON_RIGHT_FACE_RIGHT)) {
		wave.set_cut_scene_time(0);				// Reset the screen to the game
		frame_ctr = 0;							// Reset the frame counter to 0
		transparency_value = 0;					// Reset the transparency value to 0	
	}

	// Updating the frame counter function
	if (frame_ctr <= 10) {
		frame_ctr++;
	}

	// Switch statement for detecting which wave this was
	switch (wave.get_wave_number())
	{
	case 1:
		cut_scene_1();
		break;
	case 2:
		cut_scene_2();
		break;
	case 3:
		cut_scene_3();
		break;

	}
}

// cut scene 1 handler
void cut_scene_system::cut_scene_1()
{
	fading_effect_handler();
	Color text_color = { 255,255,255,transparency_value };
	DrawText("\"The one seeking vengence\nfeels the need to correct something -\nan imbalance in the scales of justice.\"", 100, 100, 30, text_color);
	DrawText("Walking through the harsh jungle I found myself surrounded,\nby the relentless echoes of the past and the shadows of \nthose who murdered my father.", 50, 300, 28, text_color);
}

// cut scene 2 handler
void cut_scene_system::cut_scene_2()
{
	fading_effect_handler();
	Color text_color = { 255,255,255,transparency_value };
	DrawText("\"Seeds of vengence once sown grow tangled roots\ndarkening the heart and feed the fury within.\"", 100, 100, 30, text_color);
	DrawText("Feeding on the fear of the innocent, these people felt not emotion\nI knew in order to defeat a monster I need to become one\nI found my resolve hardening my heart darkening .", 50, 300, 28, text_color);
}

// cut scene 3 handler
void cut_scene_system::cut_scene_3()
{
	fading_effect_handler();
	Color text_color = { 255,255,255,transparency_value };
	DrawText("To Be Continued", 100, 100, 30, text_color);
	DrawText("CREDITS", 50, 300, 28, text_color);
	DrawText("Character Art	 by	ZeggyGames", 50, 330, 28, text_color);
	DrawText("Background Art by  brullov", 50, 360, 28, text_color);
	DrawText("Concept & Programming by\nHimanshu Patel & Simarjeet Singh", 50, 390, 28, text_color);
}

void cut_scene_system::fading_effect_handler()
{
	if (frame_ctr >= 0 && frame_ctr <= 10) {
		transparency_value += 25;
	}
}
