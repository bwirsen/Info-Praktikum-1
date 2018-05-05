#include "externmap.h"
#include "ui_externmap.h"
#include <QFileDialog>

ExternMap::ExternMap(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExternMap)
{
    ui->setupUi(this);
}

ExternMap::~ExternMap()
{
    delete ui;
}

void ExternMap::on_pushButton_browser_city_clicked()
{
    pathToCityMap = QFileDialog::getOpenFileName(this, tr("Open File"), "/home", tr("txt-Files (*.txt)"));
    ui->lineEdit_city->setText(pathToCityMap);
}

void ExternMap::on_pushButton_browser_street_clicked()
{
    pathToStreetMap = QFileDialog::getOpenFileName(this, tr("Open File"), "/home", tr("txt-Files (*.txt)"));
    ui->lineEdit_street->setText(pathToStreetMap);
}

QString ExternMap::getPathToCityMap()
{
    return this->pathToCityMap;
}

QString ExternMap::getPathToStreetMap()
{
    return this->pathToStreetMap;
}
