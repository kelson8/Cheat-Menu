#include "pch.h"
#include "test_hud.h"

bool toggleHud = true;
bool toggleRadar = true;

HudTestPage::HudTestPage()
{

}

    // GTA SA Specific memory addresses, will most likely crash 3 and vc.
    // What are these doing? From scene.cpp on lines 172-177.
    // Is Nop setting the value to zero? I think that is what it's doing.
    // patch::Set<DWORD>(0x609A4E, 0x4D48689);
    // patch::Set<WORD>(0x609A52, 0);
    // patch::Nop(0x609A4E, 6);



    // patch::Set
    // patch::Set(Address, value, true);
#ifdef GTASA

static void ToggleRadarMenu()
{
    if (ImGui::Checkbox("Toggle Radar", &toggleRadar))
    {
        // radarModeAddress = 0xBA676C
        if (!toggleRadar)
        {
            patch::Set(0xBA676C, 2, true);
        }
        else
        {
            patch::Set(0xBA676C, 0, true);
        }
    }
}

static void ToggleHudMenu()
{
    if (ImGui::Checkbox("Toggle hud", &toggleHud))
    {
        // hudModeAddress = 0xBA6769;
        if (!toggleHud)
        {
            patch::Set(0xBA6769, 0, true);
        }
        else
        {
            patch::Set(0xBA6769, 1, true);
        }
    }
}

#endif //GTASA

/// <summary>
/// Main code for HudTestMenu
/// </summary>
void HudTestPage::HudTestMenu() 
{
#ifdef GTASA
    ToggleHudMenu();
    ToggleRadarMenu();
#endif //GTASA
}