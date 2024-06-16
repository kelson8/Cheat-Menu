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
#include "CWeather.h"
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
bool enterCrane = false;

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

        // TEXT(Test.TestPlayerMenu) - Test Player Menu
        if (ImGui::BeginTabItem("Player"))
        {
            // Incomplete
            PedTestPage::PlayerTestMenu();

            // This is needed, I think it should fix a crash.
            ImGui::EndTabItem();
        }

        if (ImGui::BeginTabItem(TEXT("Test.TestFeatures")))
        {
            // Incomplete
            /*PedTestPage::PlayerTestMenu();*/
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
            //if (ImGui::Button("Create Checkpoint")) 
            //{

            //}
            //ImGui::SameLine();
            //ImGui::Text("Doesn't work!");

            //if (ImGui::Button("Remove checkpoint"))
            //{
            //
            //}
            //ImGui::SameLine();
            //ImGui::Text("Doesn't work!");

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

            // This works
            if (ImGui::Button("Play Mission Passed"))
            {
                // https://library.sannybuilder.com/#/sa/default/0394
                Command<Commands::PLAY_MISSION_PASSED_TUNE>(1);
                //bool isFlyingActive = CCheat::m_aCheatsActive);
                //Util::SetMessage(std::format("Is Flying Active: {}", isFlyingActive).c_str());
            }
            // Clothes

            // World functions
            WorldTestPage::WorldTestMenu();

#endif

//#ifdef GTASA
//        // Weather
//        // Will these work?
//        
//        int defaultWeatherType;
//        //eWeatherType defaultWeatherType = WEATHER_CLOUDY_COUNTRYSIDE;
//        //std::string defaultWeatherType = "WEATHER_CLOUDY_COUNTRYSIDE";
//
//        //static std::vector<eWeatherType> cloudyWeatherTypes = {
//        //    WEATHER_CLOUDY_COUNTRYSIDE, WEATHER_CLOUDY_LA, WEATHER_CLOUDY_SF,
//        //    WEATHER_CLOUDY_VEGAS
//        //};
//
//        static std::vector<std::string> allWeatherTypes = {
//            "Extra Sunny LA", "Sunny LA", "Smog LA", "Sunny Smog LA", 
//            "Cloudy LA", "Sunny SF", "Extra Sunny SF", "Cloudy SF", "Rainy SF",
//            "Foggy SF", "Sunny LV", "Cloudy LV", "Extra Sunny Countryside", "Cloudy Countryside",
//            "Rainy Countryside", "Extra Sunny Desert", "Sunny Desert", "Sandstorm Desert",
//            "Underwater", "Extra Colors 1", "Extra Colors 2"
//            
//            //"WEATHER_EXTRASUNNY_COUNTRYSIDE", "WEATHER_EXTRASUNNY_SMOG_LA", "WEATHER_EXTRASUNNY_SMOG_LA",
//            //"WEATHER_EXTRASUNNY_VEGAS", "WEATHER_EXTRACOLOURS_1", "WEATHER_EXTRACOLOURS_2",
//            //"WEATHER_RAINY_COUNTRYSIDE", "WEATHER_RAINY_SF", "WEATHER_FOGGY_SF", 
//            //"WEATHER_REGION_DEFAULT", "WEATHER_REGION_DESERT",
//            //"WEATHER_REGION_LA", "WEATHER_REGION_LV", "WEATHER_REGION_SF",
//        };
//
//        static std::vector<std::string> cloudyWeatherTypes = {
//            "WEATHER_CLOUDY_COUNTRYSIDE", "WEATHER_CLOUDY_LA", "WEATHER_CLOUDY_SF",
//            "WEATHER_CLOUDY_VEGAS", "WEATHER_EXTRASUNNY_LA", "WEATHER_EXTRASUNNY_DESERT", "WEATHER_EXTRASUNNY_LA",
//            "WEATHER_EXTRASUNNY_COUNTRYSIDE", "WEATHER_EXTRASUNNY_SMOG_LA", "WEATHER_EXTRASUNNY_SMOG_LA",
//            "WEATHER_EXTRASUNNY_VEGAS", "WEATHER_EXTRACOLOURS_1", "WEATHER_EXTRACOLOURS_2"
//        };
//
//        static std::vector<eWeatherType> sunnyWeatherTypes = {
//            WEATHER_EXTRASUNNY_LA, WEATHER_EXTRASUNNY_DESERT, WEATHER_EXTRASUNNY_LA,
//            WEATHER_EXTRASUNNY_COUNTRYSIDE, WEATHER_EXTRASUNNY_SMOG_LA, WEATHER_EXTRASUNNY_SMOG_LA,
//            WEATHER_EXTRASUNNY_VEGAS, WEATHER_EXTRACOLOURS_1, WEATHER_EXTRACOLOURS_2
//        };
//
//        static std::vector<eWeatherType> rainyWeatherTypes = {
//            WEATHER_RAINY_COUNTRYSIDE, WEATHER_RAINY_SF,
//        };
//        
//        //static std::vector<eWeatherType> otherWeatherTypes = {
//        //    WEATHER_FOGGY_SF, WEATHER_REGION_DEFAULT, WEATHER_REGION_DESERT, 
//        //    WEATHER_REGION_LA, WEATHER_REGION_LV, WEATHER_REGION_SF,
//        //};
//
//        //
//
//
//
//        // TODO Setup to where this sets the Las Venturas weather instaed of the LA weather in the Los Venturas area.
//        // TODO Setup drop down menu for this.
//        // Get players current zone if possible, I know it's in the code somewhere.
//        ImGui::Separator();
//        ImGui::Text("Weather");
//        
//        if (ImGui::Button("Rain")) {
//            // Will this work?
//            CWeather::ForceWeatherNow(WEATHER_RAINY_COUNTRYSIDE);
//            Util::SetMessage("Weather set to rain.");
//        }
//
//        if (ImGui::Button("Clear")) {
//            // Will this work?
//            CWeather::ForceWeatherNow(WEATHER_EXTRASUNNY_LA);
//            Util::SetMessage("Weather set to rain.");
//        }
//
//        // This seems to work but the weather types aren't the right ones that I have listed.
//        // They are out of order.
//        //if (ImGui::Combo("Cloudy Weather", &defaultWeatherType, cloudyWeatherTypes))
//        if (Widget::ListBox("Cloudy Weather", allWeatherTypes, defaultWeatherType))
//        {
//            CWeather::ForceWeatherNow(defaultWeatherType);
//        }
//        
//        //if (ImGui::Combo("Cloudy Weather", &defaultWeatherType, cloudyWeatherTypes))
//        {
//            // How would I store the value for this?
//            //CWeather::ForceWeatherNow();
//        }
//
//#endif //GTASA

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