#include "pch.h"
#include "test.h"
//#include <CPopulation.h>
//#include <CDamageManager.h>
//#include "pages/menu.h"
//#include "pages/teleport.h"
//#include "utils/widget.h"
//#include "utils/util.h"
//#include "custom/filehandler.h"
//#include "custom/vehcustmzr.h"
//#include "custom/autodrive.h"
//#include <CMatrix.h>

/*
    This file has been created by kelson8, thanks to Grinch for the GPLV3 license to mess around with the code.
    If you like my work, please check out the original author and the page for this code from the link below:
    I have been using this project to learn more C++.
    https://github.com/user-grinch/Cheat-Menu
*/

// TODO Move this into my own menu named KCNet-SAMenu, possibly try to make it work on Vice City and 3.


// TODO Figure out how to get the coordniates of where the player is looking at, I think that should be possible.
// TODO Try to get this working on VC and 3 sometime, the menu normally works on those games I would just have to make sure I don't have any SA specific 
//  memory addresses or anything in it.

// Well this was working with the Visual Studio 2022 debugger now it says cannot find gta_sa.exe or gta-vc.exe.
// It still seems to work if I launch the games directly though.

// 6-17-2024 @ 2:51AM
// I fixed it to work with the Visual Studio 2022 debugger again
// Useful functions:
// Force all cars to be the specified model: https://library.sannybuilder.com/#/sa/default/09BF
// Set ped density multiplier: https://library.sannybuilder.com/#/sa/default/03DE
// Set ped vehicle multipler: https://library.sannybuilder.com/#/sa/default/01EB
// 

// This guide might be useful:
// https://www.open.mp/docs/tutorials/PluginDevelopmentGuide


#ifdef GTASA
#include "CExplosion.h"
// New
#include "C3dMarker.h"
#include "C3dMarkers.h"
#include "CWorld.h"

// Vehicle
#include "CCarAI.h"
#include "CCarCtrl.h"
#include "CCarEnterExit.h"
#include "CHeli.h"

//Misc
#include "CCheat.h"
#include "CCoronas.h"
#include "CPickup.h"
#include "CPickups.h"
#include "CWeather.h"
#include "CCheckpoints.h"
#include "CGarages.h"

//Test
#include "CGame.h"
#include "CWaterLevel.h"
#include "CWeather.h"

// Radio Test
#include "CAERadioTrackManager.h"
#include "CAudioEngine.h"
// I can disable the radio and change its type using this
#include "CAEVehicleAudioEntity.h"

#endif

#define _TEST
// I wonder how to get this test menu to show up.
// This breaks the menu.
#ifdef _TEST

#include <iostream>
#include <cstring>
#include "pages/vehicle.h"
#include "utils/widget.h"
#include "utils/util.h"
#include "pages/ped.h"

// My code
#include "test_vehicle.h"
#include "test_hud.h"
#include "test_ped.h"
#include "test_world.h"
#include "functions/player_functions.h"
#include "functions/vehicle_functions.h"

// Well I had this working but then broke it 6-14-2024 @ 3:51PM...
// I fixed it 3:53PM.

// TODO Fix this to use translations from the English.toml file instead of hardcoding the values.
// TODO Seperate these out into multiple tabs within my test tab, so have a Player, Vehicle, Sounds, World, Misc, Test Features and more tabs.

TestPage& testPage = TestPage::Get();
TestPage::TestPage()
	: IPage<TestPage>(ePageID::Test, "Window.TestPage", true) {

}

// Booleans
bool test = false;
bool enterCrane = false;
bool toggleRadio = true;

//void TestPage::PlayerTest() {
//    CPlayerPed* player = FindPlayerPed();
//    int hplayer = CPools::GetPedRef(player);
//    bool isInAir = Command<Commands::IS_CHAR_IN_AIR>(hplayer);
//}


/// <summary>
/// Train test functions.
/// </summary>
static void TrainTestMenu()
{
    
    ImGui::Text("Train testing.");
    // This works.
    if (ImGui::Button("Are you in a train?")) 
    {
        if (PlayerFunctions::IsPlayerInTrain()) 
        {
            Util::SetMessage("You are in a train.");
        }
        else
        {
            Util::SetMessage("You are not in a train.");
        }
    }
}

