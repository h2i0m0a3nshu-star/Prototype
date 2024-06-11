#pragma once
#include "wave.h"
#include <raylib.h>

class cut_scene_system {
public:
	cut_scene_system();
	void cut_scene_handler(wave_system &wave);

private:
	bool is_active;

};