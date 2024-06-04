#pragma once
#include "screen.h"
#include <raylib.h>

class play:public screen
{
public:
	play();
	void drawScreen() override;
	void updateScreen() override;
	~play();

private:

};
