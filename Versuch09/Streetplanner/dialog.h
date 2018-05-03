#ifndef DIALOG_H
#define DIALOG_H

#include <QString>
#include <QDialog>
#include "city.h"


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    City* createCity();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
