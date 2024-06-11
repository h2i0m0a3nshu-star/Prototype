#include "wave.h"

wave_system::wave_system()
{
	curr_wave = 0;
	curr_num_of_enemies = 0;
	num_of_enemies = 0;

	wave_over = 0;
}

void wave_system::reincarnate_enemy(enemy &e)
{
	delay_handler();
	if (e.get_enemy_state() == DEATH_STATE && curr_num_of_enemies < num_of_enemies && delay >= 20)
	{
		delay = 0;
		if (e.reincarnate()) {
			curr_num_of_enemies++;
		}
	}
	else if (curr_num_of_enemies >= num_of_enemies && delay >= 20) {
		delay = 0;
		curr_wave++;
		curr_num_of_enemies = 0;
	}
}

void wave_system::wave_handler(enemy& e)
{
	reincarnate_enemy(e);
	wave_updater();
	DrawText(TextFormat("CURRENT WAVE :%i", curr_wave), 200, 10, 30, GREEN);
	DrawText(TextFormat("ENEMY COUNTER :%i", curr_num_of_enemies), 200, 40, 30, GREEN);
	if (wave_over) {
		curr_wave++;
	}
}

void wave_system::wave_updater()
{
	switch (curr_wave)
	{
	case 0:
		num_of_enemies = 10;
		break;
	case 1:
		num_of_enemies = 15;
		break;
	case 2:
		num_of_enemies = 20;
		break;
	}
}

void wave_system::delay_handler()
{
	if (delay >= 0 && delay < 20) {
		delay++;
	}
}
