#include "pch.h"
#include "test_vehicle.h"

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

// This is mostly specific to GTA SA and has been disabled for 3 and vc, I cannot get this to work on VC anyways.

bool bFlyingCars = false;
bool bSearchLight = false;
bool bVehGodMode = false;

void VehicleTestPage::VehicleTestMenu() {
#ifdef GTASA
    CPlayerPed* player = FindPlayerPed();
    int hplayer = CPools::GetPedRef(player);
    CVehicle* pVeh = nullptr;
    CVector pos = player->GetPosition();
    
    if (ImGui::Button("Blow up all cars")) {

        CCheat::BlowUpCarsCheat();
        Util::SetMessage("All cars have been exterminated!");
#else
        Util::SetMessage("Only works for SA!");
#endif
    }

#ifdef GTASA
    // Try to toggle the search lights in police helicopters, is it toggleable in SA? I think I did it in FiveM.
    if (ImGui::Checkbox("Search Light", &bSearchLight))
    {
        int hPlayer = CPools::GetPedRef(player);
        CVehicle* pVeh = nullptr;

        bool bInVehicle = Command<Commands::IS_CHAR_IN_ANY_CAR>(hPlayer);
        bool bInHeli = Command<Commands::IS_CHAR_IN_ANY_HELI>(hPlayer);

        //bool vehicleSearchLight = Command<Commands::SearchLight>
        if (bInHeli)
        {
            //CHeli::AddHeliSearchLight();
        }
    }
#endif //GTASA
    // https://github.com/JuniorDjjr/CLEOPlus/blob/main/CLEOPlus/Misc.cpp#L261-L266
        /*
        reinterpret_cast<CRunningScript*>(thread)->UpdateCompareFlag(CCheat::m_aCheatsActive[i]);
        */

#ifdef GTASA
    if (ImGui::Button("Blow up Current Car"))
    {

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

    }
#endif //GTASA

#ifdef GTASA
    // Works for closing the doors, not the trunk or hood though.
    if (ImGui::Button("Close doors"))
    {


        int hplayer = CPools::GetPedRef(player);
        CVehicle* pVeh = nullptr;

        bool bInVehicle = Command<Commands::IS_CHAR_IN_ANY_CAR>(hplayer);
        if (bInVehicle)
        {
            CVehicle* pVeh = player->m_pVehicle;
            int hVeh = CPools::GetVehicleRef(pVeh);
            Command<Commands::CLOSE_ALL_CAR_DOORS>(hVeh);
        }
    }
#endif //GTASA

#ifdef GTASA
    // This works for locking the car doors.
    if (ImGui::Button("Lock doors"))
    {


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
    }
#endif //GTASA
    //}

    // This works
#ifdef GTASA
    if (ImGui::Checkbox("Flying cars", &bFlyingCars))
    {
        // In cleo redux I can read and write to memory addresses, not sure how on here.
        // I figured it out in the below code using a function in this menu.
        // Example: 
        /*
        * (Written in JavaScript)
            player.clearWantedLevel();
            Memory.Write(0x969171, 1, 1, false);

            // Flying cars cheat.
            */

            // Idea for this game from game.cpp on line 359
        if (bFlyingCars)
        {
            patch::Set<byte>(0x969160, 1, true);
            Util::SetMessage("Cars can now fly!");
        }
        else
        {
            patch::Set<byte>(0x969160, 0, true);
            Util::SetMessage("Cars can no longer fly!");
        }
        // CallDynGlobal seems to be what they are using for cheats in the plugin-sdk
        //CallDynGlobal<0x969160>;
        // Gives an error though
    }
#endif //GTASA

#ifdef GTASA

    // This works, this was a quick test I came up with.
    if (ImGui::Checkbox("Invincible car", &bVehGodMode))
    {
        int hplayer = CPools::GetPedRef(player);
        CVehicle* pVeh = nullptr;

        bool bInVehicle = Command<Commands::IS_CHAR_IN_ANY_CAR>(hplayer);
        if (bInVehicle)
        {
            CVehicle* pVeh = player->m_pVehicle;
            int hVeh = CPools::GetVehicleRef(pVeh);
#ifdef GTASA
            bool isCarLocked = Command<Commands::GET_CAR_DOOR_LOCK_STATUS>(hVeh);
#endif //GTASA
            //bool isCarLocked = player->m_pVehicle->m_eDoorLock;

            if (bVehGodMode)
            {
                // Car, bulletProof, fireProof, explosionProof, meleeProof
                // https://library.sannybuilder.com/#/sa/default/02AC
                Command<Commands::SET_CAR_PROOFS>(hVeh, true, true, true, true, true);
                Util::SetMessage("Your car now has god mode!");
            }
            else
            {
                Command<Commands::SET_CAR_PROOFS>(hVeh, false, false, false, false, false);
                Util::SetMessage("Your car no longer has god mode!");
            }
        }
    }
#endif //GTASA

#ifdef GTASA
    // Working
    if (ImGui::Button("Is car in water"))
    {
        int hplayer = CPools::GetPedRef(player);
        CVehicle* pVeh = nullptr;
        bool bInVehicle = Command<Commands::IS_CHAR_IN_ANY_CAR>(hplayer);

        if (bInVehicle) {
            CVehicle* pVeh = player->m_pVehicle;
            int hVeh = CPools::GetVehicleRef(pVeh);
            // https://library.sannybuilder.com/#/sa/default/04D8
            bool isCarInWater = Command<Commands::IS_CAR_IN_WATER>(hVeh);

            if (!isCarInWater)
            {
                Util::SetMessage("Your car is dry.");
            }
            else
            {
                Util::SetMessage("Your car is in the water.");
            }
        }
        else
        {
            Util::SetMessage("You are not in a car!");
        }
    }
}
#endif //GTASA



// void VehiclePage::Draw()
//void VehicleTestPage::Draw() 
//{
//    // Draw the test menu with a couple of cheats.
//    VehicleTestMenu();
//}
