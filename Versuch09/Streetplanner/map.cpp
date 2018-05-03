#include "map.h"

Map::Map()
{
}

void Map::addCity(City* city){

    //qDebug() << city->get_name() << " hinzugefuegt";

    vectorCities.push_back(city);
}

void Map::draw(QGraphicsScene& scene)
{

    for (QVector<City*>::iterator it = this->vectorCities.begin();  it != this->vectorCities.end(); ++it) {

        //doppelter Pointer: it zeigt auf city und city zeigt auf das Objekt der Klasse City. D.h. doppelt dereferenzieren!
        (*it)->draw(scene);
    }

    for (QVector<Street*>::iterator it = this->vectorStreets.begin();  it != this->vectorStreets.end(); ++it) {

        //doppelter Pointer: it zeigt auf street und street zeigt auf das Objekt der Klasse Street. D.h. doppelt dereferenzieren!
        (*it)->draw(scene);
    }
}

bool Map::addStreet(Street* street)
{
    if(vectorCities.contains(street->city1) && vectorCities.contains(street->city2))
    {
        vectorStreets.push_back(street);
        return true;
    }

    else
    {
        return false;
    }
}

City* Map::find_city(const QString city_name) const
{
    for (QVector<City*>::const_iterator it = this->vectorCities.begin();  it != this->vectorCities.end(); ++it) {

        //compare() compares two Strings and returns 0 if equal
       if(city_name.compare((*it)->get_name()) == 0)
       {
           return *it;
       }

    }
    return NULL;
}


std::vector<Street*> Map::get_street_list(const City* city) const
{
    std::vector<Street*> vektor;

    for (QVector<Street*>::const_iterator it = this->vectorStreets.begin();  it != this->vectorStreets.end(); ++it) {

        //using compare() to compare the given city with the member-cities of the iterated street
       if((city->get_name()).compare((*it)->city1->get_name()) == 0 || (city->get_name()).compare((*it)->city2->get_name()) == 0)
       {
           vektor.push_back(*it);
       }
    }
    return vektor;
}

City* Map::get_opposite_city(const Street* street, const City* city) const
{
    if((street->city1->get_name()).compare(city->get_name()) == 0)
    {
        return street->city2;
    }

    if((street->city2->get_name()).compare(city->get_name()) == 0)
    {
        return street->city1;
    }

    return NULL;
}

double Map::get_length(const Street* street) const
{
    //simply using Pythagorean theorem
    double cathetus1 = street->city1->get_xCoord() - street->city2->get_xCoord();
    double cathetus2 = street->city1->get_yCoord() - street->city2->get_yCoord();

    return sqrt(cathetus1*cathetus1 + cathetus2*cathetus2);
}


