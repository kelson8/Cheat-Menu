#include "pch.h"
#include "weather_test.h"
#ifdef GTASA
#include "CWeather.h"
#endif //GTASA

//What will this do?
void EarthQuakeTest()
{
	float earthQuakeTest = 1.0f;
	if (CWeather::Earthquake = earthQuakeTest) 
	{

	}
}


/// <summary>
/// Update the weather, I think this is delayed.
/// </summary>
/// <param name="weatherType">The weather type to be set</param>
void UpdateWeather(eWeatherType weatherType)
{
	CWeather::ForcedWeatherType = weatherType;
}

/// <summary>
/// Update the weather now.
/// </summary>
/// <param name="weatherType">The weather type to be set</param>
void UpdateWeatherNow(eWeatherType weatherType) 
{
	CWeather::ForcedWeatherType = weatherType;
	CWeather::OldWeatherType = weatherType;
	CWeather::NewWeatherType = weatherType;
}

