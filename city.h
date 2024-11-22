#ifndef CITY_H
#define CITY_H
#include <QString>
#include <QVector>
#include "currentweather.h"
#include "longtermforecast.h"
#include "shorttermforecast.h"

class City
{
public:
    City(QString n,CurrentWeather curw,LongTermForecast l,shortTermForecast s);
    City(const City &other);
    City();
    QString name;
    CurrentWeather curweather;
    LongTermForecast LTF;
    shortTermForecast STF;
    QString suggestion;
};

#endif // CITY_H
