#include "pch.h"
#include "player_functions.h"
#include "enums/audio_ids.h"
#include "test/utils/timer_util.h"

#include "CExplosion.h"


/// <summary>
/// Mostly helper functions for the player.
/// </summary>

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

/// <summary>
/// Sets the never wanted value, incomplete
/// </summary>
/// <param name="toggle">If never wanted is on</param>
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

/// <summary>
/// Sets the player as invincible, incomplete
/// </summary>
/// <param name="toggle">If the player is invincible.</param>
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

/// <summary>
/// Sets the infinte ammo cheat, incomplete.
/// </summary>
/// <param name="toggle">If infinite ammo is active.</param>
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

// This should work in here, untested

/// <summary>
/// Spawn a bomb on the player with sound, like a grenade or satchel charge.
/// </summary>
void PlayerFunctions::SpawnBombOnPlayer()
{
#ifdef GTASA
	//TODO Test these in the other games, 3 and vc later!
		CPlayerPed* player = FindPlayerPed();
		int hplayer = CPools::GetPedRef(player);

		CVector playerPos = player->GetPosition();

		// https://library.sannybuilder.com/#/sa/default/020C
		// x, y, z, EXPLOSION_CAR
		// Will this work for a time delay on this?
		// No this didn't work at all.

		// This stops the explosions when the player dies.
		if (!player->IsAlive()) {
			return;
		}

		Command<Commands::ADD_EXPLOSION>(playerPos.x, playerPos.y, playerPos.z, EXPLOSION_CAR);

		// https://library.sannybuilder.com/#/sa/default/018C
		// These might work: https://sampwiki.blast.hk/wiki/SoundID
		Command<Commands::ADD_ONE_OFF_SOUND>(playerPos.x, playerPos.y, playerPos.z, AudioIds::EXPLOSION_SOUND);

		// This does about the same as above with a bit more code.
		
		
		// Will this work?
		//int explosionId = CExplosion::AddExplosion(FindPlayerPed(), FindPlayerPed(), EXPLOSION_CAR, playerPos, 1000, 1, 1.0f, true);
		//CExplosion::GetExplosionPosition(explosionId);


		//CExplosion::RemoveAllExplosionsInArea();
#endif //GTASA
}

//static bool IsPlayerInCar()
//{
//
//}

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

bool PlayerFunctions::IsPlayerInVehicle()
{
	CPlayerPed* player = FindPlayerPed();
	int hplayer = CPools::GetPedRef(player);
	if (Command<Commands::IS_CHAR_IN_ANY_CAR>(hplayer)) 
	{
		return true;
	}
	else 
	{
		return false;
	}
}

