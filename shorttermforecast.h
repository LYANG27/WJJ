#ifndef SHORTTERMFORECAST_H
#define SHORTTERMFORECAST_H
#include <QString>
#include <QVector>
#include "shortweather.h"

class shortTermForecast
{
public:
    shortTermForecast(QVector<shortWeather> sW);
    shortTermForecast();
    shortTermForecast(const shortTermForecast &other);
    QVector<shortWeather> shortWeatherList;
    void setWeatherForecast();
};

#endif // SHORTTERMFORECAST_H
