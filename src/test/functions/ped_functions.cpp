#include "pch.h"
#include "ped_functions.h"
#include "enums/audio_ids.h"


#ifdef GTASA
#include "CExplosion.h"
#include "CPopulation.h"
#include "CTaskComplexWanderStandard.h"
#include "CSprite.h"
#endif

// Enable test features in this class.
#define _TEST

// Spawn random ped

// Taken from plugin-sdk examples under PedSpawner in Main.cpp
// TODO Convert these to an enum sometime.
int pedModelIds[] = { 0, 7, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 32, 33, 34, 35, 36, 37, 43, 44, 45, 46,
    47, 48, 49, 50, 51, 52, 57, 58, 59, 60, 61, 62, 66, 67, 68, 70, 71, 72, 73, 78, 79, 80, 81, 82, 83, 84, 94, 95, 96, 97, 98, 99, 100, 101,
    102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 120, 121, 122, 123, 124, 125, 126, 127, 128, 132,
    133, 134, 135, 136, 137, 142, 143, 144, 146, 147, 153, 154, 155, 156, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 170, 171,
    173, 174, 175, 176, 177, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 200, 202, 203, 204, 206, 209, 210, 212, 213, 217, 220,
    221, 222, 223, 227, 228, 229, 230, 234, 235, 236, 239, 240, 241, 242, 247, 248, 249, 250, 252, 253, 254, 255, 258, 259, 260, 261, 262,
    9, 10, 11, 12, 13, 31, 38, 39, 40, 41, 53, 54, 55, 56, 63, 64, 69, 75, 76, 77, 85, 87, 88, 89, 90, 91, 92, 93, 129, 130, 131, 138, 139,
    140, 141, 145, 148, 150, 151, 152, 157, 169, 172, 178, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 201, 205, 207, 211, 214, 215,
    216, 218, 219, 224, 225, 226, 231, 232, 233, 237, 238, 243, 244, 245, 246, 251, 256, 257, 263 };

// Cluckin bell,  
int miscPedIds[] = { 167, };

int copModelIds[] = { 280, 281, 282, 283, 284, 285, 286, 287, 288, };

// I wonder how to return this value to use it in the events, so if the ped talks or dies they blow up.
// I would need to return the ped.
#ifdef GTASA
void PedFunctions::SpawnRandomPed()
{
    CPlayerPed* player = FindPlayerPed();
    // Taken from plugin-sdk examples under PedSpawner in Main.cpp
    // https://github.com/DK22Pac/plugin-sdk/blob/master/examples/PedSpawner/Main.cpp
    // Ped
    int modelID = pedModelIds[rand() % 250]; // Random model id
    CStreaming::RequestModel(modelID, 0); // Request the model
    CStreaming::LoadAllRequestedModels(false); // Whatever this does.
    CPed* ped = new CCivilianPed(CPopulation::IsFemale(modelID) ? PED_TYPE_CIVFEMALE : PED_TYPE_CIVMALE, modelID);


    // New
    // Idk how this one works
    //ped->m_pIntelligence

    // Add blip for char
#ifdef _TEST
    // This works but doesn't get removed when the ped dies.
    // Puts a red marker over them.
    // https://library.sannybuilder.com/#/sa/default/0187

    // TODO Figure out how to store marker and delete it when they die.
    Command<Commands::ADD_BLIP_FOR_CHAR>(ped);
#endif //_TEST

    if (ped)
    {
        // TODO Figure out how to draw a health bar above the peds head.

        // This looks like it's getting the offset of the current players coordinates.
        ped->SetPosn(FindPlayerPed()->TransformFromObjectSpace(CVector(0.0f, 5.0f, 3.0f)));
        ped->SetOrientation(0.0f, 0.0f, 0.0f);
        // This should make the spawned in ped hate the player and want to kill them
        // Idea taken from here in this cleo script.: https://gtaforums.com/topic/993040-sa-cleo-detect-that-the-char-is-trying-to-attack-another-char/
        // This didn't work
        ped->m_acquaintance.m_nHate = PED_TYPE_PLAYER1;
        ped->m_acquaintance.m_nHate = PED_TYPE_PLAYER2;
        // Give the ped a MP5
        //ped->GiveWeapon(WEAPON_MP5, 999, true);

        // Stop the ped from talking
        //ped->DisablePedSpeech(1);

        // Give them 1000 health
        ped->m_fHealth = 1000;
        // Set ped to Regular
        ped->m_nPedType = PED_TYPE_CIVMALE;
        // Stop the medics from being able to revive the ped.
        ped->m_nPedFlags.bAllowMedicsToReviveMe = false;
        CVector pedPos = ped->GetPosition();

        // This doesn't work, it would need to be in an event.
        //if (ped->m_nPedFlags.bIsTalking)
        //{
        //    // Spawn a bomb on them if they speak.
        //    Command<Commands::ADD_EXPLOSION>(pedPos.x, pedPos.y, pedPos.z, EXPLOSION_CAR);
        //    Command<Commands::ADD_ONE_OFF_SOUND>(pedPos.x, pedPos.y, pedPos.z, AudioIds::EXPLOSION_SOUND);
        //}



        CWorld::Add(ped);
        ped->PositionAnyPedOutOfCollision();
        ped->m_pIntelligence->m_TaskMgr.SetTask(new CTaskComplexWanderStandard(4, rand() % 8, true), 4, false);
        // What is nCommand, for the char value?
        //ped->m_pIntelligence->m_TaskMgr.SetTask(new CTaskSimpleUseGun(player, player->GetPosition(), 'TT', 1U, false));
        //ped->m_pIntelligence->m_TaskMgr.SetTask(new CTaskSimpleFight());

        // This makes it to where the ped can be cleared by the game.
        ped->CanBeDeleted();
    }
}
#endif //GTASA