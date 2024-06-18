#pragma once
#include "wave.h"
#include <raylib.h>


// This class handles the cut scene system 
class cut_scene_system {
public:
	cut_scene_system();								// The constructor
	void cut_scene_handler(wave_system &wave);		// The cut scene handling function	

private:
	int frame_ctr;									// A variable to track the frames 
	int transparency_value;							// Some transparency variables for handling the vfx
	void cut_scene_1();								// Function handling the cut scene 1
	void cut_scene_2();								// Function handling the cut scene 2
	void cut_scene_3();								// Function handling the cut scene 3
	void fading_effect_handler();					// Function handling the fading text effects

};