#ifndef EXTERNMAP_H
#define EXTERNMAP_H

#include <QDialog>
#include <QString>

namespace Ui {
class ExternMap;
}

class ExternMap : public QDialog
{
    Q_OBJECT

public:
    explicit ExternMap(QWidget *parent = 0);
    ~ExternMap();

    /**
     * @brief getPathToCityMap
     * @return Path to the Map on the HDD
     */
    QString getPathToCityMap();

    /**
     * @brief getPathToStreetMap
     * @return Path to the Street-map on the HDD
     */
    QString getPathToStreetMap();

private slots:
    void on_pushButton_browser_city_clicked();

    void on_pushButton_browser_street_clicked();

private:
    Ui::ExternMap *ui;

    /**
     * @brief pathToCityMap
     */
    QString pathToCityMap;

    /**
     * @brief pathToStreetMap
     */
    QString pathToStreetMap;
};

#endif // EXTERNMAP_H
