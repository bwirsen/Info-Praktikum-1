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

    /**
     * @brief getCity1
     * @return the Pointer on the first city of the street
     */
    City* getCity1() const;

    /**
     * @brief getCity2
     * @return the Pointer on the second city of the street
     */
    City* getCity2() const;

private:

    /**
     * @brief city1
     */
    City* city1;

    /**
     * @brief city2
     */
    City* city2;

};

#endif // STREET_H
