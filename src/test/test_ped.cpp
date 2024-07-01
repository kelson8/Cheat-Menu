#include "pch.h"
#include "test_ped.h"
#include "utils/widget.h"

#ifdef GTASA
#include "CExplosion.h"
#include "CPopulation.h"
#include "CTaskComplexWanderStandard.h"
#include "CSprite.h"
#endif

// My code
#include "functions/player_functions.h"
#include "../enums/audio_ids.h"
#include "functions/vehicle_functions.h"
#include "functions/ped_functions.h"


// Incomplete.
// https://library.sannybuilder.com/#/sa/default/0672
//Command<Commands::TASK_DESTROY_CAR>(pPed);

// This might be fun to mess with if I can figure out how to use the stats
//player->m_pStats;

// Try to mess with the values in this enum and play sounds: eAudioEvents


PedTestPage::PedTestPage()
{

}

bool playerCanDrown = true;

//static std::vector<int> soundIds = {
AudioIds* audioIds = new AudioIds();

static std::vector<std::string> soundIds = {
    std::to_string(AudioIds::BLANK_SOUND), std::to_string(AudioIds::CRASH_SOUND), std::to_string(AudioIds::GARAGE_DOOR_OPENING),
    std::to_string(AudioIds::SELECTION_SOUND), std::to_string(AudioIds::METALLIC_FENCE_RATTLE1),
    std::to_string(AudioIds::METALLIC_FENCE_RATTLE2), std::to_string(AudioIds::SPRAY_CAN),
    std::to_string(AudioIds::CRASH1_SOUND), std::to_string(AudioIds::CRASH2_SOUND), std::to_string(AudioIds::THROW_SATCHEL_SOUND), std::to_string(AudioIds::CAR_HORN),
    std::to_string(AudioIds::BLIP_SOUND), std::to_string(AudioIds::EXPLOSION_SOUND),
    std::to_string(AudioIds::HANGER_DOORS), std::to_string(AudioIds::DRIVING_SCHOOL_RESULTS_MUSIC),
    std::to_string(AudioIds::BIKE_BOAT_SCHOOL_RESULTS_MUSIC), std::to_string(AudioIds::FLIGHT_SCHOOL_RESULTS_MUSIC)
};

//static std::vector<int> soundIds = {
//    BLANK_SOUND, CRASH_SOUND, GARAGE_DOOR_OPENING, SELECTION_SOUND,
//    METALLIC_FENCE_RATTLE1, METALLIC_FENCE_RATTLE2, SPRAY_CAN,
//    CRASH1_SOUND, CRASH2_SOUND, THROW_SATCHEL_SOUND, CAR_HORN,
//    BLIP_SOUND, EXPLOSION_SOUND, HANGER_DOORS, DRIVING_SCHOOL_RESULTS_MUSIC,
//    BIKE_BOAT_SCHOOL_RESULTS_MUSIC, FLIGHT_SCHOOL_RESULTS_MUSIC
//};

static void SuicideMenu() 
{
#ifdef GTASA
    CPlayerPed* player = FindPlayerPed();
    if (ImGui::Button("Suicide"))
    {
        CPlayerPed* player = FindPlayerPed();
        int hplayer = CPools::GetPedRef(player);
        Command<Commands::EXPLODE_CHAR_HEAD>(hplayer);
    }
#else
    CPlayerPed* player = FindPlayerPed();
#endif //GTASA
}

