#pragma once
//#include "pch.h"

// TODO Make this stuff not static
class MiscFunctions
{
public:
	// Garage functions
	static bool IsGarageOpen(int garageId);
	static bool IsGarageClosed(int garageId);
	static void OpenGarage(int garageId);
	static void CloseGarage(int garageId);

	static void ActivateGarage(int garageId);
	static void DeactivateGarage(int garageId);
	// https://library.sannybuilder.com/#/sa/enums/GarageType
	static void SetGarageType(int garageId, int garageType);
	static void SetResprayFree(int garageId, bool state);

	static void OpenSaveMenu();
	static void TogglePlayerSpeech(bool toggle);

	// Blip functions
	static void HideAllBlips(bool toggle);

};