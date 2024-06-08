//#include "screen.h"
#include <raylib.h>
#include "mechanics.h"
#include "player.h"
using namespace std;

/*typedef enum GameScreen {
	MainMenu,
	Settings,
	Play
};*/

int main(){
	const int width = 1000, height = 500;
	InitWindow(width, height, "REVENGE SAGA PROTOTYPE");
	//GameScreen curr = Play;
	///main_menu main_menu_screen;
	//settings settings_screen;
	//screen* curr_screen = &main_menu_screen;
	mechanics gameplay;
	player hero;
	int delay = 5;
	Vector2 pos = { GetScreenWidth() / 2,GetScreenHeight() / 2 };
	Vector2 enemypos = { 0,GetScreenHeight() / 2 };

	const char *BG1 = "C:\\College\\Game art\\background_layer_1.png";
	const char *BG2 = "C:\\College\\Game art\\background_layer_2.png";
	const char *BG3 = "C:\\College\\Game art\\background_layer_3.png";

	Texture2D B_G_1 = LoadTexture(BG1);
	Texture2D B_G_2 = LoadTexture(BG2);
	Texture2D B_G_3 = LoadTexture(BG3);

	SetTargetFPS(10);
	while (!WindowShouldClose())
	{
		delay++;
		gameplay.combat_handler();
		BeginDrawing();
		ClearBackground(BLACK);
		DrawTextureEx(B_G_1, { 0,0 }, 0, 3, RAYWHITE);
		DrawTextureEx(B_G_2, { 0,0 }, 0, 3, RAYWHITE);
		DrawTextureEx(B_G_3, { 0,0 }, 0, 3, RAYWHITE);
		DrawTextureEx(B_G_1, { float(B_G_1.width)*3,0}, 0, 3, RAYWHITE);
		DrawTextureEx(B_G_2, { float(B_G_2.width)*3,0 }, 0, 3, RAYWHITE);
		DrawTextureEx(B_G_3, { float(B_G_3.width)*3,0 }, 0, 3, RAYWHITE);
		DrawLine(0, pos.y + 80, GetScreenWidth(), pos.y + 80, GREEN);
		DrawLine(0, pos.y + 100, GetScreenWidth(), pos.y + 100, GREEN);
		//hero.behaviour();
		gameplay.input_handler();
		EndDrawing();
	}
	CloseWindow();
	return 0;
}

