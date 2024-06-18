#include "screen.h"
#include <direct.h>
#include <raylib.h>
using namespace std;

int main(){
	const int width = 1000, height = 500 + 24 * 4;								// Declaring the screen dimensions
	InitWindow(width, height, "REVENGE SAGA ");									// Creating the game window
																				
	main_menu main_menu_screen;													// Screen - Main Menu
	play play_screen;															// Screen - Play 
	Game_over game_over_screen;													// Screen - Game Over
	
	Screen *curr_screen = &main_menu_screen;									// Tracking the current screen
	

	char buffer[1024];
	char* path = _getcwd(buffer, 1024);

	string BG1 = string(path) + "\\Game Art\\background_layer_1.png";			// Path for the Background layer - 1
	string BG2 = string(path) + "\\Game Art\\background_layer_2.png";			// Path for the Background layer - 2
	string BG3 = string(path) + "\\Game Art\\background_layer_3.png";			// Path for the Background layer - 3
	string ground = string(path) + "\\Game Art\\Ground.png";					// Path for the ground tileset
	
	Texture2D B_G_1 = LoadTexture(BG1.c_str());											// Loading the Background layer - 1
	Texture2D B_G_2 = LoadTexture(BG2.c_str());											// Loading the Background layer - 2
	Texture2D B_G_3 = LoadTexture(BG3.c_str());											// Loading the Background layer - 3
	Texture2D ground_tileset = LoadTexture(ground.c_str());								// Loading the ground tileset
	
	Vector2 ground_pos = { 0,532 };

	SetTargetFPS(20);															// Setting the frame speed
	while (!WindowShouldClose())												// Game loop
	{

		// Handle window maximization and minimization
		if (IsKeyPressed(KEY_F11)) {
			ToggleFullscreen();  // Toggle fullscreen mode
		}
		if (IsKeyPressed(KEY_F10)) {
			RestoreWindow();     // Restore the window from fullscreen mode
		}

		if ((IsKeyPressed(KEY_X) ||												// Gmae Input to the play screen			
			IsGamepadButtonPressed(0, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)) &&
			curr_screen == &main_menu_screen) {
			curr_screen = &play_screen;
		}
		else if (curr_screen == &play_screen &&									// Gmae Input to the game over screen
			play_screen.game_over_checker()) {
			curr_screen = &game_over_screen;
		}
		
		BeginDrawing();															// Begin the Drawing
		ClearBackground(BLACK);
		//Draw the Background
		DrawTextureEx(B_G_1, { 0,0 }, 0,3, RAYWHITE);
		DrawTextureEx(B_G_2, { 0,0 }, 0, 3, RAYWHITE);
		DrawTextureEx(B_G_3, { 0,0 }, 0, 3, RAYWHITE);
		DrawTextureEx(B_G_1, { float(B_G_1.width)*3,0},  0, 3, RAYWHITE);
		DrawTextureEx(B_G_2, { float(B_G_2.width)*3,0 }, 0, 3, RAYWHITE);
		DrawTextureEx(B_G_3, { float(B_G_3.width)*3,0 }, 0, 3, RAYWHITE);
		// Draw the ground tileset
		DrawTextureEx(ground_tileset, { ground_pos.x,ground_pos.y}, 0, 3, RAYWHITE);
		DrawTextureEx(ground_tileset, { float(ground_tileset.width * 3),ground_pos.y }, 0, 4, RAYWHITE);
		DrawTextureEx(ground_tileset, { float(ground_tileset.width * 6),ground_pos.y }, 0, 4, RAYWHITE);
		DrawTextureEx(ground_tileset, { float(ground_tileset.width * 9),ground_pos.y }, 0, 4, RAYWHITE);
		DrawTextureEx(ground_tileset, { float(ground_tileset.width * 12),ground_pos.y },0, 4, RAYWHITE);
		// Update the current screen 
		curr_screen->update_screen();
		EndDrawing();
	}

	CloseWindow();
	return 0;
}