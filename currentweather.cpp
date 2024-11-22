#include "currentweather.h"

CurrentWeather::CurrentWeather(int t, int h, QString wC,QObject *parent) : QObject(parent)
{
    curtemperature = t;
    humidty = h;
    weatherCondition = wC;
}

CurrentWeather::CurrentWeather()
{

}

CurrentWeather::CurrentWeather(const CurrentWeather &other)
{
    curtemperature = other.curtemperature;
    humidty = other.humidty;
    weatherCondition = other.weatherCondition;
}

int CurrentWeather::getHumidty()
{
    return humidty;
}

int CurrentWeather::getCurrentTemperature()
{
    return curtemperature;
}

QString CurrentWeather::getWC()
{
    return weatherCondition;
}
