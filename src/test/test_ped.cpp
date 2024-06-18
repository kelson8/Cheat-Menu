#include "pch.h"
#include "test_ped.h"
#include "utils/widget.h"

#ifdef GTASA
#include "CExplosion.h"
#include "CPopulation.h"
#include "CTaskComplexWanderStandard.h"
#endif

// My code
#include "functions/player_functions.h"
#include "../enums/audio_ids.h"

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

// Taken from plugin-sdk examples under PedSpawner in Main.cpp
int pedModelIds[] = { 0, 7, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 32, 33, 34, 35, 36, 37, 43, 44, 45, 46,
    47, 48, 49, 50, 51, 52, 57, 58, 59, 60, 61, 62, 66, 67, 68, 70, 71, 72, 73, 78, 79, 80, 81, 82, 83, 84, 94, 95, 96, 97, 98, 99, 100, 101,
    102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 120, 121, 122, 123, 124, 125, 126, 127, 128, 132,
    133, 134, 135, 136, 137, 142, 143, 144, 146, 147, 153, 154, 155, 156, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 170, 171,
    173, 174, 175, 176, 177, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 200, 202, 203, 204, 206, 209, 210, 212, 213, 217, 220,
    221, 222, 223, 227, 228, 229, 230, 234, 235, 236, 239, 240, 241, 242, 247, 248, 249, 250, 252, 253, 254, 255, 258, 259, 260, 261, 262,
    9, 10, 11, 12, 13, 31, 38, 39, 40, 41, 53, 54, 55, 56, 63, 64, 69, 75, 76, 77, 85, 87, 88, 89, 90, 91, 92, 93, 129, 130, 131, 138, 139,
    140, 141, 145, 148, 150, 151, 152, 157, 169, 172, 178, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 201, 205, 207, 211, 214, 215,
    216, 218, 219, 224, 225, 226, 231, 232, 233, 237, 238, 243, 244, 245, 246, 251, 256, 257, 263 };

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
        //Command<Commands::ADD_ONE_OFF_SOUND>(playerPos.x, playerPos.y, playerPos.z, 1159);
        Command<Commands::ADD_ONE_OFF_SOUND>(playerPos.x, playerPos.y, playerPos.z, AudioIds::EXPLOSION_SOUND);

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
        //Util::SetMessage("X: " + playerXChar + " Y: " + playerYChar + " Z: " + playerZChar);

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

// This should spawn a random ped.
#ifdef GTASA
static void SpawnRandomPed()
{
    CPlayerPed* player = FindPlayerPed();
    // Taken from plugin-sdk examples under PedSpawner in Main.cpp
    // https://github.com/DK22Pac/plugin-sdk/blob/master/examples/PedSpawner/Main.cpp
    int modelID = pedModelIds[rand() % 250]; // Random model id
    CStreaming::RequestModel(modelID, 0); // Request the model
    CStreaming::LoadAllRequestedModels(false); // Whatever this does.
    CPed* ped = new CCivilianPed(CPopulation::IsFemale(modelID) ? PED_TYPE_CIVFEMALE : PED_TYPE_CIVMALE, modelID);

    // New
    // Idk how this one works
    //ped->m_pIntelligence

    if (ped)
    {
        // Is this getting the offset for the coordinates?
        ped->SetPosn(FindPlayerPed()->TransformFromObjectSpace(CVector(0.0f, 5.0f, 3.0f)));
        ped->SetOrientation(0.0f, 0.0f, 0.0f);
        CWorld::Add(ped);
        ped->PositionAnyPedOutOfCollision();
        ped->m_pIntelligence->m_TaskMgr.SetTask(new CTaskComplexWanderStandard(4, rand() % 8, true), 4, false);
    }
}


static void SpawnPedMenu()
{
    if (ImGui::Button("Spawn Ped")) {
        SpawnRandomPed();
    }
    

}

#endif //GTASA



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

#endif //GTASA
    // I could probably set this to activate when the player goes into it and send a message saying you are in the zone.
    AreaCheckTestMenu();

    MiscTestMenu();
#endif //TEST
    
}