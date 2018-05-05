#include "city.h"


City::City(QString name, int x, int y) : name(name), xCoord(x), yCoord(y)
{
}

void City::draw(QGraphicsScene& scene)
{
    //Ellipse auf die Szene setzen und beschriften
    scene.addEllipse(this->xCoord, this->yCoord, 10, 10, QPen(Qt::red), QBrush(Qt::red, Qt::SolidPattern));
    QGraphicsTextItem* cityName = new QGraphicsTextItem;
    cityName->setPos(this->xCoord, this->yCoord);
    cityName->setPlainText(this->name);
    scene.addItem(cityName);
    //qDebug() << "Stadt gezeichnet";
}

int City::get_xCoord(){

    return this->xCoord;
}

int City::get_yCoord(){

    return this->yCoord;
}

QString City::get_name() const{

    return this->name;
}
