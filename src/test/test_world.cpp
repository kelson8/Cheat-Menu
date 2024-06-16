#include "pch.h"
#include "test_world.h"
#include "utils/widget.h"

void WeatherMenu()
{
    // Weather
// Will these work?

// Will giving this a default value fix the crashing? I think the weather is crashing it.
    int defaultWeatherType = 0;
    //eWeatherType defaultWeatherType = WEATHER_CLOUDY_COUNTRYSIDE;
    //std::string defaultWeatherType = "WEATHER_CLOUDY_COUNTRYSIDE";

    //static std::vector<eWeatherType> cloudyWeatherTypes = {
    //    WEATHER_CLOUDY_COUNTRYSIDE, WEATHER_CLOUDY_LA, WEATHER_CLOUDY_SF,
    //    WEATHER_CLOUDY_VEGAS
    //};

    static std::vector<std::string> allWeatherTypes = {
        "Extra Sunny LA", "Sunny LA", "Smog LA", "Sunny Smog LA",
        "Cloudy LA", "Sunny SF", "Extra Sunny SF", "Cloudy SF", "Rainy SF",
        "Foggy SF", "Sunny LV", "Cloudy LV", "Extra Sunny Countryside", "Cloudy Countryside",
        "Rainy Countryside", "Extra Sunny Desert", "Sunny Desert", "Sandstorm Desert",
        "Underwater", "Extra Colors 1", "Extra Colors 2"

        //"WEATHER_EXTRASUNNY_COUNTRYSIDE", "WEATHER_EXTRASUNNY_SMOG_LA", "WEATHER_EXTRASUNNY_SMOG_LA",
        //"WEATHER_EXTRASUNNY_VEGAS", "WEATHER_EXTRACOLOURS_1", "WEATHER_EXTRACOLOURS_2",
        //"WEATHER_RAINY_COUNTRYSIDE", "WEATHER_RAINY_SF", "WEATHER_FOGGY_SF", 
        //"WEATHER_REGION_DEFAULT", "WEATHER_REGION_DESERT",
        //"WEATHER_REGION_LA", "WEATHER_REGION_LV", "WEATHER_REGION_SF",
    };

    static std::vector<std::string> cloudyWeatherTypes = {
        "WEATHER_CLOUDY_COUNTRYSIDE", "WEATHER_CLOUDY_LA", "WEATHER_CLOUDY_SF",
        "WEATHER_CLOUDY_VEGAS", "WEATHER_EXTRASUNNY_LA", "WEATHER_EXTRASUNNY_DESERT", "WEATHER_EXTRASUNNY_LA",
        "WEATHER_EXTRASUNNY_COUNTRYSIDE", "WEATHER_EXTRASUNNY_SMOG_LA", "WEATHER_EXTRASUNNY_SMOG_LA",
        "WEATHER_EXTRASUNNY_VEGAS", "WEATHER_EXTRACOLOURS_1", "WEATHER_EXTRACOLOURS_2"
    };

    static std::vector<eWeatherType> sunnyWeatherTypes = {
        WEATHER_EXTRASUNNY_LA, WEATHER_EXTRASUNNY_DESERT, WEATHER_EXTRASUNNY_LA,
        WEATHER_EXTRASUNNY_COUNTRYSIDE, WEATHER_EXTRASUNNY_SMOG_LA, WEATHER_EXTRASUNNY_SMOG_LA,
        WEATHER_EXTRASUNNY_VEGAS, WEATHER_EXTRACOLOURS_1, WEATHER_EXTRACOLOURS_2
    };

    static std::vector<eWeatherType> rainyWeatherTypes = {
        WEATHER_RAINY_COUNTRYSIDE, WEATHER_RAINY_SF,
    };

    //static std::vector<eWeatherType> otherWeatherTypes = {
    //    WEATHER_FOGGY_SF, WEATHER_REGION_DEFAULT, WEATHER_REGION_DESERT, 
    //    WEATHER_REGION_LA, WEATHER_REGION_LV, WEATHER_REGION_SF,
    //};

    //



    // TODO Setup to where this sets the Las Venturas weather instaed of the LA weather in the Los Venturas area.
    // TODO Setup drop down menu for this.
    // Get players current zone if possible, I know it's in the code somewhere.
    ImGui::Separator();
    ImGui::Text("Weather");

    if (ImGui::Button("Rain")) {
        // Will this work?
        CWeather::ForceWeatherNow(WEATHER_RAINY_COUNTRYSIDE);
        Util::SetMessage("Weather set to rain.");
    }

    if (ImGui::Button("Clear")) {
        // Will this work?
        CWeather::ForceWeatherNow(WEATHER_EXTRASUNNY_LA);
        Util::SetMessage("Weather set to rain.");
    }

    // This seems to work but the weather types aren't the right ones that I have listed.
    // They are out of order.
    //if (ImGui::Combo("Cloudy Weather", &defaultWeatherType, cloudyWeatherTypes))
    if (Widget::ListBox("Cloudy Weather", allWeatherTypes, defaultWeatherType))
    {
        defaultWeatherType = defaultWeatherType;
        CWeather::ForceWeatherNow(defaultWeatherType);
    }

    //if (ImGui::Combo("Cloudy Weather", &defaultWeatherType, cloudyWeatherTypes))
    {
        // How would I store the value for this?
        //CWeather::ForceWeatherNow();
    }
}

static void CreateCheckpointMenu()
{
    // Not sure how this one works
    //CCheckpoints::PlaceMarker();
    if (ImGui::Button("Create Checkpoint"))
    {

    }
    ImGui::SameLine();
    ImGui::Text("Doesn't work!");
}

static void RemoveCheckpointMenu()
{
    if (ImGui::Button("Remove checkpoint"))
    {

    }
    ImGui::SameLine();
    ImGui::Text("Doesn't work!");
}



void WorldTestPage::WorldTestMenu()
{
    /*
    Refactor these to have the tabs in each file instead of in the test.cpp file
   // TEXT(Test.TestWorldMenu) - Test World Menu
        if (ImGui::BeginTabItem("World"))
        {
            WeatherMenu();
            ImGui::EndTabItem();
        }
    */

    // Not sure how this one works
    //CCheckpoints::PlaceMarker();
    //if (ImGui::Button("Create Checkpoint"))
    //{

    //}
    //ImGui::SameLine();
    //ImGui::Text("Doesn't work!");

    //if (ImGui::Button("Remove checkpoint"))
    //{

    //}
    //ImGui::SameLine();
    //ImGui::Text("Doesn't work!");

#ifdef GTASA
    CreateCheckpointMenu();
    RemoveCheckpointMenu();
    // Weather
    WeatherMenu();
#endif

	// Not implemented yet!

}