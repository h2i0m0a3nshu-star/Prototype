#pragma once
#include "wave.h"
#include "cut_scene.h"
#include "mechanics.h"
#include "player.h"
#include "enemy.h"
#include <raylib.h>

class Screen {
protected:
public:
	virtual void update_screen() = 0;
};

class store{
public:
	bool open_store;

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
private:
	player hero;
	enemy e;
	mechanics game_mechanics;
	store store_screen;
	wave_system wave;
	cut_scene_system cut_screen;

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

