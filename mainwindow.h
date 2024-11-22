#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "city.h"
#include <QLabel>
#include <QString>
#include <QFont>
#include <QInputDialog>
#include <QPushButton>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QVector<City> cities;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
