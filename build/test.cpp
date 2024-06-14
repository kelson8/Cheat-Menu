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

//Misc
#include "CCheat.h"

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

// Well I had this working but then broke it 6-14-2024 @ 3:51PM...
// I fixed it 3:53PM.

TestPage& testPage = TestPage::Get();
TestPage::TestPage()
	: IPage<TestPage>(ePageID::Test, "Window.TestPage", true) {

}

//void TestPage::VehicleTest() {
//    // These are neat, the BY_GAME defines seem to have everything in this order: SA, VC, 3.
//    // This is under defines.h
//    CVehicle* pVeh = BY_GAME(FindPlayerVehicle(-1, false), FindPlayerVehicle(), FindPlayerVehicle());
//    int hVeh = CPools::GetVehicleRef(pVeh);
//
//    // If the player is in a vehicle.
//    if (pVeh)
//    {
//
//    }
//
//    // There is a lot of these on the sanny builder website.
//    // 
//    // Car, TireId (int)
//    // https://library.sannybuilder.com/#/sa/default/04FE
//    //Command<Commands::BURST_CAR_TYRE>(hVeh, 1);
//
//    // Get car speed
//    // https://library.sannybuilder.com/#/sa/default/02E3
//    // 
//    // Car
//    //Command<Commands::GET_CAR_SPEED>(hVeh);
//
//    // Lock car doors
//    // https://library.sannybuilder.com/#/sa/default/020A
//    // Will this work?
//    //Command<Commands::LOCK_CAR_DOORS>(hVeh);
//
//    // Explode
//    // https://library.sannybuilder.com/#/sa/default/020B
//    //
//    //Command<Commands::EXPLODE_CAR>(hVeh);
//
//
//}

//void TestPage::PlayerTest() {
//    CPlayerPed* player = FindPlayerPed();
//    int hplayer = CPools::GetPedRef(player);
//    bool isInAir = Command<Commands::IS_CHAR_IN_AIR>(hplayer);
//}


void PlayerTestFeatures() 
{
    CPlayerPed* player = FindPlayerPed();
    int hplayer = CPools::GetPedRef(player);
    CVehicle* pVeh = nullptr;
    CVector pos = player->GetPosition();
}


void TestPage::Draw()
{
    CPlayerPed* player = FindPlayerPed();
    //ImGui::BeginChild("Test");
    if (ImGui::BeginTabBar("Test", ImGuiTabBarFlags_NoTooltip + ImGuiTabBarFlags_FittingPolicyScroll))
    {
        if (ImGui::BeginTabItem(TEXT("Test.TestVehicle")))
        {
            ImGui::Text("Vehicle Tab");
            //static int selected = Locale::GetCurrentLocaleIndex();
            //static std::vector<std::string>& vec = Locale::GetLocaleList();

            ImGui::Text("Hello from KCNet");
            if (ImGui::Button("Blow up Car"))
            {
#ifdef GTASA
                //CPlayerPed* player = FindPlayerPed();
                int hplayer = CPools::GetPedRef(player);
                CVehicle* pVeh = nullptr;

                // This actually does work.
                bool bInVehicle = Command<Commands::IS_CHAR_IN_ANY_CAR>(hplayer);
                if (bInVehicle)
                {
                    CVehicle* pVeh = player->m_pVehicle;
                    int hVeh = CPools::GetVehicleRef(pVeh);
                    Command<Commands::EXPLODE_CAR>(hVeh);
                }
#endif
            }

            if (ImGui::Button("Close doors"))
            {
#ifdef GTASA

                int hplayer = CPools::GetPedRef(player);
                CVehicle* pVeh = nullptr;

                bool bInVehicle = Command<Commands::IS_CHAR_IN_ANY_CAR>(hplayer);
                if (bInVehicle)
                {
                    CVehicle* pVeh = player->m_pVehicle;
                    int hVeh = CPools::GetVehicleRef(pVeh);
                    Command<Commands::CLOSE_ALL_CAR_DOORS>(hVeh);
                }
#endif
            }

            // This works for locking the car doors.
            if (ImGui::Button("Lock doors"))
            {
#ifdef GTASA

                int hplayer = CPools::GetPedRef(player);
                CVehicle* pVeh = nullptr;

                bool bInVehicle = Command<Commands::IS_CHAR_IN_ANY_CAR>(hplayer);
                if (bInVehicle)
                {
                    CVehicle* pVeh = player->m_pVehicle;
                    int hVeh = CPools::GetVehicleRef(pVeh);
                    bool isCarLocked = Command<Commands::GET_CAR_DOOR_LOCK_STATUS>(hVeh);
                    //bool isCarLocked = player->m_pVehicle->m_eDoorLock;

                    // https://library.sannybuilder.com/#/sa/default/020A
                    // https://library.sannybuilder.com/#/sa/enums/CarLock
                    if (!isCarLocked)
                    {
                        // 2 - Locked
                        Command<Commands::LOCK_CAR_DOORS>(hVeh, 2);
                        Util::SetMessage("Car has been locked!");
                    }
                    else
                    {
                        // 1 - Unlocked
                        Command<Commands::LOCK_CAR_DOORS>(hVeh, 1);
                        Util::SetMessage("Car has been unlocked!");
                    }
                }
                else
                {
                    // I wonder how to get the last vehicle the player was in to unlock it.
                }
#endif
            }
            //}
            ImGui::EndTabItem();
        }

        if (ImGui::BeginTabItem(TEXT("Test.TestFeatures")))
        {
            if (ImGui::Button("Suicide"))
            {
                //CPlayerPed* player = FindPlayerPed();
                int hplayer = CPools::GetPedRef(player);
                Command<Commands::EXPLODE_CHAR_HEAD>(hplayer);
            }

            if (ImGui::Button("Bomb")) {
                CPlayerPed* player = FindPlayerPed();
                int hplayer = CPools::GetPedRef(player);

                CVector playerPos = player->GetPosition();

                // https://library.sannybuilder.com/#/sa/default/020C
                // x, y, z, EXPLOSION_CAR
                Command<Commands::ADD_EXPLOSION>(playerPos.x, playerPos.y, playerPos.z, EXPLOSION_CAR);
            }

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

            if (ImGui::Button("Blow up all cars")) {
#ifdef GTASA
                CCheat::BlowUpCarsCheat();
                Util::SetMessage("All cars have been exterminated!");
#else
                Util::SetMessage("Only works for SA!");
#endif
            }

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
            ImGui::EndTabItem();
            ImGui::EndTabItem();
            */
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