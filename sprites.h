#pragma once
#include <raylib.h>

class sprites {
public:
	Texture2D *loadTexture(const char* path);
	void unloadTexture(Texture2D curr);
	bool animate(Texture2D curr, Rectangle DestRect,int rotation,int num_of_images);
	bool flipanimate(Texture2D curr, Rectangle DestRect,int num_of_images);

	void setctr(int newctr);

private:
	int ctr = 0;
	int delay = 5;
	void delay_handler();
};