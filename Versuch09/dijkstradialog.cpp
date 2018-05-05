#include "dijkstradialog.h"
#include "ui_dijkstradialog.h"

dijkstradialog::dijkstradialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dijkstradialog)
{
    ui->setupUi(this);
}

dijkstradialog::~dijkstradialog()
{
    delete ui;
}

std::vector<Street*> dijkstradialog::freeSearch(const AbstractMap &map)
{
   //calls search() out of the Dijkstra-Class.
   //Parameters are taken from the GUI-Input
   return Dijkstra::search(map, QString(ui->LE_start->text()), QString(ui->LE_dest->text()));

}
