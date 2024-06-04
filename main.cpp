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
	const int width = 1000, height = 1000;
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
	SetTargetFPS(10);
	while (!WindowShouldClose())
	{
		delay++;
		BeginDrawing();
		ClearBackground(BLACK);

		DrawLine(0, pos.y + 80, GetScreenWidth(), pos.y + 80, GREEN);
		DrawLine(0, pos.y + 100, GetScreenWidth(), pos.y + 100, GREEN);
		//hero.behaviour();
		gameplay.input_handler();
		EndDrawing();
	}
	CloseWindow();
	return 0;
}

