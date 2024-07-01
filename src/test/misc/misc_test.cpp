#include "pch.h"
#include "misc_test.h"
#include "CBirds.h"

#include "CVehicle.h"
#include "CVehicleModelInfo.h"

// New
#ifdef GTASA
#include "CExplosion.h"
#include "CPopulation.h"
#include "CTaskComplexWanderStandard.h"
#include "CSprite.h"
#endif

MiscTestPage::MiscTestPage()
{

}

// Testing for messing with the code for the birds in the game.
void BirdMenu()
{
	//if(ImGui::Button(""))
	//{
	//	
	//}

	// Create 10 birds with 20 added to the z coord.
	// I don't know if this'll work.
	CPlayerPed* player = FindPlayerPed();
	CVector playerPos = player->GetPosition();
	float posX = playerPos.x;
	float posY = playerPos.y;
	// Spawn 20 above the player
	float posZ = playerPos.z + 20;
	
	// Set the targetPos to a CVector
	CVector targetPos = CVector(posX, posY, posZ);
	// Create the birds.
	CBirds::CreateNumberOfBirds(playerPos, targetPos, 10, 1, true);
}


static void PlayerPedTest()
{
	CPlayerPed* player = FindPlayerPed();

	// Got this from https://github.com/JuniorDjjr/CLEOPlus/blob/main/CLEOPlus/Coop.cpp#L30
	// I think I can modify more for the player or other peds using this
	CPlayerPed* playerTest = CWorld::Players[1].m_pPed;
}

// TODO Figure out how to put a random put in a vehicle.
static void PedVehicleTest()
{
	
}


static void VehicleModelTest()
{
	// Player and vehicle check are needed
	CPlayerPed* playerPed = FindPlayerPed();
	CVector playerPos = playerPed->GetPosition();
	CVehicle* playerVehicle = playerPed->m_pVehicle;

	if(playerVehicle)
	{
		//cVehicleParams
		//CVehicleModelInfo::
		// Will this work? Toggle the lights off if on.
		if (CVehicleModelInfo::ms_lightsOn)
		{
			!CVehicleModelInfo::ms_lightsOn;
		}
		else 
		{
			CVehicleModelInfo::ms_lightsOn;
		}
	}


	
	//CVehicleModelInfo::m_nVehicleClass;
	//CVehicleModelInfo::m_nVehicleType;
}