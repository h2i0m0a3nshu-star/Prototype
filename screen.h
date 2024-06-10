#pragma once
#include "mechanics.h"
#include "player.h"
#include "enemy.h"
#include <raylib.h>

typedef enum screen {
	MAIN_MENU,
	PLAY,
	STORE,
	PAUSE,
};

class Screen {
protected:
public:
	virtual void update_screen() = 0;
};

class play :public Screen {
public:
	void update_screen() override;
	bool game_over_checker();
private:
	player hero;
	enemy e;
	mechanics game_mechanics;
};

class Game_over :public Screen {
public:
	void update_screen() override;
private:
};

class main_menu:public Screen
{
public:
	main_menu();
	void update_screen() override;
	~main_menu() {};

private:

};

