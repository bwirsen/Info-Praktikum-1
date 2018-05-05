#include "dialogstreet.h"
#include "ui_dialogstreet.h"

DialogStreet::DialogStreet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogStreet)
{
    ui->setupUi(this);
}

DialogStreet::~DialogStreet()
{
    delete ui;
}

Street* DialogStreet::createStreet(Map &map)
{
    QString city_start = QString(ui->LE_von->text());
    QString city_dest = QString(ui->LE_nach->text());

    qDebug() << " Name der Start-Stadt: " << city_start;
    qDebug() << " Name der Ziel-Stadt: " << city_dest;

    City* city_start_pointer = map.find_city(city_start);
    City* city_dest_pointer = map.find_city(city_dest);

    Street* newStreet = new Street(city_start_pointer, city_dest_pointer);
    return newStreet;
}
