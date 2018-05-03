#ifndef STREET_H
#define STREET_H

#include "city.h"

#include <QDebug>
#include <QString>
#include <QGraphicsTextItem>
#include <QGraphicsScene>

/**
 * @brief The Street class
 */
class Street
{
public:

    /**
     * @brief Street
     */
    Street();

    /**
     * @brief Street
     * @param city1
     * @param city2
     */
    Street(City* city1, City* city2);

    /**
     * @brief draw
     * @param scene
     */
    void draw(QGraphicsScene& scene);

    /**
     * @brief drawRed
     * @param scene
     */
    void drawRed(QGraphicsScene& scene);

    City* city1;
    City* city2;

};

#endif // STREET_H
