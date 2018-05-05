#ifndef MAP_H
#define MAP_H

#include "abstractmap.h"
#include <QDebug>
#include <QString>
#include <QVector>
#include <QGraphicsScene>
#include <math.h>
/**
 * @brief The Map class
 */
class Map : public AbstractMap
{

public:
    /**
     * @brief Map Konstruktor
     */
    Map();
    /**
     * @brief Fügt Städte dem Map-Vector hinzu
     * @param city, Referenz auf eine Stadt
     */
    void addCity(City* city);
    /**
     * @brief draw Überladung der Draw-Funktion aus city.h.
     * Führt die cit-draw Funktion auf alle Städte im Vektor aus
     * @param scene Zeichenfeld aus mainwindow.h
     */
    void draw(QGraphicsScene& scene);

    /**
     * @brief addStreet
     * @param Pointer on street which will be added to the list
     * @return true if added
     */
    bool addStreet(Street* street);

    /**
     * @brief clearMap
     */
    void clearMap();

    //documentation in abstractmap.h
    City* find_city(const QString city_name) const;

    std::vector<Street*> get_street_list(const City* city) const;

    City * get_opposite_city(const Street* street, const City* city) const;

    double get_length(const Street* street) const;

private:
    /**
     * @brief vectorCities
     * Speicherort für die Referenzen aller Städte
     */
    QVector<City*> vectorCities;
    /**
     * @brief vectorStreets
     * Speicherort für die Referenzen aller Straßen
     */
    QVector<Street*> vectorStreets;

};

#endif // MAP_H
