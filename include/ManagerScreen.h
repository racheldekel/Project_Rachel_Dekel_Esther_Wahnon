#pragma once
//#include "Screen.h"

class ManagerScreen
{
public:

	ManagerScreen() {};
	~ManagerScreen() {};
	int main_run();

	void create_screens(std::vector<Screen*> Screens);

private:
};
