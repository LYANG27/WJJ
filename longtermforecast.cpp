#include "longtermforecast.h"

LongTermForecast::LongTermForecast(QVector<Weather> wF,QObject *parent) : QObject(parent)
{
    int size = wF.size();
    for (int i=0;i<size;i++)
    {
        Weather temp = Weather(wF[i].date,wF[i].maxTemperature,wF[i].minTemperature,wF[i].weatherCondition);
        weatherForecast.append(temp);
    }

}

LongTermForecast::LongTermForecast()
{

}

LongTermForecast::LongTermForecast(const LongTermForecast &other)
{
    int size = other.weatherForecast.size();
    for (int i=0;i<size;i++)
    {
        weatherForecast.append(other.weatherForecast[i]);
    }
}


void LongTermForecast::setWeatherForecast()
{
    //TODO:录入数局
}
