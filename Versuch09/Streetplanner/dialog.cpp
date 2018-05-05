#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

City* Dialog::createCity(){

    QString cityName = QString(ui->LE_cityname->text());
    int xCoord = QString(ui->LE_xCoord->text()).toInt();
    int yCoord = QString(ui->LE_yCoord->text()).toInt();

    qDebug() << " Name der Stadt: " << cityName;
    qDebug() << "Koordinaten der Stadt : ("<< xCoord << ", " << yCoord <<")";

   City* newCity = new City(cityName,xCoord, yCoord);
   return newCity;
}
