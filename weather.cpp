#include "weather.h"

Weather::Weather(QString d, int maxT, int minT, QString wC)

{
    date = d;
    maxTemperature = maxT;
    minTemperature = minT;
    weatherCondition = wC;
}

Weather::Weather(const Weather &other)
{
    date = other.date;
    maxTemperature = other.maxTemperature;
    minTemperature = other.minTemperature;
    weatherCondition = other.weatherCondition;
}

QString Weather::getDate()
{
    return date;
}

int Weather::getMaxT()
{
    return maxTemperature;
}

int Weather::getMinT()
{
    return minTemperature;
}

QString Weather::getWeatherCondition()
{
    return weatherCondition;
}

