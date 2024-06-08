#include "mechanics.h"

void mechanics::combat_handler()
{
	ctr++;
	if (combat_checker()) {
		DrawText(TextFormat("%i", ctr), 500, 400, 40, RED);
		e1.enemy_setState(ENEMY_ATTACK_RIGHT);
		enemy_attack_time = ctr;
		
		std::cout <<"ENEMY :" << enemy_attack_time;

		if ((IsKeyPressed(KEY_A) || IsGamepadButtonPressed(0, GAMEPAD_BUTTON_LEFT_TRIGGER_1)) ||
			(IsKeyPressed(KEY_D) || IsGamepadButtonPressed(0, GAMEPAD_BUTTON_RIGHT_TRIGGER_1))) {
			player_input_time = ctr;
		}
		std::cout <<"PLAYER :" << player_input_time<<std::endl;

		if (enemy_attack_time <= player_input_time) {
			DrawText("GAME OVER", 50, 50, 100, RED);
		}
	}

	DrawText(TextFormat("%i", enemy_attack_time), 50, 50, 100, RED);
	DrawText(TextFormat("%i", player_input_time), 50, 150, 100, RED);
}

bool mechanics::combat_checker()
{
	if (e1.get_enemy_pos().x + 150 > hero.get_pos().x) {
		return true;
	}
	return false;
}

void mechanics::input_handler()
{
	e1.enemyBehaviour(hero.get_pos());
	hero.player_behaviour();

	delay_handler();
	if ((IsKeyPressed(KEY_A) || IsGamepadButtonPressed(0, GAMEPAD_BUTTON_LEFT_TRIGGER_1)) && delay == 5) {
		delay = 0;
		hero.set_state(ATTACK_LEFT);
	}
	else if ((IsKeyPressed(KEY_D) || IsGamepadButtonPressed(0, GAMEPAD_BUTTON_RIGHT_TRIGGER_1)) && delay == 5) {
		delay = 0;
		hero.set_state(ATTACK_RIGHT);
	}
}

void mechanics::delay_handler()
{
	if (delay >= 0 && delay < 5) {
		delay++;
	}
}
