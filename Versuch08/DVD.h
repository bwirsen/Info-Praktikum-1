/**
 * @file DVD.h
 */
#ifndef DVD_H_
#define DVD_H_

#include "Medium.h"
/**
 * @brief Subklasse DVD der Basisklasse Medium
 */
class DVD: public Medium
{
public:
	DVD();
	/**
	 * @brief Konstruktor mit Parametern
	 * @param initTitel Titel
	 * @param initAltersfreigabe FSK
	 * @param initGenre Genre
	 */
	DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre);
	virtual ~DVD();
	/**
	 * @brief Ausgabefunktion mit Vererbung aus Basisklasse Medium
	 */
	void ausgabe() const;

	/**
	 * @brief Überladung der ausleih-Funktion der Basisklasse Medium
	 * Wird genutzt um die Basisfunktion an die Bedürfnisse der Subklasse anzupassen
	 * @param person Daten der ausleihenden Person
	 * @param ausleihdatum Ausleihdatum
	 * @return true, wenn das Medium ausgeliehen wird. Falls, wenn nicht.
	 */
	bool ausleihen(Person person, Datum ausleihdatum);

protected:
	int initAltersfreigabe;
	std::string initGenre;
};

#endif /* DVD_H_ */
