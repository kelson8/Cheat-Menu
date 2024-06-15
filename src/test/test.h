#pragma once
//#include "pch.h"
#include "interface/ipage.h"

class TestPage : public IPage<TestPage>
{
public:
	//bool m_test;

// This is just going to be a blank toggle.
//#ifdef GTASA
//	bool m_saToggle;
//#endif

	TestPage();
	TestPage(const TestPage&);
	void Draw();
	void VehicleTest();
	void PlayerTest();

};

extern TestPage& testPage;
