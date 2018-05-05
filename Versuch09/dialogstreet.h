#ifndef DIALOGSTREET_H
#define DIALOGSTREET_H

#include <QDialog>
#include "street.h"
#include "map.h"

namespace Ui {
class DialogStreet;
}

/**
 * @brief The DialogStreet class asking for the required information to create a new street
 */
class DialogStreet : public QDialog
{
    Q_OBJECT

public:
    explicit DialogStreet(QWidget *parent = 0);
    ~DialogStreet();

    /**
     * @brief creates a new Street
     * @param map to get the cities which shall be linked
     * @return Pointer on the new street on heap
     */
    Street* createStreet(Map &map);

private:
    Ui::DialogStreet *ui;
};

#endif // DIALOGSTREET_H
