#include "pch.h"
#include "misc_functions.h"


//////////////////////////
// Misc options
//////////////////////////

// Untested
/// <summary>
/// Opens the save menu, only works if the player is not dead.
/// </summary>
void MiscFunctions::OpenSaveMenu()
{
	CPlayerPed* player = FindPlayerPed();
	if (!player->IsAlive())
	{
		Command<Commands::ACTIVATE_SAVE_MENU>();
	}
}


/// <summary>
/// Toggle the player talking or not.
/// </summary>
void MiscFunctions::TogglePlayerSpeech(bool toggle)
{
	CPlayerPed* player = FindPlayerPed();
	int hplayer = CPools::GetPedRef(player);

	if (toggle) 
	{	
		Command<Commands::ENABLE_CHAR_SPEECH>(hplayer);
	}
	else 
	{
		Command<Commands::DISABLE_CHAR_SPEECH>(hplayer);
	}
}

//////////////////
// Begin untested functions
//////////////////

// Test messing with a void or boolean from the code in a memory address
/*
// 0x4B1330
bool CEventHitByWaterCannon::AffectsPed
*/

// Will this work? Possibly patch out the code so the player or peds aren't effected by a firetruck water cannon.
// I don't think this works like this though but it looks like I can replace functions in the code, 
// using the reversed code as a guide on what the functions are doing.
// TODO Test this later!
bool ToggleWaterCannonTest()
{
	return false;
}


void ToggleWaterCannonHit()
{
	patch::ReplaceFunction(0x4B1330, *ToggleWaterCannonTest, true);
}

// This is untested but it should work like this.
void ChangeClothes(CPed* player, const char* textureName, const char* modelName, int bodyPart)
{

	//Command<Commands::GIVE_PLAYER_CLOTHES_OUTSIDE_SHOP>(player, "tshirt2horiz", "tshirt2", 0);
	Command<Commands::GIVE_PLAYER_CLOTHES_OUTSIDE_SHOP>(player, textureName, modelName, bodyPart);
}

/// <summary>
/// Change the players current outfit, this isn't tested yet.
/// </summary>
void ChangePlayerClothes()
{
	CPed* player = FindPlayerPed();
	// https://wiki.multitheftauto.com/wiki/CJ_Clothes
	// player, textureName, modelName, bodyPart
	// Sun glasses
	//Command<Commands::GIVE_PLAYER_CLOTHES_OUTSIDE_SHOP>(player, "glasses01dark", "glasses01", 15);
	 ChangeClothes(player, "glasses01dark", "glasses01", CLOTHES_MODEL_GLASSES);
	// White striped shirt.
	//Command<Commands::GIVE_PLAYER_CLOTHES_OUTSIDE_SHOP>(player, "tshirt2horiz", "tshirt2", 0);
	ChangeClothes(player, "tshirt2horiz", "tshirt2", CLOTHES_MODEL_TORSO);
	// Camo green pants
	ChangeClothes(player, "worktrcamogrn", "worktr", CLOTHES_MODEL_LEGS);
	// Shoes
	ChangeClothes(player, "sneakerbincblu", "sneaker", CLOTHES_MODEL_SHOES);
	// Watch ,this one didn't seem to have an enum for it
	ChangeClothes(player, "watchcro", "watch", 14);

}




/// <summary>
/// // Change the current day of the week, from 1-7. Untested.
/// </summary>
/// <param name="dayToSet">Date to set the game time to.</param>
void ChangeCurrentDay(int dayToSet)
{
	patch::Set<byte>(0xB7014E, dayToSet, true);
}

/// <summary>
/// Get the current day of the week, from 1-7. Untested.
/// </summary>
void GetCurrentDay() 
{
	patch::Get<byte>(0xB7014E);
}

//////////////////
// End untested functions
//////////////////

//////////////////////////
// Blip options
//////////////////////////


void MiscFunctions::HideAllBlips(bool toggle)
{
	
	if (toggle) 
	{
		Command<Commands::HIDE_ALL_FRONTEND_BLIPS>(true);
	}
	else
	{
		Command<Commands::HIDE_ALL_FRONTEND_BLIPS>(false);

	}
	// Will it work like this also?
	//Command<Commands::HIDE_ALL_FRONTEND_BLIPS>(toggle);
}

//////////////////////////
//
//////////////////////////



//////////////////////////
// Garage functions
// These are untested but they should work.
//////////////////////////

bool MiscFunctions::IsGarageOpen(int garageId)
{
	if(Command<Commands::IS_GARAGE_OPEN>(garageId))
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

bool MiscFunctions::IsGarageClosed(int garageId)
{
	if (Command<Commands::IS_GARAGE_CLOSED>(garageId))
	{
		return true;
	}
	else
	{ 
		return false;
	}
}
void MiscFunctions::OpenGarage(int garageId)
{
	Command<Commands::OPEN_GARAGE>(garageId);
}

void MiscFunctions::CloseGarage(int garageId)
{
	Command<Commands::CLOSE_GARAGE>(garageId);

}

void MiscFunctions::ActivateGarage(int garageId)
{
	Command<Commands::ACTIVATE_GARAGE>(garageId);
	//Util::SetMessage("You have enabled the garage with id " + garageId);
}


void MiscFunctions::DeactivateGarage(int garageId)
{
	Command<Commands::DEACTIVATE_GARAGE>(garageId);
	//Util::SetMessage("You have disabled the garage with id " + garageId);
}

void MiscFunctions::SetGarageType(int garageId, int garageType)
{
	Command<Commands::CHANGE_GARAGE_TYPE>(garageId, garageType);
	Util::SetMessage(std::format("You have changed the garage with id {} to type id {} ", garageId, garageType).c_str());
}

void MiscFunctions::SetResprayFree(int garageId, bool toggle)
{
	if (toggle)
	{
		Command<Commands::SET_FREE_RESPRAYS>(garageId, true);
		Util::SetMessage("Resprays are now free at this Pay N Spray!");
		// Resprays are now free at this Pay N Spray!
	}
	else
	{
		Command<Commands::SET_FREE_RESPRAYS>(garageId, false);
		Util::SetMessage("Resprays are no longer free at this Pay N Spray!");
			// Resprays are no longer free at this Pay N Spray!
	}

}

//////////////////////////
//
//////////////////////////