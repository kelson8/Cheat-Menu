#include "pch.h"
#include "test_ped.h"

#ifdef GTASA
#include "CExplosion.h"
#endif

// Incomplete.

bool playerCanDrown = true;

void PedTestPage::PlayerTestMenu() 
{
#ifdef GTASA
    CPlayerPed* player = FindPlayerPed();
    if (ImGui::Button("Suicide"))
    {
        //CPlayerPed* player = FindPlayerPed();
        int hplayer = CPools::GetPedRef(player);
        Command<Commands::EXPLODE_CHAR_HEAD>(hplayer);
    }
#else
    CPlayerPed* player = FindPlayerPed();
#endif //GTASA

#ifdef GTASA
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

#ifdef GTASA
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