#include "street.h"

Street::Street(City* city1, City* city2): city1(city1), city2(city2)
{
}

void Street::draw(QGraphicsScene& scene)
{
  QPen pen;
  pen.setWidth(2);
  pen.setColor(Qt::black);
  scene.addLine(this->city1->get_xCoord(),this->city1->get_yCoord(),this->city2->get_xCoord(),this->city2->get_yCoord(), pen);
}

void Street::drawRed(QGraphicsScene& scene)
{
    QPen pen;
    pen.setWidth(5);
    pen.setColor(Qt::red);
    scene.addLine(this->city1->get_xCoord(),this->city1->get_yCoord(),this->city2->get_xCoord(),this->city2->get_yCoord(), pen);
}
