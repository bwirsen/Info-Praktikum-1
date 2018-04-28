//
// Praktikum Informatik 1 MMXVIII
// Versuch 04: Einführung Klasse
//
// Datei:  Vektor.h
// Inhalt: Headerdatei der Klasse Vektor
//

#ifndef Vektor_H
#define Vektor_H
#define PI 3.14159265359
#include <iostream>
#include <cmath>
#include <iomanip>

class Vektor
{
   public:
	/**
	 * @brief constructor of the class Vektor
	 * @param x Parameter to fill the private x-component
	 * @param y	look at x
	 * @param z loot at y
	 */
    Vektor(double x, double y, double z);
    ~Vektor();

	void print() const;
    Vektor sub(const Vektor& input) const;
    double length() const;
    double scalarProd(const Vektor& input) const;
    double angle(const Vektor& input) const;
    void rotateAroundZ(const double rad);
    
   private:
    double x;
    double y;
    double z;

};

#endif
