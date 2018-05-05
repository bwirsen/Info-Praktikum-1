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
    /**
     * @brief get_xCoord
     * @return x-Koordinate der Stadt
     */
    int get_xCoord();

    /**
     * @brief get_yCoord
     * @return y-Koordinate der Stadt
     */
    int get_yCoord();

    /**
     * @brief get_name
     * @return Name der Stadt
     */
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
