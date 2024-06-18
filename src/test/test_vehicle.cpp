#include "pch.h"
// My code
#include "test_vehicle.h"
#include "functions/vehicle_functions.h"
#include "functions/player_functions.h"

#ifdef GTASA
// Radio Test
#include "CAERadioTrackManager.h"
#include "CAudioEngine.h"
// I can disable the radio and change its type using this
#include "CAEVehicleAudioEntity.h"

#include "CBmx.h"


#endif //GTASA

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

VehicleTestPage::VehicleTestPage()
{

}

static void BlowUpAllCarsMenu()
{
#ifdef GTASA
    CPlayerPed* player = FindPlayerPed();
    int hplayer = CPools::GetPedRef(player);
    CVehicle* pVeh = nullptr;
    CVector pos = player->GetPosition();

    if (ImGui::Button("Blow up all cars")) {

        CCheat::BlowUpCarsCheat();
        Util::SetMessage("All cars have been exterminated!");
    }
}
#else
    Util::SetMessage("Only works for SA!");

    }
#endif //GTASA




static void SearchLightMenu() 
{
#ifdef GTASA
    CPlayerPed* player = FindPlayerPed();
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
    ImGui::SameLine();
    ImGui::Text("Doesn't work!");
#endif //GTASA
}

static void BlowUpVehicleMenu()
{
#ifdef GTASA
    CPlayerPed* player = FindPlayerPed();
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
}

static void CloseDoorsMenu()
{
#ifdef GTASA
    CPlayerPed* player = FindPlayerPed();
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
}



static void LockDoorsMenu()
{
#ifdef GTASA
    CPlayerPed* player = FindPlayerPed();
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

}


static void FlyingCarsMenu()
{
        // This works
#ifdef GTASA
    CPlayerPed* player = FindPlayerPed();
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
}

static void InvincibleCarsMenu()
{
    
#ifdef GTASA
    CPlayerPed* player = FindPlayerPed();
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
}

