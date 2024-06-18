#pragma once
#include <raylib.h>

// Sprite class
class sprites {
public:
	Texture2D *loadTexture(const char* path);												// Function to load texture
	void unloadTexture(Texture2D curr);														// Function to unload texture
	bool animate(Texture2D curr, Rectangle DestRect,int rotation,int num_of_images);		// Function to animate
	bool flipanimate(Texture2D curr, Rectangle DestRect,int num_of_images);					// Function to flip the animation
	void setColor(Color new_color);															// Function to set the color
	void setctr(int newctr);																// Function to set the frame counter
	
private:
	int ctr = 0;																			// Frame counter

	Color main_color = RAYWHITE;															// Main color 
};