// Why does this not have sound? I'm not using ADD_EXPLOSION_NO_SOUND
// I manually added an explosion using ADD_ONE_OFF_SOUND
static void BombMenu()
{
#ifdef GTASA
    CPlayerPed* player = FindPlayerPed();
    //TODO Test these in the other games, 3 and vc later!
    if (ImGui::Button("Bomb")) {
        CPlayerPed* player = FindPlayerPed();
        int hplayer = CPools::GetPedRef(player);

        CVector playerPos = player->GetPosition();

        // https://library.sannybuilder.com/#/sa/default/020C
        // x, y, z, EXPLOSION_CAR
        Command<Commands::ADD_EXPLOSION>(playerPos.x, playerPos.y, playerPos.z, EXPLOSION_CAR);

        // https://library.sannybuilder.com/#/sa/default/018C
        // These might work: https://sampwiki.blast.hk/wiki/SoundID
        // 
        // Working
        //Command<Commands::ADD_ONE_OFF_SOUND>(playerPos.x, playerPos.y, playerPos.z, AudioIds::EXPLOSION_SOUND);
        // 
        // 

        // This works like this.
        PlayerFunctions::AddSoundOnPlayer(AudioIds::EXPLOSION_SOUND);

        // This does about the same as above with a bit more code.
        //CExplosion::AddExplosion(FindPlayerPed(), FindPlayerPed(), EXPLOSION_CAR, playerPos, 1000, 1, 1.0f, true);
    }
#endif //GTASA
}

static void TestSoundMenu()
{
    // GTA SA specific sounds.
#ifdef GTASA
    
#endif //GTASA
}

// New

#define _TEST
// Sound testing, incomplete.
#ifdef _TEST
// Set this to nothing
int defaultSoundType = 0;
static void SoundMenu()
{
#ifdef GTASA
    CPlayerPed* player = FindPlayerPed();
    CVector playerPos = player->GetPosition();
    ImGui::Text("Sound");
    // Not sure how to get a list box to play each sound with a button under.
    // This is complaining, I guess because I gave it an int instead of string.

    // This doesn't seem to work
    if (Widget::ListBox("Sounds", soundIds, defaultSoundType))
        defaultSoundType = defaultSoundType;
    //if (ImGui::ListBox("Sounds", soundIds, defaultSoundType))
    {
        if (ImGui::Button("Play sound")) {
            Command<Commands::ADD_ONE_OFF_SOUND>(playerPos.x, playerPos.y, playerPos.z, defaultSoundType);
        }
    }

    // This might work:
    // https://stackoverflow.com/questions/10847237/how-to-convert-from-int-to-char
    //const char* soundIdsChar = char(soundIds);

    // Will these work? I think this is converting the int to a char.
    // https://stackoverflow.com/questions/4254615/how-to-cast-vectorunsigned-char-to-char
    //reinterpret_cast<char*> (soundIds[0]);

    // Now to create a for loop
    // Will this work for the int?
    //for (int i = 0; i < soundIds.size(); i++) 
    //{
    //    const char* soundIdsChars = reinterpret_cast<char*> (soundIds[i]);
    //    
    //    if (Widget::ListBox("Sounds", soundIds, defaultSoundType))
    //    //if (ImGui::ListBox("Sounds", soundIds, defaultSoundType))
    //    {

    //    }
    //}

#endif //GTASA
}

#endif //_TEST

static void ShowCoordsMenu()
{
#ifdef GTASA
    CPlayerPed* player = FindPlayerPed();
    if (ImGui::Button("Show coords"))
    {
        CVector playerCoords = player->GetPosition();
        //std::string text = std::to_string(pos.x) + ", " + std::to_string(pos.y) + ", " + std::to_string(pos.z);
        //int playerX = playerCoords.x;
        //int playerY = playerCoords.y;
        //int playerZ = playerCoords.z;

        std::string playerX = std::to_string(playerCoords.x);
        std::string playerY = std::to_string(playerCoords.y);
        std::string playerZ = std::to_string(playerCoords.z);

        // This works for showing just the X coord, I cannot concatenate these values though
        //Util::SetMessage(playerXChar);
        // Taken idea from freecam_sa.cpp on line 156
        // This works!!
        // 6-14-2024 @ 2:34PM
        Util::SetMessage(std::format("X: {} Y: {} Z: {}", playerX, playerY, playerZ).c_str());
    }
#endif //GTASA
}

static void ShowMarkerCoordsMenu()
{
#ifdef GTASA
    CPlayerPed* player = FindPlayerPed();

    if (ImGui::Button("Show Marker Coords"))
    {
        Util::SetMessage("Not implemented yet!");

    //    if (Command<Commands::DOES_BLIP_EXIST>())
    //    {
    //        // Check if the target marker blip exists and print the coords if so, looks like this function is only available in cleo.
    //        // GET_TARGET_BLIP_COORDS
    //        //if()
    //    }
    //    //Command<Commands::BLIP>(playerPos.x, playerPos.y, playerPos.z, EXPLOSION_CAR);

    }
#else
    Util::SetMessage("No markers in VC or 3!");
#endif //GTASA
}

