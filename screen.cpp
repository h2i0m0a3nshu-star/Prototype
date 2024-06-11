#include "screen.h"

main_menu::main_menu()
{

}

void main_menu::update_screen()
{
	DrawText("REVENGE SAGA", 205, 205, 80, WHITE);
	DrawText("REVENGE SAGA", 200, 200, 80, RED);

	DrawText("Press X to play", 0, 560, 20, GREEN);
}

void play::update_screen()
{
	if (IsKeyPressed(KEY_SPACE) ||
		IsGamepadButtonPressed(0, GAMEPAD_BUTTON_RIGHT_TRIGGER_2)) {
		store_screen.open_store = 1;
	}
	if (store_screen.open_store){
		store_screen.update_screen();
		store_screen.input_handler(hero);
	}
	else if (wave.wave_over) {
		cut_screen.cut_scene_handler(wave.get_wave_number());
	}
	else {
		game_mechanics.input_handler(hero);
		game_mechanics.combat_handler(hero, e);
		game_mechanics.behaviours(hero, e);
		wave.wave_handler(e);
		DrawText("Press SPACE or LEFT TRIGGER 2 to go to the store", 10, 560, 20, GREEN);
	}
	DrawText(TextFormat("%i", wave.get_wave_number()), 200, 560, 20, GREEN);

}

bool play::game_over_checker()
{
	return game_mechanics.is_game_over(hero);
}

void Game_over::update_screen()
{
	DrawText("GAME OVER", GetScreenWidth() / 2 - 250, GetScreenHeight() / 2, 100, RED);
	DrawText("GAME OVER", GetScreenWidth() / 2 - 245, GetScreenHeight() / 2-5, 100, WHITE);
}

store::store()
{
	open_store		= 0;
	sword_bought	= 0;
	katana_bought	= 0;
	potion_bought	= 0;
}

void store::update_screen()
{
	DrawRectangle(100, 200, 200, 200, BLACK);

	DrawRectangle(400, 200, 200, 200, BLACK);

	DrawRectangle(700, 200, 200, 200, BLACK);

	DrawRectangle(selector.x, selector.y, selector.width, selector.height, YELLOW);

	DrawText("SWORD", 130, 150, 40, BLACK);
	DrawText("SWORD", 135, 155, 40, RAYWHITE);
	DrawRectangle(110, 210, 180, 180, RAYWHITE);
	if (sword_bought) {
		DrawText("BOUGHT", 120, 410, 30, BLACK);
		DrawText("BOUGHT", 125, 415, 30, RAYWHITE);
	}
	else if (!sword_bought) {
		DrawText("COST:50 XP", 110, 410, 30, BLACK);
		DrawText("COST:50 XP", 115, 415, 30, RAYWHITE);
	}

	DrawText("KATANA", 420, 150, 40, BLACK);
	DrawText("KATANA", 425, 155, 40, RAYWHITE);
	DrawRectangle(410, 210, 180, 180, RAYWHITE);
	if (katana_bought) {
		DrawText("BOUGHT", 420, 410, 30, BLACK);
		DrawText("BOUGHT", 425, 415, 30, RAYWHITE);
	}
	else if (!katana_bought) {
		DrawText("COST:50 XP", 410, 410, 30, BLACK);
		DrawText("COST:50 XP", 415, 415, 30, RAYWHITE);
	}

	DrawText("POTION", 720, 150, 40, BLACK);
	DrawText("POTION", 725, 155, 40, RAYWHITE);
	DrawRectangle(710, 210, 180, 180, RAYWHITE);
	if (potion_bought) {
		DrawText("BOUGHT", 720, 410, 30, BLACK);
		DrawText("BOUGHT", 725, 415, 30, RAYWHITE);
	}
	else if(!potion_bought){
		DrawText("COST:50 XP", 710, 410, 30, BLACK);
		DrawText("COST:50 XP", 715, 415, 30, RAYWHITE);
	}

	DrawText("Press X to go buy the item", 10, 560, 20, GREEN);
	DrawText("Press O to go back to the game", 10, 540, 20, GREEN);
}

void store::input_handler(player &hero)
{
	DrawText(TextFormat("XP:%i", hero.XP), 800, 10, 30, GREEN);

	if (IsKeyPressed(KEY_D) ||
		IsGamepadButtonPressed(0, GAMEPAD_BUTTON_RIGHT_TRIGGER_1)) {
		if (selector.x == 100) {
			selector.x = 400;
		}
		else if (selector.x == 400) {
			selector.x = 700;
		}
	}
	else if (IsKeyPressed(KEY_A) ||
		IsGamepadButtonPressed(0, GAMEPAD_BUTTON_LEFT_TRIGGER_1)) {
		if (selector.x == 700) {
			selector.x = 400;
		}
		else if (selector.x == 400) {
			selector.x = 100;
		}
	}
	else if (IsKeyPressed(KEY_O) ||
		IsGamepadButtonPressed(0, GAMEPAD_BUTTON_LEFT_TRIGGER_2)) {
		open_store = 0;
	}

	if (
		(IsKeyPressed(KEY_X) ||
		IsGamepadButtonPressed(0, GAMEPAD_BUTTON_LEFT_TRIGGER_1)) &&
		hero.XP >= 50
		) {
		if (selector.x == 100 && !sword_bought) {
			sword_bought = 1;
			buy_sword(hero);
		}
		else if (selector.x == 400 && !katana_bought) {
			katana_bought = 1;
			buy_katana(hero);
		}
		else if (
			selector.x == 700 && !potion_bought &&
			hero.HP < 5 && hero.HP > 0
			) {
			potion_bought = 1;
			buy_potion(hero);
		}
	}
}

void store::buy_sword(player& hero)
{
	hero.XP -= 50;
	hero.set_weapon(SWORD);
}

void store::buy_katana(player& hero)
{
	hero.XP -= 50;
	hero.set_weapon(KATANA);
}

void store::buy_potion(player& hero)
{
	hero.XP -= 50;
	hero.take_potion();
}

