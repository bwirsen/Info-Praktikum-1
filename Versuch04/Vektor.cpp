//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVIII
// Versuch 04: Einführung Klasse
//
// Datei:  Vektor.cpp
// Inhalt: Sourcedatei der Klasse Vektor
//////////////////////////////////////////////////////////////////////////////
#define PI 3.14159265
#include "Vektor.h"

Vektor::Vektor(double inX, double inY, double inZ) :
		x(inX), y(inY), z(inZ)
{

}

Vektor::~Vektor()
{

}

/**
 * @brief Function printing the components of the vector 
 */
void Vektor::print() const
{
	std::cout << "X-Komponente: " << x << std::endl;
	std::cout << "Y-Komponente: " << y << std::endl;
	std::cout << "Z-Komponente: " << z << std::endl << std::endl;
}

/**
 *@brief Function calculating the square-root of the vector
 * @return square-root of the vector
 */
double Vektor::length() const
{
	return sqrt(x * x + y * y + z * z);
}

/**
 *@brief Function calculating the difference between 2 vectors
 * @param input 2nd vector by reference
 * @return difference between the two vectors
 */
Vektor Vektor::sub(const Vektor& input) const
{
	return Vektor(x - input.x, y - input.y, z - input.z);
}

/**
 *@brief Function calculating the scalar product of two vectors
 * @param input input 2nd vector by reference
 * @return scalar product
 */
double Vektor::scalarProd(const Vektor& input) const
{

	return (x * input.x + y * input.y + z * input.z);
}

/**
 * @brief Function calculating the angle between two vectors
 * @param input input 2nd vector by reference
 * @return
 */
double Vektor::angle(const Vektor& input) const
{

	return acos(scalarProd(input) / (length() * input.length())) * 180 / PI;
}

/**
 * @brief Function calculating the rotation around the z-axis
 * @param rad Radiant
 */
void Vektor::rotateAroundZ(const double rad)
{
const double x0=x;
const double y0=y;
const double z0=z;
const double rotMat[3][3]={ {cos(rad),-sin(rad),0},
							{sin(rad),cos(rad), 0},
							{0,	    0,	      1} };

x=x0*rotMat[0][0]+y0*rotMat[0][1]+z0*rotMat[0][2];
y=x0*rotMat[1][0]+y0*rotMat[1][1]+z0*rotMat[1][2];
z=x0*rotMat[2][0]+y0*rotMat[2][1]+z0*rotMat[2][2];
}
