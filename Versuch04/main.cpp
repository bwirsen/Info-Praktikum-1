//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVIII
// Versuch 04: Einführung Klasse
// Prüfling: Bjarne Wirsen
// Datum: 20.04.18
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////
#define PI 3.14159265359
#define EARTHRAD 6370
#define ROTATERAD -PI/33000000
#include "Vektor.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int steps = 0;

	//calculation normed to km
	Vektor const human(0, (832 + 1.80) / 1000 + EARTHRAD, 0); //human on platform, constant obviously
	Vektor earthRad(0, EARTHRAD, 0);			//vector middle of earth -> earth surface
	Vektor humanEarth = earthRad.sub(human);    //vector describing the view of the human

	//while loop until the scalarproduct is nearly zero (orthogonal)
	while (humanEarth.scalarProd(earthRad) >= 0.1
			|| humanEarth.scalarProd(earthRad) <= -0.1)
	{
		//rotating earthRad with a constant factor and calculating the new "view" of the human
		earthRad.rotateAroundZ(ROTATERAD);
		humanEarth = earthRad.sub(human);

		++steps;
	}

	cout << fixed;
	cout << setprecision(4);
	cout << "Sie können " << humanEarth.length() << " kM weit sehen" << endl;
	cout << "Sie sind 833.8 Meter hoch." << endl;
	cout << "Der Winkel beträgt " << human.angle(earthRad) << " Grad" << endl;
	cout << "Anzahl Schritte: " << steps << endl;

	return 0;
}
