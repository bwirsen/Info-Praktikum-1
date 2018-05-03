#ifndef DIJKSTRADIALOG_H
#define DIJKSTRADIALOG_H

#include <QDialog>
#include "dijkstra.h"

namespace Ui {
class dijkstradialog;
}

class dijkstradialog : public QDialog
{
    Q_OBJECT

public:
    explicit dijkstradialog(QWidget *parent = 0);
    ~dijkstradialog();

    std::vector<Street*> freeSearch(const AbstractMap &map);

private:
    Ui::dijkstradialog *ui;
};

#endif // DIJKSTRADIALOG_H
