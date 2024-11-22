#ifndef CURRENTWEATHER_H
#define CURRENTWEATHER_H

#include <QObject>
#include <QString>
class CurrentWeather : public QObject
{
    Q_OBJECT
public:
    explicit CurrentWeather(int t, int h, QString wC,QObject *parent = nullptr);
    CurrentWeather();
    CurrentWeather(const CurrentWeather &other);
    int curtemperature;
    int humidty;
    QString weatherCondition;
    QString getWC();
    int getCurrentTemperature();
    int getHumidty();
signals:

};

#endif // CURRENTWEATHER_H
