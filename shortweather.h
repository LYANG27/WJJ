#ifndef SHORTWEATHER_H
#define SHORTWEATHER_H

#include <QObject>
#include <QString>
class shortWeather
{
public:
    explicit shortWeather(QString t,int temp);
    shortWeather(const shortWeather &other);
    QString time;
    int temperature;
    QString getTime();
    int getTemperature();
signals:

};

#endif // SHORTWEATHER_H
