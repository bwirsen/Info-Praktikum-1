/*
 * Buch.cpp
 *
 *  Created on: 01.05.2018
 *      Author: Bjarne
 */

#include "Buch.h"
#include <iostream>

Buch::Buch(std::string initTitel, std::string initAutor) : Medium(initTitel), initAutor(initAutor)
{
}

Buch::~Buch()
{
	// TODO Auto-generated destructor stub
}

void Buch::ausgabe() const
{
	Medium::ausgabe();
	std::cout << "Autor: " << this->initAutor <<std::endl;
}
