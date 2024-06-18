#include "pch.h"
#include "test_markers.h"

static void CoronasMenu()
{
    // Doesn't work
//    if (ImGui::Button("Show corona"))
//            {
           // I wonder How I would use this?
           // I would need to define it somehow
           //CCorona
           //CCoronas::RegisterCorona();
//            }
}

/// <summary>
/// Main code for MarkersTestMenu
/// </summary>
void MarkersTestPage::MarkersTestMenu() 
{
#ifdef _TEST
    CoronasMenu();
#endif //_TEST
}