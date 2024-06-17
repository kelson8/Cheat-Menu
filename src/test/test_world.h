#pragma once
//#include "pch.h"

class WorldTestPage
{
private:
	void Draw();
public:
	// I had to change these two values to public for this to work, even though they arent in use.
	WorldTestPage();
	WorldTestPage(const WorldTestPage&);
	//
	//static void WorldTestMenu();
	void WorldTestMenu();
};
