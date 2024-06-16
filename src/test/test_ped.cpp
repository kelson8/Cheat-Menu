#include "pch.h"
#include "test_ped.h"

#ifdef GTASA
#include "CExplosion.h"
#endif

// Incomplete.
// https://library.sannybuilder.com/#/sa/default/0672
//Command<Commands::TASK_DESTROY_CAR>(pPed);

bool playerCanDrown = true;

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
    }
#endif //GTASA
}

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
    CPlayerPed* player = FindPlayerPed();
#ifdef GTASA
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


// Very WIP and incomplete.
static void SpawnPedMenu()
{
    CPlayerPed* player = FindPlayerPed();

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
*/
}


void PedTestPage::PlayerTestMenu() 
{
    SuicideMenu();
    BombMenu();
    ShowCoordsMenu();
    ShowMarkerCoordsMenu();
    TogglePlayerDrownMenu();
    GravityValuesMenu();        
}