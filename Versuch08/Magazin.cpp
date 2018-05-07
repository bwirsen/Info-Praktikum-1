/*!
 * @file Magazin.cpp
 */
#include "Magazin.h"

Magazin::Magazin(std::string initTitel, Datum initDatumAusgabe,
		std::string initSparte) :
		Medium(initTitel), initDatumAusgabe(initDatumAusgabe), initSparte(
				initSparte)
{
}

Magazin::~Magazin()
{
	// TODO Auto-generated destructor stub
}

void Magazin::ausgabe() const
{
	Medium::ausgabe();
	std::cout << "Ausgabe: " << initDatumAusgabe << std::endl;
	std::cout << "Sparte: " << initSparte << std::endl;
}

bool Magazin::ausleihen(Person person, Datum ausleihdatum)
{

	if (abs(this->initDatumAusgabe - ausleihdatum) != (0 || 1))
	{
		//std::cout << abs(this->initDatumAusgabe - ausleihdatum);
		Medium::ausleihen(person, ausleihdatum);
		return true;
	}

	else
	{
		std::cout
				<< "Leider handelt es sich um die neueste Ausgabe des Magazins"
				<< std::endl;

		return false;
	}
}

