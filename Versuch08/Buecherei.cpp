/*! 
 * @ file Buecherei.cpp
 */

//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVIII
// Versuch 08: Vererbung und Polymorphie
//
// Datei:  Buecherei.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

/* Durch setzen dieser Variable können Sie entscheiden, welche Includes alle eingebunden werden sollen
 * Bei setzen auf true sind alle abgeleiteten Klassen (Buch, DVD, Magazin) vorhanden
 * Bei setzen auf false ist nur die Basisklasse Medium vorhanden
 */
 
#define UNTERKLASSENVORHANDEN true

#include <iostream>
#include <string>
#include <vector>
#include "Medium.h"
#include "Datum.h"


#if UNTERKLASSENVORHANDEN

	#include "Magazin.h"
	#include "DVD.h"
	#include "Buch.h"

#endif


int main()
{
	// Vektor mit allen Medien der Bücherei
	std::vector<Medium*> medien;

	// aktuelles Datum
	Datum aktuellesDatum;

// Prüfen, ob Unterklassen schon programmiert wurden (siehe bedingtes Kompilieren)
// entsprechend wird die Datenbank mit unterschiedlichen Medien gefüllt
#if UNTERKLASSENVORHANDEN
	{
		// Datenbank wird mit Medien gefüllt
		Medium* neuesMedium = new Buch("Das Parfum", "Patrick Suskind");
		medien.push_back(neuesMedium);

		neuesMedium = new Buch("Harry Potter und der Stein der Weisen", "J. K. Rowling");
		medien.push_back(neuesMedium);

		neuesMedium = new Buch("Tom Sawyer", "Mark Twain");
		medien.push_back(neuesMedium);

		neuesMedium = new Magazin("Chip", Datum(1, 12, 2017), "Computer");
		medien.push_back(neuesMedium);

		neuesMedium = new DVD("Fluch der Karibik", 12, "Actionkomödie");
		medien.push_back(neuesMedium);

		neuesMedium = new Buch("Huckleberry Finn", "Mark Twain");
		medien.push_back(neuesMedium);
	}
#else
	{
		// Datenbank wird mit Medien gefüllt
		Medium* neuesMedium = new Medium("Das Parfum");
		medien.push_back(neuesMedium);

		neuesMedium = new Medium("Harry Potter und der Stein der Weisen");
		medien.push_back(neuesMedium);

		neuesMedium = new Medium("Tom Sawyer");
		medien.push_back(neuesMedium);
	}
#endif

	std::cout << "Aktuelles Datum: " << aktuellesDatum << std::endl;
    char abfrage;
    do  // Anzeige des Menüs
    {
        std::cout << std::endl
				  << "Menue:" << std::endl
                  << "-----------------------------" << std::endl
                  << "(1): Medium hinzufügen" << std::endl
                  << "(2): Medium löschen" << std::endl
                  << "(3): Datenbank ausgeben" << std::endl
				  << "(4): Ein Medium verleihen" << std::endl
				  << "(5): Ein Medium zurücknehmen" << std::endl
                  << "(7): Beenden" << std::endl;

        // Einlesen der Abfrage
        std::cin >> abfrage;
        std::cin.ignore(10,'\n');

        switch (abfrage)
        {

        	/////////////////////////////////////////////
        	// Ein Medium wird zur Datenbank hinzufügt //
        	/////////////////////////////////////////////
            case '1':
				{

#if UNTERKLASSENVORHANDEN
					std::cout << "Geben Sie die Art des Mediums ein: " << std::endl
							  << "(1): Buch" << std::endl
							  << "(2): Magazin" << std::endl
							  << "(3): DVD" << std::endl;

					// Einlesen der aktuellen Abfrage
					// über std::cin.ignore(10,\n) wird die "Enter-Eingabe, die für std::cin benötigt wird ignoriert
					// Ansonsten würde der nächste getline Befehl nicht auf eine Eingabe warten...
					std::cin >> abfrage;
					std::cin.ignore(10,'\n');

					switch (abfrage)
					{
						// Case 1: Buch
						case '1':
							{
								// Einlesen des Buch-Titels
								std::string titel;
								std::cout << "Bitte geben Sie den Titel des Buchs ein: " << std::endl;
								std::getline(std::cin, titel);

								std::string autor;
								std::cout << "Bitte geben sie den Autor des Buchs ein: " << std::endl;
								std::getline(std::cin, autor);

								// erzeugen eines neuen Buchs
								Medium* neuesMedium = new Buch(titel,autor);
								medien.push_back(neuesMedium);
							}
							break;

						//Case 2: Magazin
						case '2':
							{
								// Einlesen des Magazin-Titels
								std::string titel;
								std::cout << "Geben Sie den Titel des Magazins ein:" << std::endl;
								getline(std::cin, titel);

								// Einlesen der Magazin-Sparte
								std::string sparte;
								std::cout << "Geben Sie die Sparte an:" << std::endl;
								getline(std::cin, sparte);

								// Einlesen des Datums (siehe überladener Eingabeoperator in der Klasse Datum)
								Datum datumAusgabe;
								std::cout << "Geben Sie das Erscheinungsdatum der Ausgabe an:" << std::endl;
								std::cin >> datumAusgabe;

								// erzeugen eines neuen Magazins
								Medium* neuesMedium = new Magazin(titel, datumAusgabe, sparte);
								medien.push_back(neuesMedium);
							}
							break;

						// Case 3: DVD
						case '3':
							{
								// Einlesen des DVD-Titels
								std::string titel;
								std::cout << "Bitte geben Sie den Titel der DVD ein:" << std::endl;
								getline(std::cin, titel);

								// Einlesen des DVD-Generes
								std::string genre;
								std::cout << "Geben Sie das Genre an:" << std::endl;
								getline(std::cin, genre);

								// Einlesen der DVD-Altersfreigabe
								int altersfreigabe;
								std::cout << "Geben Sie die Altersfreigabe ein:" << std::endl;
								std::cin >> altersfreigabe;
								std::cin.ignore(10,'\n');

								Medium* neuesMedium = new DVD(titel, altersfreigabe, genre);
								medien.push_back(neuesMedium);
							}
							break;

						// Ungültige Eingabe
						default:
							std::cout << "Ungültige Eingabe!" << std::endl;
							break;
					}
#else
					// Einlesen des Titels
					std::string titel;
					std::cout << "Bitte geben sie den Titel des Mediums ein:\n";
					getline(std::cin, titel);

					// Erzeugen eines neuen Mediums
					Medium* neuesMedium = new Medium(titel);
					medien.push_back(neuesMedium);
#endif
				}
				break;

			////////////////////////////////////////////////
			// Ein Medium wird aus der Datenbank entfernt //
			////////////////////////////////////////////////
            case '2':
				{
            		// ID des Mediums, welches gelöscht werden soll

					unsigned int id;

					std::cout << "Geben Sie die ID des Mediums ein, welches gelöscht werden soll: " ;
					std::cin >> id;
					std::cin.ignore(10,'\n');

					bool success = false;

					// Suchen des richtigen Mediums zum Löschen
					for(std::vector<Medium*>::iterator it = medien.begin(); it != medien.end(); ++it)
					{
						if((*it)->getID() == id)
						{
							delete (*it);  // Objekt löschen
							medien.erase(it); // Zeiger auf das Objekt löschen
							success = true; // Löschen war erfolgreich
							break; // Schleife abbrechen
						}
					}
					if(!success)
					{
						std::cout << "Keine gültige ID!" << std::endl;
					}
				}
                break;

            ///////////////////////////////////////////
            // Ausgabe aller Medien in der Datenbank //
            ///////////////////////////////////////////
            case '3':
				std::cout << "Vorhandene Medien in der Bücherei:" << std::endl;

				for (unsigned int index = 0; index < medien.size(); ++index)
				{
					std::cout << "*************************************************************" << std::endl;
					medien[index]->ausgabe();
				}

                break;
            /////////////////////////////
            // Verleihen eines Mediums //
            /////////////////////////////
			case '4':
				{
					// Einlesen der ID (über std::cin.ignore(10, '\n'), wird die
					// Enter-Eingabe am Ende std::cin Eingabe ignoriert
					unsigned int id;
					std::cout << "Geben Sie die ID des Mediums ein:" << std::endl;
					std::cin >> id;
					std::cin.ignore(10, '\n');

					// Einlesen des Namens der Person, die das Medium ausleihen möchte
					std::string name;
					std::cout << "Geben Sie den Namen der Person ein: ";
					getline(std::cin, name);

					// Einlesen des Geburtsdatums
					Datum geburtsdatum;
					std::cout << "Geben Sie das Geburtsdatum der Person ein: (Format TT.MM.JJ) ";
					std::cin >> geburtsdatum;

					Person person(name,geburtsdatum);

					bool id_vorhanden = false;
					// Suchen des richtigen Elementes
					for(std::vector<Medium*>::iterator it = medien.begin(); it != medien.end(); ++it)
					{
						if((*it)->getID() == id)
						{
							(*it)->ausleihen(person,aktuellesDatum);
							id_vorhanden = true;
						}
					}
					if (!id_vorhanden)
					{
						std::cout << "Keine gültige ID!" << std::endl;
					}
				}
				break;

			////////////////////////////////////////
			// Medium an die Bücherei zurückgeben //
			////////////////////////////////////////
			case '5':
				{
					// Einlesen der ID (über std::cin.ignore(10, '\n'), wird die
					// Enter-Eingabe am Ende std::cin Eingabe ignoriert)
					unsigned int id;
					std::cout << "Geben Sie die ID des Mediums ein: ";
					std::cin >> id;
					std::cin.ignore(10,'\n');

					bool id_vorhanden = false;
					// Suchen des richtigen Elementes
					for(std::vector<Medium*>::iterator it = medien.begin(); it != medien.end(); ++it)
					{
						if((*it)->getID() == id)
						{
							(*it)->zurueckgeben();
							id_vorhanden = true;
						}
					}
					if (!id_vorhanden)
					{
						std::cout << "Keine gültige ID!" << std::endl;
					}
				}
				break;

            case '7':
                std::cout << "Das Programm wird nun beendet." << std::endl;
                break;

            default :
                std::cout << "Falsche Eingabe, bitte nochmal versuchen.";
                break;
        }
    }
    while (abfrage != '7');

	// Beim Beenden des Programms sämtliche Medien löschen
	for (std::vector<Medium*>::iterator it = medien.begin(); it != medien.end(); ++it)
	{
		delete (*it);
	}

	return 0;
}
