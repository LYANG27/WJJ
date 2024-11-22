#include "shorttermforecast.h"

shortTermForecast::shortTermForecast(QVector<shortWeather> sW)
{
    int size = sW.size();
    for (int i=0;i<size;i++)
    {
        shortWeather temp(sW[i].time,sW[i].temperature);
        shortWeatherList.append(temp);
    }
}

shortTermForecast::shortTermForecast(const shortTermForecast &other)
{
    int size = other.shortWeatherList.size();
    for (int i=0;i<size;i++)
        shortWeatherList.append(other.shortWeatherList[i]);
}

shortTermForecast::shortTermForecast()
{

}

void shortTermForecast::setWeatherForecast()
{
    //TODO
}
