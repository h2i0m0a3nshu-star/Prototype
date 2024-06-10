#include "screen.h"

main_menu::main_menu()
{

}

void main_menu::update_screen()
{
	DrawText("REVENGE SAGA", 202, 202, 80, WHITE);
	DrawText("REVENGE SAGA", 200, 200, 80, RED);

	DrawText("Press x to play", 0, 480, 20, GREEN);
}

void play::update_screen()
{
	game_mechanics.input_handler(hero);
	game_mechanics.combat_handler(hero, e);
	game_mechanics.behaviours(hero, e);
}

bool play::game_over_checker()
{
	return game_mechanics.is_game_over(hero);
}

void Game_over::update_screen()
{
	ClearBackground(BLACK);
	DrawText("GAME OVER", GetScreenWidth() / 2, GetScreenHeight() / 2, 50, RED);
}
