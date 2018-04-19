//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVIII
// Versuch 04: Einführung Klasse
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////
#define PI 3.14159265
#include "Vektor.h"
#include <iostream>


int main()
{
	Vektor vector1(1,9,6.8);
	Vektor vector2(5,1,10.9);
	
	/*vector1.print();
vector2.print();
	//double laenge1=vector1.length();
	vector1.angle(vector2);
	std::cout<<vector1.angle(vector2)<<std::endl;
*/
	vector1.print();
    vector1.rotateAroundZ(PI/2);
    vector1.print();


    vector2.print();
    vector1.sub(vector2).print();

    return 0;
}
