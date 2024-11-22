#include "city.h"


City::City(QString n,CurrentWeather curw,LongTermForecast l,shortTermForecast s)
{
    name = n;

    curweather.curtemperature = curw.curtemperature;
    curweather.humidty = curw.humidty;
    curweather.weatherCondition = curw.weatherCondition;

    int size1=l.weatherForecast.size();
    for (int i=0;i<size1;i++)
    {
        //Weather temp = Weather(l.weatherForecast[i].date,l.weatherForecast[i].maxTemperature,l.weatherForecast[i].minTemperature,l.weatherForecast[i].weatherCondition);
        LTF.weatherForecast.append(l.weatherForecast[i]);
    }

    int size2=s.shortWeatherList.size();
    for (int i=0;i<size2;i++)
    {
        //shortWeather temp = shortWeather(s.shortWeatherList[i].time,s.shortWeatherList[i].temperature);
        STF.shortWeatherList.append(s.shortWeatherList[i]);
    }

}

City::City(const City &other)
{
    name = other.name;

    curweather.humidty = other.curweather.humidty;
    curweather.curtemperature = other.curweather.curtemperature;
    curweather.weatherCondition = other.curweather.weatherCondition;

    int size = other.LTF.weatherForecast.size();
    for (int i=0;i<size;i++)
        LTF.weatherForecast.append(other.LTF.weatherForecast[i]);
        //weatherForecast.append(other.weatherForecast[i]);

    size = other.STF.shortWeatherList.size();
    for (int i=0;i<size;i++)
        STF.shortWeatherList.append(other.STF.shortWeatherList[i]);

}

City::City()
{

}