void PlayerTestFeatures() 
{
    CPlayerPed* player = FindPlayerPed();

    // Not sure how to get the garage id.
    // TODO
    // 
    // Work on messing with garages
    // https://library.sannybuilder.com/#/sa/classes/Garage
    // 
    // Work on adding objects using code
    // Add pickups such as money, health, mines, bombs.
    // 
    // Get, add to and decrement stats.
    // https://library.sannybuilder.com/#/sa/classes/Stat
    // https://gtamods.com/wiki/List_of_statistics_(SA)

    // Mess around with tasks
    // https://library.sannybuilder.com/#/sa/classes/Task

    // Weather
    // https://library.sannybuilder.com/#/sa/classes/Weather

    // World
    // https://library.sannybuilder.com/#/sa/classes/World

    // Zone
    // https://library.sannybuilder.com/#/sa/classes/Zone



    int hplayer = CPools::GetPedRef(player);
    CVehicle* pVeh = nullptr;
    CVector pos = player->GetPosition();
}


void TestPage::Draw()
{
    // I am testing moving everything from static to not using static.
#ifdef _TEST
    // Init for the menu
    WorldTestPage* worldTestPage = new WorldTestPage();
    HudTestPage* hudTestPage = new HudTestPage();
    PedTestPage* pedTestPage = new PedTestPage();
    VehicleTestPage* vehicleTestPage = new VehicleTestPage();

    // Misc items
#ifdef GTASA
    CAERadioTrackManager* cAERadioTrackManager = new CAERadioTrackManager();
    CAudioEngine* cAudioEngine = new CAudioEngine();
    CAEVehicleAudioEntity* cAEVehicleAudioEntity = new CAEVehicleAudioEntity();
#endif // GTASA
#endif //_TEST
    CPlayerPed* player = FindPlayerPed();
    //ImGui::BeginChild("Test");

    // Test
    ImGui::Text("Hello from KCNet");

    if (ImGui::BeginTabBar("Test", ImGuiTabBarFlags_NoTooltip + ImGuiTabBarFlags_FittingPolicyScroll))
    {
        
        ImGui::Separator();
        if (ImGui::BeginTabItem(TEXT("Test.TestVehicle")))
        {
            // This works for seperating out the menus!
            // 6-15-2024 @ 2:05PM
            //ImGui::Text("Hello from KCNet");
            ImGui::Text("Vehicle Tab");
            vehicleTestPage->VehicleTestMenu();
            ImGui::EndTabItem();
        }

        // TEXT(Test.TestPlayerMenu) - Test Player Menu
        if (ImGui::BeginTabItem("Player"))
        {
            // Incomplete
#ifdef _TEST
            pedTestPage->PlayerTestMenu();
#else
            PedTestPage::PlayerTestMenu();
#endif //_TEST
            

            // This is needed, I think it should fix a crash.
            ImGui::EndTabItem();
        }

        if (ImGui::BeginTabItem(TEXT("Test.TestFeatures")))
        {
            // Incomplete
            /*PedTestPage::PlayerTestMenu();*/

            //if (ImGui::Button("Show Marker Coords"))
            //{

            //    if (Command<Commands::DOES_BLIP_EXIST>())
            //    {
            //        // Check if the target marker blip exists and print the coords if so, looks like this function is only available in cleo.
            //        // GET_TARGET_BLIP_COORDS
            //        //if()
            //    }
            //    //Command<Commands::BLIP>(playerPos.x, playerPos.y, playerPos.z, EXPLOSION_CAR);

            //}
            //ImGui::Columns(2, NULL, false);

#ifdef GTASA
            //ImGui::NextColumn();
            // https://github.com/JuniorDjjr/CLEOPlus/blob/main/CLEOPlus/Misc.cpp#L261-L266
            // reinterpret_cast<CRunningScript*>(thread)->UpdateCompareFlag(CCheat::m_aCheatsActive[i]);


            // I wonder how to spawn a different pickup
            if (ImGui::Button("Health pickup"))
            {
                CVector playerPos = player->GetPosition();
                int playerX = playerPos.x;
                int playerY = playerPos.y;
                int playerZ = playerPos.z;

                // Needs some more arguments.
                //CPickup::GiveUsAPickUpObject(CObject::, -1);
                //CPickups::CreatePickupCoorsCloseToCoors(playerPos.x, playerPos.y, playerPos.z);
            }
            //ImGui::SameLine();

            ImGui::Text("Spawn 50k near your position");
            if (ImGui::Button("Money pickup"))
            {
                CVector playerPos = player->GetPosition();
                CVector newPos = CVector(playerPos.x + 3, playerPos.y + 3, playerPos.z);

                CPickups::CreateSomeMoney(newPos, 50000);
                Util::SetMessage("You have spawned 50k near you!");
            }
            ImGui::Separator();

            // Not sure how these work.
            // https://library.sannybuilder.com/#/sa/classes/Crane
            if (ImGui::Checkbox("Enter Crane", &enterCrane))
            {
                if (enterCrane)
                {
                    // https://library.sannybuilder.com/#/sa/default/079D
                    Command<Commands::PLAYER_ENTERED_DOCK_CRANE>();
                }
                else
                {
                    // https://library.sannybuilder.com/#/sa/default/079F
                    Command<Commands::PLAYER_LEFT_CRANE>();
                }
            }

            // This works
            if (ImGui::Button("Play Mission Passed"))
            {
                // https://library.sannybuilder.com/#/sa/default/0394
                
                Command<Commands::PLAY_MISSION_PASSED_TUNE>(1);
                //bool isFlyingActive = CCheat::m_aCheatsActive);
                //Util::SetMessage(std::format("Is Flying Active: {}", isFlyingActive).c_str());
            }

            // Move into vehicle functions.
            if (ImGui::Button("Current Radio Station"))
            {
                int hplayer = CPools::GetPedRef(player);
                CVehicle* pVeh = nullptr;
                bool bInVehicle = Command<Commands::IS_CHAR_IN_ANY_CAR>(hplayer);

                if (bInVehicle) {
                    CVehicle* pVeh = player->m_pVehicle;
                    if (cAERadioTrackManager->IsVehicleRadioActive())
                    {
                        // How would I set this to get the current radio station?
                        // I'll just use the command version of it for now instead of the cAERadioTrackManager


                        // Wow this works fine, I noticed the method was using char* so I decided to put it into it's own field.
                        const char* currentRadioStationName = cAERadioTrackManager->GetRadioStationName(cAudioEngine->GetCurrentRadioStationID());
                        //int radioChannel = 0;
                        //Command<Commands::GET_RADIO_CHANNEL>();

                        //Util::SetMessage(cAERadioTrackManager->GetRadioStationName(Command<Commands::GET_RADIO_CHANNEL>()));
                        // This works!! I figured it out
                        // 6-17-2024 @ 12:27AM
                        //Util::SetMessage(cAERadioTrackManager->GetRadioStationName(cAudioEngine->GetCurrentRadioStationID()));
                        Util::SetMessage(currentRadioStationName);
                        
                        //
                    }   
                }
            }

            //////
            // New
            ImGui::Separator();

            ImGui::Text("In game clock");


            //if (ImGui::Button("Show mili Seconds?")) 
            //{
            //    short currentGameSeconds = CClock::ms_nGameClockSeconds;
            //    Util::SetMessage(std::format("ms {}", currentGameSeconds).c_str());
            //}

            if (ImGui::Button("Show hours")) 
            {
                short currentGameHours = CClock::ms_nGameClockHours;
                Util::SetMessage(std::format("Hour: {}", currentGameHours).c_str());
            }

            if (ImGui::Button("Show Minutes"))
            {
                short currentGameMinutes = CClock::ms_nGameClockMinutes;
                Util::SetMessage(std::format("Minute: {}", currentGameMinutes).c_str());
            }

            // Train Menu
            TrainTestMenu();
            //////

            // Clothes

#endif
            ImGui::EndTabItem();
        }


// Hud menu and Hud functions.
// Comment out this define if this crashes.
#ifdef _TEST
        if (ImGui::BeginTabItem("Hud")) {
            hudTestPage->HudTestMenu();
            ImGui::EndTabItem();
        }
    #else
            HudTestPage::HudTestMenu();
#endif //_TEST


// World Menu & World Functions
#ifdef _TEST
    
    if (ImGui::BeginTabItem("World")) {
        worldTestPage->WorldTestMenu();
        ImGui::EndTabItem();
    // Use original code.
#else
        WorldTestPage::WorldTestMenu();
#endif //TEST
        }
    ImGui::EndTabBar();
    }
    
}
#endif //_TEST