static void TogglePlayerDrownMenu() 
{
#ifdef GTASA
    CPlayerPed* player = FindPlayerPed();
    // This seems to work fine.
    if (ImGui::Checkbox("Player drowns", &playerCanDrown))
    {
        int hPlayer = CPools::GetPedRef(player);
        if (!playerCanDrown) {
            Command<Commands::SET_CHAR_DROWNS_IN_WATER>(hPlayer, false);
            Util::SetMessage("You can no longer drown!");
        }
        else
        {
            Command<Commands::SET_CHAR_DROWNS_IN_WATER>(hPlayer, true);
            Util::SetMessage("You can now drown again!");
        }
    }
#endif //GTASA
    
}

static void GravityValuesMenu()
{
#ifdef GTASA
    CPlayerPed* player = FindPlayerPed();
        ImGui::Separator();
        ImGui::Text("Gravity Values");
        //ImGui::Columns(4);
    
        if (ImGui::Button("Space Gravity")) {
            GAME_GRAVITY = 0.0;
            Util::SetMessage("Gravity set to space.");
        }
    
        ImGui::SameLine();
        if (ImGui::Button("Moon Gravity")) {
            GAME_GRAVITY = 0.001;
            Util::SetMessage("Gravity set to moon.");
        }
    
        ImGui::SameLine();
        if (ImGui::Button("Normal Gravity")) {
            GAME_GRAVITY = 0.008;
            Util::SetMessage("Gravity set to normal.");
        }
    
        ImGui::Separator();
        if (ImGui::Button("Strong Gravity")) {
            GAME_GRAVITY = 0.015;
            Util::SetMessage("Gravity set to strong.");
        }
    
        ImGui::SameLine();
        if (ImGui::Button("Maniac Gravity")) {
            GAME_GRAVITY = 0.9;
            Util::SetMessage("Gravity set to maniac. Chaos will occur!");
        }
#endif //GTASA
}

void PedTestPage::InsaneGravity()
{
    // Make game timer,
    // Toggle gravity from Maniac to Normal
    float maniacGravity = 0.9;
    float normalGravity = 0.008;

    size_t game_ms = CTimer::m_snTimeInMilliseconds;
    static size_t interval = 0;
    if (game_ms - interval > 10000) {
        //
        if (GAME_GRAVITY = normalGravity) 
        {
            GAME_GRAVITY = maniacGravity;
            interval = game_ms;
        }
    }
}

void PedTestPage::NormalGravity()
{
    float maniacGravity = 0.9;
    float normalGravity = 0.008;

    size_t game_ms = CTimer::m_snTimeInMilliseconds;
    static size_t interval = 0;
    if (game_ms - interval > 5000) {
        //
        if (GAME_GRAVITY = maniacGravity)
        {
            GAME_GRAVITY = normalGravity;
            interval = game_ms;
        }
    }
}

// I couldn't get this working.
#ifdef _TEST1
#ifdef GTASA
static void SpawnRandomCopPed()
{
    //CVehicle* cVehicle = nullptr;
    CPlayerPed* player = FindPlayerPed();
    // Taken from plugin-sdk examples under PedSpawner in Main.cpp
    // https://github.com/DK22Pac/plugin-sdk/blob/master/examples/PedSpawner/Main.cpp
    // Cop Ped
    int copRandModelID = copModelIds[rand() % 250]; // Random model id
    CStreaming::RequestModel(copRandModelID, 0); // Request the model
    CStreaming::LoadAllRequestedModels(false); // Whatever this does.
    //CPed* ped = new CCivilianPed(CPopulation::IsFemale(modelID) ? PED_TYPE_CIVFEMALE : PED_TYPE_CIVMALE, modelID);
    //CPed* ped = new CCivilianPed(CPopulation::IsFemale(modelID) ? PED_TYPE_CIVFEMALE : PED_TYPE_CIVMALE, modelID);


    // Vehicle
    //CVehicle *vehicle = new CVehicle();
    CVehicle* SpawnVehicle(unsigned int modelIndex, CVector position) 
    {

    }

    // This might be fun, have the cop run over the player.
    CCopPed* copPed = new CCopPed(copRandModelID);

    //CVehicle* cVehicle = new CVehicle(MODEL_DODO);

    copPed->KillPedWithCar();
    CStreaming::SetModelIsDeletable(copRandModelID);
 
}
#endif //GTASA

