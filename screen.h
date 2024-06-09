#pragma once
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

class main_menu:public Screen
{
public:
	main_menu() {};
	void update_screen() override;
	~main_menu() {};

private:

};
