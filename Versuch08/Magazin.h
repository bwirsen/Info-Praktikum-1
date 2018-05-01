/*!
 * @file Magazin.h
 */

#ifndef MAGAZIN_H_
#define MAGAZIN_H_

#include "Medium.h"
/**
 * @brief Subklasse Magazin der Basisklasse Medium
 */
class Magazin: public Medium
{
public:
	/**
	 * @brief Konstruktor
	 */
	Magazin();

	/**
	 * @brief Konstruktor mit Parametern
	 * @param initTitel Titel
	 * @param initDatumAusgabe Herausgabedatum der Ausgabe
	 * @param initSparte Sparte
	 */
	Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte);
	/**
	 * @brief virtueller Destruktor
	 */
	virtual ~Magazin();
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
	Datum initDatumAusgabe;
	std::string initSparte;
};

#endif /* MAGAZIN_H_ */
