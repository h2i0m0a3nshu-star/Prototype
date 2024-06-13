#include "wave.h"

wave_system::wave_system()
{
	curr_wave = 0;
	curr_num_of_enemies = 0;
	num_of_enemies = 0;
	is_cut_scene_active = 0;
	wave_over = 0;
}

int wave_system::get_wave_number() const
{
	return curr_wave;
}

bool wave_system::is_wave_over()
{
	return wave_over;
}

void wave_system::set_cut_scene_time(bool new_value)
{
	wave_over = new_value;
	is_cut_scene_active = new_value;
}

void wave_system::reincarnate_enemy(enemy &e)
{
	delay_handler();
		if (
			e.get_enemy_state() == DEATH_STATE && 
			delay >= 10 && 
			!wave_over
			)
		{
			delay = 0;
			int rand = GetRandomValue(0, 51);
			if (rand % 2 == 0) {
				e.enemy_setPos(0);
				e.enemy_setState(PURSUE_RIGHT);
			}
			else {
				e.enemy_setPos(GetScreenWidth() - 40);
				e.enemy_setState(PURSUE_LEFT);
			}
			if (curr_num_of_enemies >= num_of_enemies) {
				wave_over = 1;
			}
			curr_num_of_enemies++;
		}
		
		if (wave_over)
		{
			curr_wave++;
			curr_num_of_enemies = 0;
			is_cut_scene_active = 1;
		}
}

void wave_system::wave_handler(enemy& e)
{
	reincarnate_enemy(e);
	wave_updater();
	DrawText(TextFormat("CURRENT WAVE :%i", curr_wave), 200, 10, 30, GREEN);
	DrawText(TextFormat("ENEMY COUNTER :%i", curr_num_of_enemies), 200, 40, 30, GREEN);
	
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
	if (delay >= 0 && delay < 25) {
		delay++;
	}

}
