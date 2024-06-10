#include "screen.h"
#include <raylib.h>
using namespace std;

int main(){
	const int width = 1000, height = 500 + 24 * 4;
	InitWindow(width, height, "REVENGE SAGA PROTOTYPE");
	
	main_menu main_menu_screen;
	play play_screen;
	Game_over game_over_screen;
	
	Screen *curr_screen = &main_menu_screen;

	const char *BG1 = "C:\\College\\Game art\\background_layer_1.png";
	const char *BG2 = "C:\\College\\Game art\\background_layer_2.png";
	const char *BG3 = "C:\\College\\Game art\\background_layer_3.png";
	const char* ground = "C:\\College\\Game art\\Ground.png";

	Texture2D B_G_1 = LoadTexture(BG1);
	Texture2D B_G_2 = LoadTexture(BG2);
	Texture2D B_G_3 = LoadTexture(BG3);
	Texture2D ground_tileset = LoadTexture(ground);

	SetTargetFPS(10);
	while (!WindowShouldClose())
	{
		if ((IsKeyPressed(KEY_X) ||
			IsGamepadButtonPressed(0, GAMEPAD_AXIS_LEFT_X)) &&
			curr_screen == &main_menu_screen) {
			curr_screen = &play_screen;
		}
		else if (curr_screen == &play_screen && play_screen.game_over_checker()) {
			curr_screen = &game_over_screen;
		}

		BeginDrawing();
		ClearBackground(BLACK);

		DrawTextureEx(B_G_1, { 0,0 }, 0, 3, RAYWHITE);
		DrawTextureEx(B_G_2, { 0,0 }, 0, 3, RAYWHITE);
		DrawTextureEx(B_G_3, { 0,0 }, 0, 3, RAYWHITE);

		DrawTextureEx(B_G_1, { float(B_G_1.width)*3,0}, 0, 3, RAYWHITE);
		DrawTextureEx(B_G_2, { float(B_G_2.width)*3,0 }, 0, 3, RAYWHITE);
		DrawTextureEx(B_G_3, { float(B_G_3.width)*3,0 }, 0, 3, RAYWHITE);
		
		DrawTextureEx(ground_tileset, { 0,532}, 0, 3, RAYWHITE);
		DrawTextureEx(ground_tileset, { float(ground_tileset.width * 3),532}, 0, 3, RAYWHITE);
		DrawTextureEx(ground_tileset, { float(ground_tileset.width * 6),532}, 0, 3, RAYWHITE);
		DrawTextureEx(ground_tileset, { float(ground_tileset.width * 9),532}, 0, 3, RAYWHITE);
		DrawTextureEx(ground_tileset, { float(ground_tileset.width * 12),532}, 0, 3, RAYWHITE);
		curr_screen->update_screen();
		EndDrawing();
	}
	CloseWindow();
	return 0;
}