#endif //_TEST1

static void SpawnPedMenu()
{
    if (ImGui::Button("Spawn Ped")) {
        //SpawnRandomPed();
        // Moved this into PedFunctions.
        PedFunctions::SpawnRandomPed();
    }

#ifdef _TEST1
    if (ImGui::Button("Spawn Random Cop ped")) 
    {
        SpawnRandomCopPed();
    }
#endif //_TEST1
    

}

//#endif //GTASA



static void AreaCheckTestMenu()
{
    CVector testLocationArea1 = CVector(2, 2, 2);
    CVector testLocationArea2 = CVector(20, 20, 20);

    ImGui::Text("Area Check testing.");
    if (ImGui::Button("Check Area #1")) {
        bool isPlayerInArea = PlayerFunctions::IsPlayerInArea(testLocationArea1.x, testLocationArea1.y, testLocationArea1.z, 
            testLocationArea2.x, testLocationArea2.y, testLocationArea2.z);

        if (isPlayerInArea) 
        {
            Util::SetMessage("You are in the zone.");
        }
        else
        {
            Util::SetMessage("You are not in the zone.");
        }
        //AreaCheckTest();
    }
}

/////////////


bool playerSprint = true;
static void MiscTestMenu()
{
#ifdef GTASA
    CPlayerPed* player = FindPlayerPed();
    // I'm not exactly sure what this is doing.
    int hplayer = CPools::GetPedRef(player);

    // https://library.sannybuilder.com/#/sa/default/06AF
    // This just crashes it.
//#define _TEST1
#ifdef _TEST1

    if (ImGui::Checkbox("Toggle running", &playerSprint)) 
    {
        if(!playerSprint)
        {
            Command<Commands::DISABLE_PLAYER_SPRINT>(hplayer, false);
            Util::SetMessage("You have disabled sprinting!");
        }
        else
        {
            Command<Commands::DISABLE_PLAYER_SPRINT>(hplayer, true);
            Util::SetMessage("You have enabled sprinting!");
        }
    }
#endif //GTASA

    if(ImGui::Button("Is player under car?"))
    {
        if (PlayerFunctions::IsPedStuckUnderCar()) {
            Util::SetMessage("You are being crushed!");
        } 
        else
        {
            Util::SetMessage("You are not under a car.");
        }
    }

    if (ImGui::Button("Add blip for current pos")) 
    {
        CVector playerPos = player->GetPosition();

        // This works
        //bool pos = Command<Commands::ADD_SPRITE_BLIP_FOR_COORD>(playerPos.x, playerPos.y, playerPos.z);
        // https://library.sannybuilder.com/#/sa/default/02A8
        // https://gtamods.com/wiki/Blip

        Command<Commands::ADD_SPRITE_BLIP_FOR_COORD>(playerPos.x, playerPos.y, playerPos.z, RADAR_SPRITE_AMMUGUN);


        // Test, didn't work
        //CSprite playerSprite = Command<Commands::ADD_SPRITE_BLIP_FOR_COORD>(playerPos.x, playerPos.y, playerPos.z, RADAR_SPRITE_AMMUGUN);

        // This doesn't seem to store the value or remove the blip.
        //bool blip = Command<Commands::ADD_SPRITE_BLIP_FOR_COORD>(playerPos.x, playerPos.y, playerPos.z, RADAR_SPRITE_AMMUGUN);
        //bool doesBlipExist = Command<Commands::DOES_BLIP_EXIST>(blip);
        ////if (blipPos) 
        //if (doesBlipExist) 
        //{
        //    Command<Commands::REMOVE_BLIP>(blip);
        //    Util::SetMessage("Removed current blip.");
        //}

    }

    if (ImGui::Button("Add blip for vehicle"))
    {
        CVehicle* pVeh = nullptr;
        

        if (PlayerFunctions::IsPlayerInVehicle()) {
            pVeh = player->m_pVehicle;
            Command<Commands::ADD_BLIP_FOR_CAR>(pVeh);
            Util::SetMessage("You have added a blip for your vehicle.");
        }

    }

    // I'm not sure how to remove these yet.
    if (ImGui::Button("Remove blip for vehicle"))
    {
        CVehicle* pVeh = nullptr;

        if (PlayerFunctions::IsPlayerInVehicle()) {
            pVeh = player->m_pVehicle;
            Command<Commands::REMOVE_BLIP>(pVeh);
            Util::SetMessage("You have removed a blip for your vehicle.");
        }
    }

#endif //_TEST1

}

