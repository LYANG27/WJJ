#ifndef WEATHER_H
#define WEATHER_H

#include <QObject>
#include <QString>

class Weather
{
public:
    QString date;
    int maxTemperature;
    int minTemperature;
    QString weatherCondition;
    explicit Weather(QString d, int maxT, int minT, QString wC);
    Weather(const Weather &other);
    QString getDate();
    int getMaxT();
    int getMinT();
    QString getWeatherCondition();
signals:

};

#endif // WEATHER_H
