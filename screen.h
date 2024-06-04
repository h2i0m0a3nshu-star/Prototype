#pragma once
#include <raylib.h>
using namespace std;

class screen
{
public:
	screen() {};
	virtual void drawScreen() {};
	virtual void updateScreen() {};
	~screen() {};
private:

};

class main_menu:public screen{
public:
	void drawScreen() override;
	void updateScreen() override;
private:
};

class settings :public screen {
public:
	void drawScreen() override;
	void updateScreen() override;

};