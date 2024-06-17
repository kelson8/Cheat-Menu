#include "pch.h"
#include "player_functions.h"

PlayerFunctions::PlayerFunctions()
{
	//if (m_bRespawnMiddleOfMap)
	//{

	//}
}

void PlayerFunctions::KillPlayer()
{
	CPlayerPed* player = FindPlayerPed();
	player->m_fHealth = 0;
	player->m_fArmour = 0;
}

static void SetNeverWanted(bool toggle)
{
	if(toggle)
	{
		// Enable never wanted
	}
	else 
	{
		// Disable never wanted
	}
}

static void SetInvincible(bool toggle) 
{
	if (toggle)
	{
		// Enable invincibility
	}
	else
	{
		// Disable invincibility
	}
}

static void SetInfiniteAmmo(bool toggle) 
{
	if (toggle)
	{
		// Enable infinite ammo
	}
	else
	{
		// Disable infinite ammo
	}
}

//static bool IsPlayerInCar()
//{
//
//}

/// This is untested but it should work.
/// <summary>
/// Checks if the player is in the specified area.
/// Values are the first set of x,y,z and the second set in a cube, if you have ever messed with mta sa lua it's kind of like that.
/// So if you want the player to be killed going from 2,2,2 to 20,20,20 that would be possible.
/// </summary>
/// <returns>If player is in specified area</returns>
/// 
//static bool IsPlayerInArea(float x1, float y1, float z1, float x2, float y2, float z2)
bool PlayerFunctions::IsPlayerInArea(float x1, float y1, float z1, float x2, float y2, float z2)
{
	CPlayerPed* player = FindPlayerPed();
	int hplayer = CPools::GetPedRef(player);

	CVector playerPos = player->GetPosition();

	// https://library.sannybuilder.com/#/sa/default/00A4

	if (Command<Commands::IS_CHAR_IN_AREA_3D>(hplayer,
		x1, y1, z1, x2, y2, z2, false)) {
		return true;
	}
	else
	{
		return false;
	}
}

/// <summary>
/// Check if player is in a train
/// </summary>
/// <returns>If the player is in a train</returns>
bool PlayerFunctions::IsPlayerInTrain()
{
	CPlayerPed* player = FindPlayerPed();
	int hplayer = CPools::GetPedRef(player);
	if (Command<Commands::IS_CHAR_IN_ANY_TRAIN>(hplayer)) {
		return true;
	}
	else 
	{
		return false;
	}
}



