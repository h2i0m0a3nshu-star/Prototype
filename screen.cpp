#include "screen.h"

// Constructor for the main menu screen
main_menu::main_menu()
{

}

// Function to update the main menu screen
void main_menu::update_screen()
{
	// Drawing the title 
	DrawText("REVENGE SAGA", 205, 205, 80, WHITE);
	DrawText("REVENGE SAGA", 200, 200, 80 , RED);

	DrawText("Press X to play", 0, GetScreenHeight()  - 50, 20, GREEN);
}

// Function to update the play screen
void play::update_screen()
{
	// Input to open the store
	if (IsKeyPressed(KEY_SPACE) ||
		IsGamepadButtonPressed(0, GAMEPAD_BUTTON_RIGHT_TRIGGER_2)) {
		store_screen.open_store = 1;
	}
	// Update the screen to store screen
	if (store_screen.open_store){
		store_screen.update_screen();
		store_screen.input_handler(hero);
	}
	// if a wave is over play the cut sceen
	else if (wave.is_wave_over()) {
		cut_screen.cut_scene_handler(wave);
	}
	// if a cut scene is not being played or the store is not open then handle all the other game mechanics
	else {
		game_mechanics.input_handler(hero);
		game_mechanics.combat_handler(hero, e);
		game_mechanics.behaviours(hero, e);
		wave.wave_handler(e);
		DrawText("Press SPACE or RIGHT TRIGGER 2 to go to the store", 0, GetScreenHeight()  - 50, 20, GREEN);
	}
	
}

// Check if the game is over or not
bool play::game_over_checker()
{
	return game_mechanics.is_game_over(hero);
}

// Function to update the game over screen
void Game_over::update_screen()
{
	DrawText("GAME OVER", GetScreenWidth() / 2 - 250, GetScreenHeight() / 2, 100, RED);
	DrawText("GAME OVER", GetScreenWidth() / 2 - 245, GetScreenHeight() / 2-5, 100, WHITE);
}

// Constructor for the store screen 
store::store()
{
	open_store		= 0;
	sword_bought	= 0;
	katana_bought	= 0;
	potion_bought	= 0;
}

// Function to update the store screen
void store::update_screen()
{
	DrawRectangle(100 , 200, 200, 200, BLACK);

	DrawRectangle(400 , 200, 200, 200, BLACK);

	DrawRectangle(700 , 200, 200, 200, BLACK);

	DrawRectangle(selector.x , selector.y, selector.width, selector.height, YELLOW);

	// Sword graphics and mechanics
	DrawText("SWORD", 130 , 150, 40, BLACK);
	DrawText("SWORD", 135 , 155, 40, RAYWHITE);
	DrawRectangle(110 , 210, 180, 180, RAYWHITE);
	if (sword_bought) {
		DrawText("BOUGHT", 120 , 410, 30, BLACK);
		DrawText("BOUGHT", 125 , 415, 30, RAYWHITE);
	}
	else if (!sword_bought) {
		DrawText("COST:50 XP", 110 , 410, 30, BLACK);
		DrawText("COST:50 XP", 115 , 415, 30, RAYWHITE);
	}

	// Katana graphics and mechanics
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

	// Potion graphics and mechanics
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

	DrawText("Press X to go buy the item", 10, GetScreenHeight()  - 100, 20, GREEN);
	DrawText("Press O to go back to the game", 10, GetScreenHeight()  - 50, 20, GREEN);
}

// Function to handle the input in store
void store::input_handler(player &hero)
{
	DrawText(TextFormat("XP:%i", hero.get_XP()), 800, 10, 30, GREEN);
	// The inputs for navigation from one item to other
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
		IsGamepadButtonPressed(0, GAMEPAD_BUTTON_RIGHT_FACE_RIGHT)) {
		open_store = 0;
	}

	if (
		(IsKeyPressed(KEY_X) ||
		IsGamepadButtonPressed(0, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)) &&
		hero.get_XP() >= 50
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
			hero.get_HP() < 5 && hero.get_HP() > 0
			) {
			potion_bought = 1;
			buy_potion(hero);
		}
	}
}

// Function to buy sword
void store::buy_sword(player& hero)
{
	hero.increase_XP(-50);
	hero.set_weapon(SWORD);
}

// Function to buy katana
void store::buy_katana(player& hero)
{
	hero.increase_XP(-50);
	hero.set_weapon(KATANA);
}

// Function to buy potion
void store::buy_potion(player& hero)
{
	hero.increase_XP(-50);
	hero.take_potion();
}

