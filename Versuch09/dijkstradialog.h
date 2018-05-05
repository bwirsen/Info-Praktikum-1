#ifndef DIJKSTRADIALOG_H
#define DIJKSTRADIALOG_H

#include <QDialog>
#include "dijkstra.h"

namespace Ui {
class dijkstradialog;
}

/**
 * @brief The dijkstradialog class asking for information to do a free search
 */
class dijkstradialog : public QDialog
{
    Q_OBJECT

public:
    explicit dijkstradialog(QWidget *parent = 0);
    ~dijkstradialog();

    /**
     * @brief freeSearch Searches the shortest distance between to cities
     * @param map to look at
     * @return a list of the streets to take
     */
    std::vector<Street*> freeSearch(const AbstractMap &map);

private:
    Ui::dijkstradialog *ui;
};

#endif // DIJKSTRADIALOG_H