static void KillPlayer()
{
    CPlayerPed* player = FindPlayerPed();
    player->m_fHealth = 0;
    player->m_fArmour = 0;
}


/// <summary>
/// Change the respawn point, possibly use an event to do this.
/// </summary>
static void TestChangeRespawnMenu()
{
    if (ImGui::Button("Set Respawn to 22,22,10")) 
    {
        // Needs the decimals or it doesn't work right.
        Command<Commands::OVERRIDE_NEXT_RESTART>(22.0, 22.0, 2.0, 20.0);
        Util::SetMessage("Respawn point set to middle of map.");
    }
    if (ImGui::Button("Fix respawn back to normal")) 
    {
        Command<Commands::CANCEL_OVERRIDE_RESTART>();
        Util::SetMessage("Reset respawn points.");
    }
}

// Will this work?
bool respawnMiddleOfMap;
static void SetRespawnMiddleOfMapMenu() 
{
    PlayerFunctions* playerFunctions = new PlayerFunctions();
    //if (ImGui::Checkbox("Respawn middle of map", &playerFunctions->m_bRespawnMiddleOfMap))
    if (ImGui::Checkbox("Respawn middle of map", &respawnMiddleOfMap))
    {
        //if (playerFunctions->m_bRespawnMiddleOfMap) {
        if (respawnMiddleOfMap) {
            playerFunctions->m_bRespawnMiddleOfMap = true;
            Util::SetMessage("You have enabled respawn at the middle of the map!");

        }
        else
        {
            playerFunctions->m_bRespawnMiddleOfMap = false;
            Util::SetMessage("Spawning reset to normal.");

        }
    }
    //if (ImGui::Checkbox("Respawn middle of map", &PlayerFunctions::m_bRespawnMiddleOfMap))
    //{
    //    if (PlayerFunctions::m_bRespawnMiddleOfMap) {
    //        PlayerFunctions::m_bRespawnMiddleOfMap = true;
    //        Util::SetMessage("You have enabled respawn at the middle of the map!");
    //    } 
    //    else
    //    {
    //        PlayerFunctions::m_bRespawnMiddleOfMap = false;
    //        Util::SetMessage("Spawning reset to normal.");
    //    }
    //}
    //if (ImGui::Button("Respawn middle of map")) 
    //{
    //    PlayerFunctions::m_bRespawnMiddleOfMap = true;
    //}
}


// Use Swat rope test, this is in the reversed gta sa project, I wonder if I can use it in the plugin-sdk?
// I don't know if it'll work with the player.
static void CreateSwatRopeOnPed()
{
#ifdef GTASA
    CPlayerPed* player = FindPlayerPed();
    int hplayer = CPools::GetPedRef(player);
    
    CVector playerCoords = player->GetPosition();

    //CVector testLocation = CVector(2, 2, 2);
    // Will this work?
    CVector testLocation = playerCoords;
    
    // Add some distance to the x and y so they don't spawn right on the player.
    // Z is the height, I'll leave it alone for now.
    testLocation.x = testLocation.x + 2;
    testLocation.y = testLocation.y + 2;

    // pedType, modelId, x, y, z
    // Ped male
    // Sweet
    Command<Commands::CREATE_SWAT_ROPE>(PED_TYPE_CIVMALE, 270, testLocation.x, testLocation.y, testLocation.z);
#endif //GTASA
}

