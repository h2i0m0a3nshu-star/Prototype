//#include "game.h"
#include "screen.h"
#include <raylib.h>
using namespace std;

typedef enum GameScreen {
	MainMenu,
	Settings,
	Play
};

int main(){
	const int width = 1000, height = 900;
	//game RevengeSaga(width,height,"REVENGE SAGA");
	InitWindow(width, height, "REVENGE SAGA PROTOTYPE");
	GameScreen curr = Play;
	main_menu main_menu_screen;
	settings settings_screen;
	screen* curr_screen = &main_menu_screen;
	int delay = 5;
	Vector2 pos = { GetScreenWidth() / 2,GetScreenHeight() / 2 };
	Vector2 enemypos = { 0,GetScreenHeight() / 2 };
	SetTargetFPS(60);
	while (!WindowShouldClose())
	{
		delay++;
		//curr_screen->updateScreen();
		BeginDrawing();
		ClearBackground(BLACK);
		DrawRectangle(pos.x, pos.y, 50, 50, RED);
		DrawRectangle(enemypos.x, enemypos.y, 50, 50, BLUE);
		enemypos.x += 0.2;

		if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_TRIGGER_1) && delay > 5) {
			pos.x -= 10;
			delay = 0;
		}else if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_TRIGGER_1) && delay > 5) {
			pos.x += 10;
			delay = 0;
		}
		if (pos.x < enemypos.x + 50) {
			enemypos.x = 0;
			DrawText("GAME OVER", 30, 30, 50, RED);

		}
		//curr_screen->drawScreen();
		EndDrawing();
	}
	CloseWindow();
	return 0;
}

