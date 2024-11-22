#ifndef LONGTERMFORECAST_H
#define LONGTERMFORECAST_H

#include <QObject>
#include <QVector>
#include <QString>
#include "weather.h"

class LongTermForecast : public QObject
{
    Q_OBJECT
public:
    QVector<Weather> weatherForecast;
    explicit LongTermForecast(QVector<Weather> wF,QObject *parent = nullptr);
    LongTermForecast(const LongTermForecast &other);
    LongTermForecast();
    void setWeatherForecast();

signals:

};

#endif // LONGTERMFORECAST_H