static void IsCarInWaterMenu()
{
    
#ifdef GTASA
    CPlayerPed* player = FindPlayerPed();
    // Working
    if (ImGui::Button("Is car in water"))
    {
        int hplayer = CPools::GetPedRef(player);
        CVehicle* pVeh = nullptr;
        bool bInVehicle = Command<Commands::IS_CHAR_IN_ANY_CAR>(hplayer);

        // TODO Possibly Move this into a vehicle_functions file.
        // First we check if the player is in a vehicle
        if (bInVehicle) {
            CVehicle* pVeh = player->m_pVehicle;
            int hVeh = CPools::GetVehicleRef(pVeh);
            // https://library.sannybuilder.com/#/sa/default/04D8
            bool isCarInWater = Command<Commands::IS_CAR_IN_WATER>(hVeh);
            
            // If the car is not in water
            if (!isCarInWater)
            {
                Util::SetMessage("Your car is dry.");
            }
            // If the car is in water
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
#endif //GTASA
}



// Incomplete.
static void RadioTest() {
#ifdef GTASA
    CAEVehicleAudioEntity* cAEVehicleAudioEntity = new CAEVehicleAudioEntity();
    CAudioEngine* cAudioEngine = new CAudioEngine();
#endif //GTASA

    ImGui::Separator();
    ImGui::Text("Radio Test");
    bool toggleRadio = true;

    if (ImGui::Checkbox("Toggle Radio", &toggleRadio)) {
        if (!toggleRadio) {
            // Idk how I would set these values
            //eRadioType(RADIO_DISABLED);
            //eRadioType == RADIO_DISABLED;
            //cAudioEngine->;

            //cAEVehicleAudioEntity.
            // Disable the radio
        }
        else 
        {
            // Enable the radio
        }
    }
}

#define _TEST
void BurstAllTiresMenu()
{
    CPlayerPed* player = FindPlayerPed();

    if (ImGui::Button("Pop car tires")) {
        int hplayer = CPools::GetPedRef(player);
        CVehicle* pVeh = nullptr;
        bool bInVehicle = Command<Commands::IS_CHAR_IN_ANY_CAR>(hplayer);

        //// First we check if the player is in a vehicle
        if(bInVehicle)
        {
            //CVehicle* pVeh = player->m_pVehicle;
            // I've never used this before
            // https://github.com/DK22Pac/plugin-sdk/blob/master/examples/OpenDoorExample/Main.cpp#L69
            CVehicle* pVehTest = FindPlayerVehicle(0, false);

            //int hVeh = CPools::GetVehicleRef(pVeh);

#define _SWITCH_TEST
            
#ifdef _SWITCH_TEST

            eVehicleType vehicleType;

            // Check if the player is in a vehicle.
            if (pVehTest) {
                int hVehTest = CPools::GetVehicleRef(pVehTest);
                // I didn't know it was possible to use switch on an enum, this can be useful to cut down on a lot of duplicate code.
                // Well this doesn't seem to work right, it always prints "Your car no longer has tires.
                // https://stackoverflow.com/questions/3019153/how-do-i-use-an-enum-value-in-a-switch-statement-in-c
                
                // I'm not doing this right, it only ever says "Your car no longer has tires" even in a bike or boat.
                // Also says the same for other vehicles too.
                // https://github.com/DK22Pac/plugin-sdk/blob/master/examples/CreateCar/Main.cpp#L41
                //switch (reinterpret_cast<CVehicleModelInfo*>(CModelInfo::ms_modelInfoPtrs[hVehTest])->m_nVehicleType) {
                // This seems to crash it.
                switch (pVeh->m_nVehicleClass) {
                
                case VEHICLE_AUTOMOBILE:
                    Command<Commands::BURST_CAR_TYRE>(hVehTest, 0);
                    Command<Commands::BURST_CAR_TYRE>(hVehTest, 1);
                    Command<Commands::BURST_CAR_TYRE>(hVehTest, 2);
                    Command<Commands::BURST_CAR_TYRE>(hVehTest, 3);
                    Util::SetMessage("Your car no longer has tires!");
                    break;
                case VEHICLE_BIKE:
                    Command<Commands::BURST_CAR_TYRE>(hVehTest, 1);
                    Command<Commands::BURST_CAR_TYRE>(hVehTest, 2);
                    Util::SetMessage("Your bike no longer has tires!");

                    break;
                case VEHICLE_BMX:
                    Command<Commands::BURST_CAR_TYRE>(hVehTest, 1);
                    Command<Commands::BURST_CAR_TYRE>(hVehTest, 2);
                    Util::SetMessage("Your bike no longer has tires!");
                    break;
                default:
                    Util::SetMessage("Only works for cars and bikes!");
                    break;
                }


                //switch (vehicleType) {

             
            }
#else
            // This works
            // TODO Setup for loop for this and check if the car is a motorcycle
            if (pVehTest && pVehTest->m_nVehicleClass == VEHICLE_AUTOMOBILE)
            {
                int hVehTest = CPools::GetVehicleRef(pVehTest);
                // https://github.com/DK22Pac/plugin-sdk/blob/master/examples/OpenDoorExample/Main.cpp#L71
                CAutomobile* autoMobile = reinterpret_cast<CAutomobile*>(pVehTest);

                // TODO Set this to where it detects if the vehicle has 4 tires or not.
                Command<Commands::BURST_CAR_TYRE>(hVehTest, 1);
                Command<Commands::BURST_CAR_TYRE>(hVehTest, 2);
                Command<Commands::BURST_CAR_TYRE>(hVehTest, 3);
                Command<Commands::BURST_CAR_TYRE>(hVehTest, 4);
            }
#endif //_SWITCH_TEST
        }
    }
}

/// <summary>
/// Quick test for checking if the VehicleFunctions class is working properly, it seems to be working fine.
/// </summary>
void CarCheckTestMenu()
{
    VehicleFunctions* vehicleFunctions = new VehicleFunctions();

    // Table test
    // This adds a border for it. ImGuiTableFlags_Borders

    // The flag I have set below removes the borders for the tables.
    if(ImGui::BeginTable("VehicleTable", 4, ImGuiTableFlags_NoBordersInBody)) 
    {
        // 1
        ImGui::TableNextColumn();
        if (ImGui::Button("In vehicle?"))
        {
            // Only shows the "In a car" message if the player is in a vehicle
            VehicleFunctions::PlayerInCarMsg();
        }

        // 2
        ImGui::TableNextColumn();
        if (ImGui::Button("Car in water?"))
        {
            if (PlayerFunctions::IsPlayerInVehicle())
            {
                if (VehicleFunctions::IsCarInWater())
                {
                    Util::SetMessage("Your car is in the water.");
                }
                else
                {
                    Util::SetMessage("Your car is dry");
                }
            }
            else
            {
                Util::SetMessage("You are not in a car!");
            }
        }

        // 3
        ImGui::TableNextColumn();
        if (ImGui::Button("Test1"))
        {
            Util::SetMessage("Not implemented!");
        }

        // 4
        ImGui::TableNextColumn();
        if (ImGui::Button("Test2"))
        {
            Util::SetMessage("Not implemented!");
        }

        ImGui::EndTable();

        // Fix columns being broken
        ImGui::Columns(1);
    }
}

/// <summary>
/// Main code for VehicleTestMenu
/// </summary>
void VehicleTestPage::VehicleTestMenu() {
//#ifdef GTASA
//    CPlayerPed* player = FindPlayerPed();
//    int hplayer = CPools::GetPedRef(player);
//    CVehicle* pVeh = nullptr;
//    CVector pos = player->GetPosition();
//
//    if (ImGui::Button("Blow up all cars")) {
//
//        CCheat::BlowUpCarsCheat();
//        Util::SetMessage("All cars have been exterminated!");
//#else
//    Util::SetMessage("Only works for SA!");
//
//    }
//#endif //GTASA

    // These should be ordered in whatever order they are specified here.
    // Most of these are private to this file, they can be put into the header file to be made public if needed for other classes.
    BlowUpAllCarsMenu();
    SearchLightMenu();
    BlowUpVehicleMenu();
    CloseDoorsMenu();
    LockDoorsMenu();
    FlyingCarsMenu();
    InvincibleCarsMenu();
    IsCarInWaterMenu();

    // New
#ifdef _TEST
    BurstAllTiresMenu();

    ImGui::Separator();
    CarCheckTestMenu();
#endif //_TEST

}


// void VehiclePage::Draw()
//void VehicleTestPage::Draw() 
//{
//    // Draw the test menu with a couple of cheats.
//    VehicleTestMenu();
//}
