#pragma once
//#include "pch.h"

class PlayerFunctions
{
public:
	bool m_bRespawnMiddleOfMap;
	PlayerFunctions();
	PlayerFunctions(const PlayerFunctions&);
	static void KillPlayer();
	static void SpawnBombOnPlayer();
	static bool IsPlayerInVehicle();
	static bool IsPlayerInArea(float x1, float y1, float z1, float x2, float y2, float z2);
	static bool IsPlayerInTrain();
	static bool IsPedStuckUnderCar();
	static void AddSoundOnPlayer(int audioId);
	static bool IsPlayerDead();
	static void SetNeverWanted(bool toggle);
	static void SetInvincible(bool toggle);
	static void SetInfiniteAmmo(bool toggle);
};
