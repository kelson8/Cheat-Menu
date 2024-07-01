#include "pch.h"
#include "player_functions.h"
#include "enums/audio_ids.h"
#include "test/utils/timer_util.h"

#include "CExplosion.h"

/// <summary>
/// Mostly helper functions for the player.
/// </summary>
///

PlayerFunctions::PlayerFunctions()
{
	//if (m_bRespawnMiddleOfMap)
	//{

	//}
}

bool PlayerFunctions::IsPlayerDead()
{
	CPlayerPed* player = FindPlayerPed();
	if(!player->IsAlive())
	{
		return true;
	}
	else 
	{
		return false;
	}
	return false;
}

void PlayerFunctions::KillPlayer()
{
	CPlayerPed* player = FindPlayerPed();
	player->m_fHealth = 0;
	player->m_fArmour = 0;
}

//////////////////////////
// Cheat functions
//////////////////////////

/// <summary>
/// Sets the never wanted value, untested
/// </summary>
/// <param name="toggle">If never wanted is on</param>
void PlayerFunctions::SetNeverWanted(bool toggle)
{
	// TODO Possibly replace these with byte instead of bool.
	if(toggle)
	{
		// Enable never wanted
		patch::Set<bool>(0x969171, 1, true);
	}
	else 
	{
		// Disable never wanted
		patch::Set<bool>(0x969171, 1, true);
	}
}

/// <summary>
/// Sets the player as invincible, untested
/// </summary>
/// <param name="toggle">If the player is invincible.</param>
void PlayerFunctions::SetInvincible(bool toggle) 
{
	CPed* player = FindPlayerPed();
	// Taken from player.cpp on line 124, looks like this is running the infinite health cheat using the memory address
	if (toggle)
	{
		// Enable invincibility	
		patch::Set<bool>(0x96916D, 1, true);
		player->m_nPhysicalFlags.bBulletProof = 1;
		player->m_nPhysicalFlags.bCollisionProof = 1;
		player->m_nPhysicalFlags.bExplosionProof = 1;
		player->m_nPhysicalFlags.bFireProof = 1;
		player->m_nPhysicalFlags.bMeleeProof = 1;
	}
	else
	{
		// Disable invincibility
		patch::Set<bool>(0x96916D, 0, true);
		player->m_nPhysicalFlags.bBulletProof = 0;
		player->m_nPhysicalFlags.bCollisionProof = 0;
		player->m_nPhysicalFlags.bExplosionProof = 0;
		player->m_nPhysicalFlags.bFireProof = 0;
		player->m_nPhysicalFlags.bMeleeProof = 0;
	}
}

/// <summary>
/// Sets the infinte ammo cheat, untested.
/// </summary>
/// <param name="toggle">If infinite ammo is active.</param>
void PlayerFunctions::SetInfiniteAmmo(bool toggle) 
{
	// TODO Possibly replace these with byte instead of bool.

	if (toggle)
	{
		// Enable infinite ammo
		patch::Set<bool>(0x969178, 1, true);
	}
	else
	{
		// Disable infinite ammo
		patch::Set<bool>(0x969178, 0, true);
	}
}

//////////////////////////
//
//////////////////////////


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

		PlayerFunctions::AddSoundOnPlayer(AudioIds::EXPLOSION_SOUND);

		// Alternative method to do this.
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

//////////////////////////
// Vehicle functions
//////////////////////////


//////////////////////////
// Check for the player being in all types of vehicles
//////////////////////////

bool IsPlayerInBoat()
{
	CPlayerPed* player = FindPlayerPed();
	int hplayer = CPools::GetPedRef(player);
	if (Command<Commands::IS_CHAR_IN_ANY_BOAT>(hplayer)) {
		return true;
	}
	else
	{
		return false;
	}
}

bool IsPlayerInHeli()
{
	CPlayerPed* player = FindPlayerPed();
	int hplayer = CPools::GetPedRef(player);
	if (Command<Commands::IS_CHAR_IN_ANY_HELI>(hplayer)) {
		return true;
	}
	else
	{
		return false;
	}
}

bool IsPlayerInPlane()
{
	CPlayerPed* player = FindPlayerPed();
	int hplayer = CPools::GetPedRef(player);
	if (Command<Commands::IS_CHAR_IN_ANY_PLANE>(hplayer)) {
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


/// <summary>
/// Check if the player is in a vehicle
/// </summary>
/// <returns>If the player is in a vehicle.</returns>
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

//////////////////////////
// 
//////////////////////////

/// <summary>
/// Check if the player is stuck under a car
/// </summary>
bool PlayerFunctions::IsPedStuckUnderCar()
{
#ifdef GTASA
	CPlayerPed* player = FindPlayerPed();
	int hplayer = CPools::GetPedRef(player);


	// I don't think this will work making it like this.
	bool bIsPlayerStuckUnderCar = Command<Commands::IS_CHAR_STUCK_UNDER_CAR>(player);

	if (bIsPlayerStuckUnderCar)
	{
		return true;
	}
	else
	{
		return false;
	}

#endif //GTASA
}

//////////////////////////
// 
//////////////////////////


//////////////////////////
// Sound testing
//////////////////////////

// https://library.sannybuilder.com/#/sa/default/018C
// List of sound ids: https://sampwiki.blast.hk/wiki/SoundID
/// <summary>
/// Play a sound on the player at their current coordinates.
/// </summary>
/// <param name="audioId">The audio id to play</param>
void PlayerFunctions::AddSoundOnPlayer(int audioId)
{
	CPlayerPed* player = FindPlayerPed();
	CVector playerPos = player->GetPosition();
	//Command<Commands::ADD_ONE_OFF_SOUND>(playerPos.x, playerPos.y, playerPos.z, AudioIds::EXPLOSION_SOUND);
	// Will this work?
	Command<Commands::ADD_ONE_OFF_SOUND>(playerPos.x, playerPos.y, playerPos.z, audioId);
}

// This is untested.
/// <summary>
/// Play a sound at the specifed coordinates, takes an x,y,z and an audio id.
/// </summary>
/// <param name="audioId">The id of the sound to play</param>
void AddSoundAtCoords(float posX, float posY, float posZ, int audioId)
{
	Command<Commands::ADD_ONE_OFF_SOUND>(posX, posY, posZ, audioId);
}

//////////////////////////
// 
//////////////////////////