/**
 * @file Buch.h
 */

#ifndef BUCH_H_
#define BUCH_H_

#include "Medium.h"

/**
 * @brief Subklasse Buch der Basisklasse Medium
 */
class Buch: public Medium
{
public:
	Buch();
	/**
	 * @brief Konstruktor mit Parametern
	 * @param initTitel Titel
	 * @param initAutor Autor
	 */
	Buch(std::string initTitel, std::string initAutor);
	/**
	 * @brief virtueller Destruktor
	 */
	virtual ~Buch();

	/**
	 * @brief Ausgabefunktion mit Vererbung aus Basisklasse Medium
	 */
	void ausgabe() const;


protected:
	std::string initAutor;
};

#endif /* BUCH_H_ */
