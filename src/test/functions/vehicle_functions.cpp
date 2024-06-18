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

/// <summary>
/// Check if the players current vehicle is in the water
/// </summary>
/// <returns>If the current vehicle is in water.</returns>
bool VehicleFunctions::IsCarInWater()
{
#ifdef GTASA
    CPlayerPed* player = FindPlayerPed();
        int hplayer = CPools::GetPedRef(player);
        CVehicle* pVeh = nullptr;

        // TODO Possibly Move this into a vehicle_functions file.
        // First we check if the player is in a vehicle
        if (PlayerFunctions::IsPlayerInVehicle()) {
            CVehicle* pVeh = player->m_pVehicle;
            int hVeh = CPools::GetVehicleRef(pVeh);
            // https://library.sannybuilder.com/#/sa/default/04D8
            bool isCarInWater = Command<Commands::IS_CAR_IN_WATER>(hVeh);

            // If the car is not in water
            if (!isCarInWater)
            {
                return false;
            }
            // If the car is in water
            else
            {
                return true;
            }
        }
#endif //GTASA
}