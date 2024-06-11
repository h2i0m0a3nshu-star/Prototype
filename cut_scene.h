#pragma once
#include <raylib.h>

class cut_scene_system {
public:
	cut_scene_system();
	void cut_scene_handler(int wave_number);

	bool cut_scene_time;

private:

	void input_handler();
};