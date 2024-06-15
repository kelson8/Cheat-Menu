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


// Well this was working with the Visual Studio 2022 debugger now it says cannot find gta_sa.exe or gta-vc.exe.
// It still seems to work if I launch the games directly though.

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

// Well I had this working but then broke it 6-14-2024 @ 3:51PM...
// I fixed it 3:53PM.

// TODO Fix this to use translations from the English.toml file instead of hardcoding the values.

TestPage& testPage = TestPage::Get();
TestPage::TestPage()
	: IPage<TestPage>(ePageID::Test, "Window.TestPage", true) {

}



//void TestPage::PlayerTest() {
//    CPlayerPed* player = FindPlayerPed();
//    int hplayer = CPools::GetPedRef(player);
//    bool isInAir = Command<Commands::IS_CHAR_IN_AIR>(hplayer);
//}


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


bool test = false;
//bool toggleHud = true;
//bool toggleRadar = true;
bool enterCrane = false;
//bool playerCanDrown = true;

void TestPage::Draw()
{
    CPlayerPed* player = FindPlayerPed();
    //ImGui::BeginChild("Test");
    if (ImGui::BeginTabBar("Test", ImGuiTabBarFlags_NoTooltip + ImGuiTabBarFlags_FittingPolicyScroll))
    {
        if (ImGui::BeginTabItem(TEXT("Test.TestVehicle")))
        {
            // This works for seperating out the menus!
            // 6-15-2024 @ 2:05PM
            ImGui::Text("Hello from KCNet");
            ImGui::Text("Vehicle Tab");
            VehicleTestPage::VehicleTestMenu();
            //static int selected = Locale::GetCurrentLocaleIndex();
            //static std::vector<std::string>& vec = Locale::GetLocaleList();
            ImGui::EndTabItem();
        }

        if (ImGui::BeginTabItem(TEXT("Test.TestFeatures")))
        {
            // Incomplete
            PedTestPage::PlayerTestMenu();
            //
            //if (ImGui::Button("Suicide"))
            //{
            //    //CPlayerPed* player = FindPlayerPed();
            //    int hplayer = CPools::GetPedRef(player);
            //    Command<Commands::EXPLODE_CHAR_HEAD>(hplayer);
            //}

            //if (ImGui::Button("Bomb")) {
            //    CPlayerPed* player = FindPlayerPed();
            //    int hplayer = CPools::GetPedRef(player);

            //    CVector playerPos = player->GetPosition();

            //    // https://library.sannybuilder.com/#/sa/default/020C
            //    // x, y, z, EXPLOSION_CAR
            //    Command<Commands::ADD_EXPLOSION>(playerPos.x, playerPos.y, playerPos.z, EXPLOSION_CAR);
            //}

            //if (ImGui::Button("Show coords"))
            //{
            //    CVector playerCoords = player->GetPosition();
            //    //std::string text = std::to_string(pos.x) + ", " + std::to_string(pos.y) + ", " + std::to_string(pos.z);
            //    //int playerX = playerCoords.x;
            //    //int playerY = playerCoords.y;
            //    //int playerZ = playerCoords.z;

            //    std::string playerX = std::to_string(playerCoords.x);
            //    std::string playerY = std::to_string(playerCoords.y);
            //    std::string playerZ = std::to_string(playerCoords.z);

            //    // This works for showing just the X coord, I cannot concatenate these values though
            //    //Util::SetMessage(playerXChar);
            //    // Taken idea from freecam_sa.cpp on line 156
            //    // This works!!
            //    // 6-14-2024 @ 2:34PM
            //    Util::SetMessage(std::format("X: {} Y: {} Z: {}", playerX, playerY, playerZ).c_str());
            //    //Util::SetMessage("X: " + playerXChar + " Y: " + playerYChar + " Z: " + playerZChar);
            //}

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

            // Not sure how this one works
            //CCheckpoints::PlaceMarker();
            if (ImGui::Button("Create Checkpoint")) 
            {

            }
            ImGui::SameLine();
            ImGui::Text("Doesn't work!");

            if (ImGui::Button("Remove checkpoint"))
            {
            
            }
            ImGui::SameLine();
            ImGui::Text("Doesn't work!");

            // Hud functions
            HudTestPage::HudTestMenu();

            // Not sure how these work.
            // https://library.sannybuilder.com/#/sa/classes/Crane
            if (ImGui::Checkbox("Enter Crane", &enterCrane))
            {
                if(enterCrane)
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

            // This seems to work fine.
            //if (ImGui::Checkbox("Player drowns", &playerCanDrown))
            //{
            //    int hPlayer = CPools::GetPedRef(player);
            //    if (!playerCanDrown) {
            //        Command<Commands::SET_CHAR_DROWNS_IN_WATER>(hPlayer, false);
            //        Util::SetMessage("You can no longer drown!");
            //    }
            //    else
            //    {
            //        Command<Commands::SET_CHAR_DROWNS_IN_WATER>(hPlayer, true);
            //        Util::SetMessage("You can now drown again!");

            //    }
            //}

            // This works
            if (ImGui::Button("Play Mission Passed"))
            {
                // https://library.sannybuilder.com/#/sa/default/0394
                Command<Commands::PLAY_MISSION_PASSED_TUNE>(1);
                //bool isFlyingActive = CCheat::m_aCheatsActive);
                //Util::SetMessage(std::format("Is Flying Active: {}", isFlyingActive).c_str());
            }

            // Doesn't work
//            if (ImGui::Button("Show corona"))
//            {
           // I wonder How I would use this?
           // I would need to define it somehow
           //CCorona
           //CCoronas::RegisterCorona();
//            }

            /*
            * void PedPage::AddNewPed()
            Example for what i'm trying to do spawning in a ped.
                    Command<Commands::REQUEST_MODEL>(model);
                    Command<Commands::LOAD_ALL_MODELS_NOW>();
                    if (Command<Commands::IS_MODEL_AVAILABLE>(model))
            {
                std::string key = std::format("Custom.{} (Added)", name);
                m_PedData.m_pData->Set(key.c_str(), std::to_string(model));
                m_PedData.m_pData->Save();
                Util::SetMessage(TEXT("Ped.AddPedMSG"));
                Command<Commands::MARK_MODEL_AS_NO_LONGER_NEEDED>(model);
            }
            else
            {
                Util::SetMessage(TEXT("Vehicle.InvalidID"));
            }
            */

            // First request the model
            // Then load all models
            // Lastly check if the model is available.
            // If not say "Invalid model"

            // 
            //if (ImGui::Button("Spawn Ped"))
            //{
            //    //CPed* pPed = new CPed::;
            //    //CWaterLevel::
            //    //CWorld::Add()
            //}

            // Clothes

#endif

            //if (ImGui::Button("Spawn ped to attack vehicle"))
            //{
            //    Util::SetMessage("Not setup!");
            //}

            /*
            if (ImGui::CollapsingHeader("Spawner"))
            {
                // PedPage::AddNewPed
                // This doesn't work yet.
//#define _DISABLED_CODE
#ifdef _DISABLED_CODE
                static char name[8];
                static int model = 0;
                ImGui::InputTextWithHint(TEXT("Menu.Name"), "PEDNAME", name, 7);
                Widget::InputInt(TEXT("Ped.Model"), &model, 0, 999999);
                ImGui::Spacing();
                ImVec2 sz = Widget::CalcSize(2);
                if (ImGui::Button(TEXT("Ped.AddPed"), sz))
                {
                    Command<Commands::REQUEST_MODEL>(model);
                    Command<Commands::LOAD_ALL_MODELS_NOW>();
                    if (Command<Commands::IS_MODEL_AVAILABLE>(model))
                    {
                        std::string key = std::format("Custom.{} (Added)", name);
                        // This part doesn't want to work.
                        //m_PedData.m_pData->Set(key.c_str(), std::to_string(model));
                        pedPage.m_PedData.m_pData->Set(key.c_str(), std::to_string(model));
                        pedPage.m_PedData.m_pData->Save();
                        //
                        Util::SetMessage(TEXT("Ped.AddPedMSG"));
                        Command<Commands::MARK_MODEL_AS_NO_LONGER_NEEDED>(model);
                    }
                    else
                    {
                        Util::SetMessage(TEXT("Vehicle.InvalidID"));
                    }
                }
                ImGui::SameLine();
                if (ImGui::Button(TEXT("Ped.GetPlayerModel"), sz))
                {
                    model = FindPlayerPed()->m_nModelIndex;
                }
#endif //_DISABLED_CODE
                //

                // https://library.sannybuilder.com/#/sa/default/0672
                //Command<Commands::TASK_DESTROY_CAR>(pPed);

                } //End
            //ImGui::EndChild();

            *
            }


            // This seems to work for printing text, idea came from imgui_demo.cpp line 5819
            static char text[64] = "text";
            static int bufTest[2];

            if(ImGui::InputText("Test", text, IM_ARRAYSIZE(text)))

                // Not sure how to get this to work
            //if (ImGui::InputInt("Clock", bufTest, IM_ARRAYSIZE(bufTest)))
            {
                //CClock::ms_nGameClockHours = hours;
                //CClock::SetGameClock(hours)
            }

            if (ImGui::Button("Print Text"))
            {
                Util::SetMessage(text);
            }

            ImGui::Text("Test Items");
            //CWorld::
            */
            ImGui::EndTabItem();
        }

    //ImGui::EndChild();
            
            ImGui::EndTabBar();
    }
    
}



// This doesn't do anything yet, I would like to add a custom tab to the Cheat menu
#endif //_TEST


#ifdef _DISABLED_CODE
// These weren't needed, leaving here for future reference.
// //////////////
// https://www.geeksforgeeks.org/convert-string-char-array-cpp/
//const char* playerXChar = playerX.c_str();
//const char* playerYChar = playerY.c_str();
//const char* playerZChar = playerZ.c_str();
//const char* playerXTest = static_cast<char>(char_array);

//https://www.tutorialspoint.com/How-to-convert-an-std-string-to-const-char-or-char-in-Cplusplus
//const char* test = new char[playerCoords.x];
//

//https://cplusplus.com/forum/general/268793/
//const char* s = new[std::strlen(playerXChar) + std::strlen(playerYChar) + 1];

//https://stackoverflow.com/questions/347949/how-to-convert-a-stdstring-to-const-char-or-char
//
//const char* playerMessage = std::to_string(playerCoords.x) + ", " + std::to_string(playerCoords.y) + ", " + std::to_string(playerCoords.z);
//const char* playerMessage = std::to_string(playerXChar) + ", " + std::to_string(playerCoords.y) + ", " + std::to_string(playerCoords.z);
//const char* playerMessage(test);


//Util::SetMessage("X: " + *playerXChar);
//Util::SetMessage(std::to_string(playerCoords.x));
//Util::SetMessage(playerMessage);
//////////////////



// Old
/*
    if (ImGui::BeginTabBar("Test", ImGuiTabBarFlags_NoTooltip + ImGuiTabBarFlags_FittingPolicyScroll))
    {
        if (ImGui::BeginTabItem(TEXT("Test.TestVehicle")))
        {
            ImGui::Text("Vehicle Tab");
            //static int selected = Locale::GetCurrentLocaleIndex();
            //static std::vector<std::string>& vec = Locale::GetLocaleList();

            ImGui::Text("Hello from KCNet");
            //}
            ImGui::EndTabItem();
        }

            if (ImGui::BeginTabItem(TEXT("Test.TestFeatures")))
            {
                ImGui::Text("Test Features");
                //    ImGui::Text("Test Features");
                //    //if (ImGui::BeginChild("CommandsChild"))
                //    //{
                //    //    ImGui::Text("Hello from KCNet");
                //    //    //
                //    //    //if (ImGui::CollapsingHeader(TEXT("Menu.QuickVehSpawnerCMD")))
                //    //    //{
                //    //    //    ImGui::Spacing();
                //    //    //    ImGui::TextWrapped(TEXT("Menu.QuickVehSpawnerCMDText"));
                //    //    //    ImGui::Spacing();
                //    //    //    ImGui::Separator();
                //    //    //}
                //    //    //if (ImGui::CollapsingHeader(TEXT("Menu.QuickWepSpawnerCMD")))
                //    //    //{
                //    //    //    ImGui::Spacing();
                //    //    //    ImGui::TextWrapped(TEXT("Menu.QuickWepSpawnerCMDText"));
                //    //    //    ImGui::Spacing();
                //    //    //    ImGui::Separator();
                        //}
                //    //    //


            ImGui::EndChild();
            ImGui::EndTabItem();
            ImGui::EndTabBar();
        }

        */
        //}


// Get config data
/*
Events::initGameEvent += [this]()
    {
    };

*/

#endif //_DISABLED_CODE