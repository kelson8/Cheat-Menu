#include "pch.h"

#include "vehicle_functions.h"
#include "player_functions.h"

void VehicleTest()
{
	CPlayerPed* player = FindPlayerPed();
	int hplayer = CPools::GetPedRef(player);
	CVehicle* pVeh = nullptr;
	if (PlayerFunctions::IsPlayerInVehicle())
	{
		CVehicle* pVeh = player->m_pVehicle;
		//pVeh->
	}
}

/// <summary>
/// Quick test for making sure this class is working.
/// </summary>
void VehicleFunctions::PlayerInCarMsg()
{
	CPlayerPed* player = FindPlayerPed();
	int hplayer = CPools::GetPedRef(player);
	CVehicle* pVeh = nullptr;
	if (PlayerFunctions::IsPlayerInVehicle())
	{
		Util::SetMessage("You are in a car.");
	}
	else
	{
		Util::SetMessage("You are not in a car.");
	}
}

bool VehicleFunctions::IsCarInWater()
{
	CPlayerPed* player = FindPlayerPed();
	int hplayer = CPools::GetPedRef(player);
	CVehicle* pVeh = nullptr;

	if (PlayerFunctions::IsPlayerInVehicle())
	{
		CVehicle* pVeh = player->m_pVehicle;
		// Will this work?
		int hVeh = CPools::GetVehicleRef(pVeh);
		bool bIsCarInWater = Command<Commands::IS_CAR_IN_WATER>(hVeh);

		if (bIsCarInWater) 
		{
			return true;
			
		}
		else 
		{
			return false;		
		}
	}
	else 
	{
		// This should make this do nothing.
		return false;
	}

	return false;
}