//

// Untested
/// <summary>
/// Teleport to marker test, this seems to work but doesn't put the player on the ground.
/// </summary>

static void TeleportToMarkerTest()
{
    // Idk what this below is doing but its defined in teleport.cpp.
    tRadarTrace* ms_RadarTrace = reinterpret_cast<tRadarTrace*>(patch::GetPointer(0x5838B0 + 2));
    CPlayerPed* player = FindPlayerPed();
    int hplayer = CPools::GetPedRef(player);
    CVector playerPos = player->GetPosition();

    //Test
    CEntity* pPlayerEntity = FindPlayerEntity(-1);

    tRadarTrace targetBlip = ms_RadarTrace[LOWORD(FrontEndMenuManager.m_nTargetBlipIndex)];
    if (targetBlip.m_nRadarSprite != RADAR_SPRITE_WAYPOINT)
    {
        Util::SetMessage(TEXT("Teleport.TargetBlipText"));
        return;
    }
    
    // I don't know how to get the location of the current marker.
    // This should place the player on the ground.
    // This doesn't work.
#ifdef _TEST1
    float ground, water;
    CEntity* pPlayerEntity = FindPlayerEntity(-1);
    ground = CWorld::FindGroundZFor3DCoord(playerPos.x, playerPos.y, 1000, nullptr, &pPlayerEntity) + 1.0f;

    Command<Commands::GET_WATER_HEIGHT_AT_COORDS>(playerPos.x, playerPos.y, true, &water);
    playerPos.z = ground > water ? ground : water;

#endif //_TEST1
    player->SetPosn(targetBlip.m_vecPos);

}

static void TeleportTestMenu()
{
    if (ImGui::Button("Teleport to marker"))
    {
        // I don't think this'll work.
        TeleportToMarkerTest();
    }
}

void PedTest()
{
    ImGui::Text("Find unsuspecting target ped");
    if(ImGui::Button("Test #1"))
    {
        //CWorld::FindUnsuspectingTargetPed();
    }

    ImGui::Text("Clear peds and everything in area");
    if (ImGui::Button("Test #2")) 
    {
        CPlayerPed* player = FindPlayerPed();
        CWorld::ClearExcitingStuffFromArea(player->GetPosition(), 20, true);
        Util::SetMessage("Killed everything in the area!");
    }

    // This didn't seem to work
    ImGui::Text("Start a fire in your area");
    if (ImGui::Button("Test #3"))
    {
        CPlayerPed* player = FindPlayerPed();
        CEntity* playerEntity = FindPlayerEntity(-1);

        CVector playerPos = player->GetPosition();
        CWorld::SetWorldOnFire(playerPos.x, playerPos.y, playerPos.z, 20, playerEntity);
    }

}



/// <summary>
/// Main code for PlayerTestMenu
/// </summary>
void PedTestPage::PlayerTestMenu() 
{

    //Events::initGameEvent += [this]()
    //    {

    //    };

    Events::processScriptsEvent += [this]()
    //Events::gameProcessEvent += [this]()
        {
            // Well this just spams the text and doesn't stop the noises when in the area.
            // Moved KillPlayer and other chaos mode functions into player_functions.cpp.
            // Moved the event into cheatmenu.cpp.
        };

    SuicideMenu();
    BombMenu();
    ShowCoordsMenu();
    ShowMarkerCoordsMenu();
    TogglePlayerDrownMenu();
    GravityValuesMenu();
    ImGui::Separator();

    // Test features
#ifdef _TEST
    SoundMenu();
    ImGui::Separator();
#ifdef GTASA
    SpawnPedMenu();

    // New
    // Respawn stuff
    TestChangeRespawnMenu();
    SetRespawnMiddleOfMapMenu();

    TeleportTestMenu();

#endif //GTASA
    // I could probably set this to activate when the player goes into it and send a message saying you are in the zone.
    AreaCheckTestMenu();

    MiscTestMenu();

    PedTest();
#endif //TEST
    
}