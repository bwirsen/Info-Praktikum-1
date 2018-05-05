#ifndef DIALOG_H
#define DIALOG_H

#include <QString>
#include <QDialog>
#include "city.h"


namespace Ui {
class Dialog;
}

/**
 * @brief Dialog asking for the required information to create a new city on the map
 */
class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    /**
     * @brief createCity
     * @return pointer on a City on the heap
     */
    City* createCity();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
