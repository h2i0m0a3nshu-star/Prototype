#pragma once
#include "wave.h"
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

class cut_scenes {
public:
	bool cut_scene_time = 0;

	cut_scenes();
	void update_screen();
	void cut_scene_1();
	void cut_scene_2();
	void cut_scene_3();
	void input_handler();
};


class store{
public:
	bool open_store = 0;

	store();
	void update_screen();
	void input_handler(player& hero);
private:
	Rectangle selector = { 100,200,200,200 };

	bool sword_bought;
	bool katana_bought;
	bool potion_bought;

	void buy_sword(player& hero);
	void buy_katana(player& hero);
	void buy_potion(player& hero);
};

class play :public Screen {
public:
	void update_screen() override;
	bool game_over_checker();
protected:
	player hero;
	enemy e;
	mechanics game_mechanics;
	store store_screen;
	wave_system wave;
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

