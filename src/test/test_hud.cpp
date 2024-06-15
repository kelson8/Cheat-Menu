#include "pch.h"
#include "test_hud.h"

bool toggleHud = true;
bool toggleRadar = true;

void HudTestPage::HudTestMenu() 
{

// GTA SA Specific memory addresses, will most likely crash 3 and vc.
#ifdef GTASA
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
#endif //GTASA
}