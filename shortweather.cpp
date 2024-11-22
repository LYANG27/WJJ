#include "shortweather.h"

shortWeather::shortWeather(QString t,int temp)
{
    time = t;
    temperature = temp;
}

shortWeather::shortWeather(const shortWeather &other)
{
    time = other.time;
    temperature = other.temperature;
}

QString shortWeather::getTime()
{
    return time;
}

int shortWeather::getTemperature()
{
    return temperature;
}
