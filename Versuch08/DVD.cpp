/*
 * DVD.cpp
 *
 *  Created on: 01.05.2018
 *      Author: Bjarne
 */

#include "DVD.h"

DVD::DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre) :
		Medium(initTitel), initAltersfreigabe(initAltersfreigabe), initGenre(
				initGenre)
{
}

DVD::~DVD()
{
	// TODO Auto-generated destructor stub
}

void DVD::ausgabe() const
{
	Medium::ausgabe();
	std::cout << "FSK: ab " << initAltersfreigabe << " Jahren" << std::endl;
	std::cout << "Genre: " << initGenre << std::endl;
}

bool DVD::ausleihen(Person person, Datum ausleihdatum)
{
	//erzeugt das aktuelle Datum
	Datum aktuellesDatum;
	if (this->initAltersfreigabe
			<= abs((person.getGeburtsdatum() - aktuellesDatum) / 12))
	{
		Medium::ausleihen(person, ausleihdatum);
		return true;
	}
	else
	{
		std::cout << "Tut uns leid, aber Sie sind leider zu jung."<<std::endl;
		return false;
	}
}
