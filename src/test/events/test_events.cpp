#include "pch.h"
#include "test_events.h"
#include "./test/functions/player_functions.h"
#include "./test/utils/timer_util.h"

#include "CPhysical.h"

#ifdef GTASA
#include "CClock.h"
#include "CTimer.h"

#endif //GTASA

// TODO Move Chaos mode events into its own file.
// Most of these events will only run if this is defined
//#define _CHAOS_MODE


// Stuff to mess around with
// playerPed->m_nFightingStyle = STYLE_BOXING;
// playerPed->m_nPhysicalFlags.bApplyGravity = false;

// Make it to where if the car catches on fire the player can't exit it.
// playerPed->m_nPedFlags.bCanExitCar = false;
// playerPed->m_nPedFlags.bDontFight = false;
// playerPed->m_nPedFlags.CantBeKnockedOffBike = false;


// TODO Move these and other chaos items into a seperate mod named KCNet-SAChaosMod
// Most of these are running on the main class which is cheatmenu.cpp

// TODO Add this into a checkbox for a toggle in the test menu.

TestEvents::TestEvents()
{

}

/// <summary>
/// Kill the player if they are aiming, this didn't work.
/// </summary>
void TestEvents::KillPlayerIfAiming()
{
#ifdef _CHAOS_MODE
    CPlayerPed* player = FindPlayerPed();
    CPed* playerPed = reinterpret_cast<CPlayerPed*>(player);

    if (playerPed->m_nPedFlags.bIsAimingGun) 
    {
        player->m_fHealth = 0;
        player->m_fArmour = 0;
        Util::SetMessage("You have been exterminated!");
    }

#endif //CHAOS_MODE
}

/// <summary>
/// Event that blows up the player if they are drowning.
/// This just constantly blows up the player if they are in the water, not even if they are drowning.
/// </summary>
void TestEvents::DrowningExplosionEvent() 

{
#ifdef _CHAOS_MODE
    CPlayerPed* player = FindPlayerPed();

    // Oh wow this actually worked!
    CPed* playerPed = reinterpret_cast<CPlayerPed*>(player);
    //CPhysical* cPhysical = new CPhysical(player);

    // This spawns too many bombs, sometimes hurts the player when they respawn, I wonder how to fix that.
    if (playerPed->m_nPedFlags.bIsDrowning)
    {
        PlayerFunctions::SpawnBombOnPlayer();
    }

    //playerPed->m_nPedFlags.
    

    //player->m_b
    //if(player->)
#endif //CHAOS_MODE
}

void CanNotExitCar() 
{
    CPlayerPed* player = FindPlayerPed();
    CPed* playerPed = reinterpret_cast<CPlayerPed*>(player);
    playerPed->m_nPedFlags.bCanExitCar = false;
}

void KillPlayerInVehicle()
{
    // Blow up the player if they enter a car and don't let them escape.. How evil!
    if (PlayerFunctions::IsPlayerInVehicle())
    {
        PlayerFunctions::SpawnBombOnPlayer();
        // Set it to where the player cannot exit the vehicle.
        //CanNotExitCar();
    }
}

void KillPlayerInMiddleOfMap() 
{
    PlayerFunctions* playerFunctions = new PlayerFunctions();
    CPlayerPed* player = FindPlayerPed();
#ifdef GTASA

    CVector coords1 = CVector(2, 2, 2);
    CVector coords2 = CVector(20, 20, 20);
    if (playerFunctions->IsPlayerInArea(coords1.x, coords1.y, coords1.z, coords2.x, coords2.y, coords2.z))
    {
        playerFunctions->KillPlayer();
        // This just spams the screen, I wonder how to check if they died or update a value
        if (!player->IsAlive()) {
            Util::SetMessage("You have been exterminated!");
        }
        //Util::SetMessage("Hello");
    }
#endif //GTASA
}



// This seems to work in this class.
//#define _CHAOS_MODE
void TestEvents::ChaosModeEvent() 
{

    // Put this outside of the preprocessors here so the preprocessors don't comment it out.
    PlayerFunctions* playerFunctions = new PlayerFunctions();
    CPlayerPed* player = FindPlayerPed();

    

    //if(PlayerFunctions::m_bRespawnMiddleOfMap)
    // This doesn't seem to toggle it on/off properly
#ifdef _TEST
    if (playerFunctions->m_bRespawnMiddleOfMap)
    {
        Command<Commands::OVERRIDE_NEXT_RESTART>(22.0, 22.0, 2.0, 20.0);
    }
    // Quick test, this will always run and cancel it all the time most likely.
    else
    {
        Command<Commands::CANCEL_OVERRIDE_RESTART>();
    }
#endif //TEST
    // This seems to work fine, idk if it'll crash the game though.
//#ifdef _TEST
//    Command<Commands::OVERRIDE_NEXT_RESTART>(22.0, 22.0, 2.0, 20.0);
//#endif //_TEST
#ifdef _CHAOS_MODE
    // 6-18-2024 @ 3:37AM
    // I figured out how to get timers working on here, this is running in Events::gameProcessEvent in cheatmenu.cpp
    // This does work. Copied from overlay.cpp on lines 429-432
    size_t game_ms = CTimer::m_snTimeInMilliseconds;
    static size_t interval = 0;

    // Add test timer for this, this works!
    if (game_ms - interval > 1000) {
        //
        KillPlayerInVehicle();
        interval = game_ms;
    }
    
    KillPlayerInMiddleOfMap();

#endif //_CHAOS_MODE
}
