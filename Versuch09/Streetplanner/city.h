#ifndef CITY_H
#define CITY_H

#include <QDebug>
#include <QString>
#include <QGraphicsTextItem>
#include <QGraphicsScene>

/**
 * @brief The City class
 */
class City
{
public:
    /**
     * @brief City Konstruktor
     * @param name Name der Stadt
     * @param x xKoordinate der Stadt
     * @param y yKoordinate der Stadt
     */
    City(QString name, int x, int y);

    /**
     * @brief draw Zeichnet die Stadt
     * @param scene Zeichenfeld aus mainwindow.h
     */
    void draw(QGraphicsScene& scene);

    int get_xCoord();
    int get_yCoord();
    QString get_name() const;

private:
    /**
     * @brief name Name der Stadt
     */
    QString name;

    /**
     * @brief xCoord
     */
    int xCoord;
    /**
     * @brief yCoord
     */
    int yCoord;
};

#endif // CITY_H
