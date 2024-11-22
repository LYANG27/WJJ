#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(QSize(300*3,648*2));

    //录入city信息
    QString cname = "南京";

    CurrentWeather curw(20,40,"晴");

    QVector<Weather> weatherList;
    for (int i=0;i<7;i++)
    {
        QString date = "11.";
        date.append(QString::number(i+1));
        Weather w(date,20+i,10+i,"晴");
        weatherList.append(w);
    }
    LongTermForecast LTF(weatherList);

    QVector<shortWeather> shortweatherList;
    for (int i=0;i<7;i++)
    {
        QString time = QString::number(i+7);
        time.append(":00");
        shortWeather sW(time,10+i);
        shortweatherList.append(sW);
    }
    shortTermForecast STF(shortweatherList);

    City city1 = City(cname,curw,LTF,STF);
    cities.append(City(cname,curw,LTF,STF));
    //北京
    QString cname2 = "北京";

    CurrentWeather curw2(10,20,"阴");

    QVector<Weather> weatherList2;
    for (int i=0;i<7;i++)
    {
        QString date = "11.";
        date.append(QString::number(i+1));
        Weather w(date,10+i,0+i,"阴");
        weatherList2.append(w);
    }
    LongTermForecast LTF2(weatherList2);

    QVector<shortWeather> shortweatherList2;
    for (int i=0;i<7;i++)
    {
        QString time = QString::number(i+7);
        time.append(":00");
        shortWeather sW(time,0+i);
        shortweatherList2.append(sW);
    }
    shortTermForecast STF2(shortweatherList2);

    City city2 = City(cname2,curw2,LTF2,STF2);
    cities.append(City(cname2,curw2,LTF2,STF2));
    cities[1].suggestion = "  北京当前温度10摄氏度，湿度较低（20%），天气阴天。建议穿着长袖上衣加薄外套，\n早晚可增加一件毛衣或厚外套以防凉意。湿度低，皮肤易干燥，可携带保湿霜\n或喷雾。阴天光线较暗，宜携带晴雨两用伞，以备不时之需。因为湿度低，即使天气阴沉，也无需担心雨水，\n但仍建议穿舒适的鞋子，注意交通安全。";
    cities[0].suggestion = "  南京当前温度20摄氏度，湿度适中（40%），天气晴朗。建议穿着轻薄的长袖衫和长裤\n，搭配一双舒适的平底鞋或运动鞋，既可防晒又适宜步行。晴天适合户外活动，\n可以游览夫子庙、玄武湖等著名景点，记得涂抹防晒霜，佩戴太阳镜和遮阳帽，以保护皮肤免受紫外线伤害。\n同时，保持随身携带的物品精简，以增加出行的便利性。";

    QFont title("Arial", 28, QFont::Bold);
    QLabel *label1 = new QLabel(this);
    QString temp = cities[0].name;
    temp.append("\n20℃");
    //label1->setParent(this);
    label1->setText(temp);
    label1->setAlignment(Qt::AlignCenter);
    label1->setFixedSize(200,200);
    label1->move(350,20);
    label1->setFont(title);
    label1->show();

    QLabel *label2 = new QLabel(this);
    QFont title2("Arial", 18, QFont::Bold);
    QString temp2;
    temp2.append(QString::number(cities[0].LTF.weatherForecast[3].minTemperature));
    temp2.append("℃/");
    temp2.append(QString::number(cities[0].LTF.weatherForecast[3].maxTemperature));
    temp2.append("℃\n湿度：");
    temp2.append(QString::number(cities[0].curweather.humidty));
    temp2.append("\n");
    temp2.append(cities[0].curweather.weatherCondition);
    label2->setText(temp2);
    label2->setAlignment(Qt::AlignCenter);
    label2->setFixedSize(200,300);
    label2->move(350,100);
    label2->setFont(title2);
    label2->show();

    QLabel *label3 = new QLabel(this);
    QFont title3("Arial", 18, QFont::Bold);
    QString temp3;
    for (int i=0;i<7;i++)
    {
        temp3.append(cities[0].STF.shortWeatherList[i].time);
        temp3.append("   ");
    }
    temp3.append("\n");
    for (int i=0;i<7;i++)
    {
        temp3.append(QString::number(cities[0].STF.shortWeatherList[i].temperature));
        temp3.append("℃   ");
    }
    label3->setText(temp3);
    label3->setAlignment(Qt::AlignCenter);
    label3->setFixedSize(900,200);
    label3->move(0,300);
    label3->setFont(title3);
    label3->show();

    QLabel *label4 = new QLabel(this);
    QString temp4="日期:  ";
    for (int i=0;i<7;i++)
    {
        temp4.append(cities[0].LTF.weatherForecast[i].date);
        temp4.append("   ");
    }
    label4->setText(temp4);
    label4->setAlignment(Qt::AlignCenter);
    label4->setFixedSize(900,100);
    label4->move(0,500);
    label4->setFont(title3);
    label4->show();

    QLabel *label5 = new QLabel(this);
    QString temp5="最高温度:  ";
    for (int i=0;i<7;i++)
    {
        temp5.append(QString::number(cities[0].LTF.weatherForecast[i].maxTemperature));
        temp5.append("℃   ");
    }
    label5->setText(temp5);
    label5->setAlignment(Qt::AlignCenter);
    label5->setFixedSize(900,100);
    label5->move(0,600);
    label5->setFont(title3);
    label5->show();

    QLabel *label6 = new QLabel(this);
    QString temp6="最低温度:  ";
    for (int i=0;i<7;i++)
    {
        temp6.append(QString::number(cities[0].LTF.weatherForecast[i].minTemperature));
        temp6.append("℃   ");
    }
    label6->setText(temp6);
    label6->setAlignment(Qt::AlignCenter);
    label6->setFixedSize(900,100);
    label6->move(0,700);
    label6->setFont(title3);
    label6->show();

    QLabel *label7 = new QLabel(this);
    QString temp7="天气状况:  ";
    for (int i=0;i<7;i++)
    {
        temp7.append(cities[0].LTF.weatherForecast[i].weatherCondition);
        temp7.append("    ");
    }
    label7->setText(temp7);
    label7->setAlignment(Qt::AlignCenter);
    label7->setFixedSize(900,100);
    label7->move(0,800);
    label7->setFont(title3);
    label7->show();

    QFont title4("Arial", 10, QFont::Bold);
    QLabel *label8 = new QLabel(this);
    label8->setFrameStyle(QFrame::Box | QFrame::Raised);
    label8->setMargin(10);
    label8->setText(cities[0].suggestion);
    label8->setAlignment(Qt::AlignLeft);
    label8->setFixedSize(700,300);
    label8->move(100,900);
    label8->setFont(title4);
    label8->show();

    QPushButton *switchCity = new QPushButton("切换", this);
    switchCity->setFont(QFont("Arial", 24, QFont::Bold));
    switchCity->setFixedSize(100,100);

    connect(switchCity,&QPushButton::pressed,[=]
    {
        bool ok;
        QString city = QInputDialog::getText(this, "输入城市名称", "请输入城市名称:", QLineEdit::Normal, "南京", &ok);
        if (ok && !city.isEmpty())
        {
            // 在按钮点击时重新设置
            for (int i=0;i<cities.size();i++)
            {
                if (cities[i].name == city)
                {
                    int currentweather = cities[i].curweather.curtemperature;
                    QString str1 = city;
                    str1.append("\n");
                    str1.append(QString::number(currentweather));
                    str1.append("℃");
                    label1->setText(str1);

                    QString temp2;
                    temp2.append(QString::number(cities[i].LTF.weatherForecast[3].minTemperature));
                    temp2.append("℃/");
                    temp2.append(QString::number(cities[i].LTF.weatherForecast[3].maxTemperature));
                    temp2.append("℃\n湿度：");
                    temp2.append(QString::number(cities[i].curweather.humidty));
                    temp2.append("\n");
                    temp2.append(cities[i].curweather.weatherCondition);
                    label2->setText(temp2);

                    QString temp3;
                    for (int j=0;j<7;j++)
                    {
                        temp3.append(cities[i].STF.shortWeatherList[j].time);
                        temp3.append("   ");
                    }
                    temp3.append("\n");
                    for (int j=0;j<7;j++)
                    {
                        temp3.append(QString::number(cities[i].STF.shortWeatherList[j].temperature));
                        temp3.append("℃   ");
                    }
                    label3->setText(temp3);

                    QString temp4="日期:  ";
                    for (int j=0;j<7;j++)
                    {
                        temp4.append(cities[i].LTF.weatherForecast[j].date);
                        temp4.append("   ");
                    }
                    label4->setText(temp4);

                    QString temp5="最高温度:  ";
                    for (int j=0;j<7;j++)
                    {
                        temp5.append(QString::number(cities[i].LTF.weatherForecast[j].maxTemperature));
                        temp5.append("℃   ");
                    }
                    label5->setText(temp5);

                    QString temp6="最低温度:  ";
                    for (int j=0;j<7;j++)
                    {
                        temp6.append(QString::number(cities[i].LTF.weatherForecast[j].minTemperature));
                        temp6.append("℃   ");
                    }
                    label6->setText(temp6);

                    QString temp7="天气状况:  ";
                    for (int j=0;j<7;j++)
                    {
                        temp7.append(cities[i].LTF.weatherForecast[j].weatherCondition);
                        temp7.append("    ");
                    }
                    label7->setText(temp7);

                    label8->setText(cities[i].suggestion);

                    break;
                }
            }
            //TODO:未找到弹出对话框
        }
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

