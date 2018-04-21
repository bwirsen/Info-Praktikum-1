/** @mainpage
 *
 * Praktikum Informatik 1 MMXVIII
 * Versuch 5: Dynamische Datenstrukturen
 *
 * 
 */

/**
 * @file main.cpp
 *
 * content: main routine
 */

#include <iostream>
#include <string>
#include "Student.h"
#include "List.h"

int main()
{
	List testList;
	Student student = Student();

	char abfrage;
	std::cout << "Wollen sie die Liste selbst fuellen? (j)/(n) ";
	std::cin >> abfrage;

	if (abfrage != 'j')
	{
		student = Student(34567, "Harro Simoneit", "19.06.1971", "Am Markt 1");
		testList.enqueue_head(student);
		student = Student(74567, "Vera Schmitt", "23.07.1982", "Gartenstr. 23");
		testList.enqueue_head(student);
		student = Student(12345, "Siggi Baumeister", "23.04.1983",
				"Ahornst.55");
		testList.enqueue_head(student);
		student = Student(64567, "Paula Peters", "9.01.1981", "Weidenweg 12");
		testList.enqueue_head(student);
		student = Student(23456, "Walter Rodenstock", "15.10.1963",
				"Wüllnerstr.9");
		testList.enqueue_head(student);
	}

	do
	{
		std::cout << "\nMenue:" << std::endl << "-----------------------------"
				<< std::endl << "(1): Datenelement hinzufügen" << std::endl
				<< "(2): Datenelement abhängen" << std::endl
				<< "(3): Datenbank ausgeben" << std::endl
				<< "(4): Datenbank in umgekehrter Reihenfolge ausgeben"
				<< std::endl << "(5): Datenelement löschen" << std::endl
				<< "(6): Datenelement hinten ergänzen" << std::endl
				<< "(7): Beenden" << std::endl;
		std::cin >> abfrage;

		switch (abfrage)
		{
		case '1':
		{
			unsigned int matNr = 0;
			std::string name = "";
			std::string dateOfBirth = "";
			std::string address = "";

			std::cout
					<< "Bitte geben sie die Daten für den Studenten ein.\nName: ";
			std::cin.ignore(10, '\n'); // ignore character '\n', which still is in the buffer
			getline(std::cin, name);    // get entire line, including whitespace
			std::cout << "Geburtsdatum: ";
			getline(std::cin, dateOfBirth);
			std::cout << "Adresse: ";
			getline(std::cin, address);
			std::cout << "Matrikelnummer: ";
			std::cin >> matNr;

			student = Student(matNr, name, dateOfBirth, address);

			testList.enqueue_head(student);
		}
			break;
		case '2':
		{
			Student delElem = Student();
			bool success = false;
			success = testList.dequeue(delElem);

			if (success)
			{
				std::cout << "Das letzte Datenelemt wird entfernt\n";
				delElem.print();
			}
			else
			{
				std::cout << "Die Liste ist leer!\n";
			}
		}
			break;

		case '3':
			std::cout << "Inhalt der Liste:\n";
			testList.print_forwards();
			break;

		case '4':
			std::cout << "Inhalt der Liste rückwerts:\n";
			testList.print_backwards();
			break;

		case '5':
		{
			unsigned int matNr = 0;
			bool success = false;
			std::cout << "Matrikelnummer der zu löschenden Person eingeben: ";
			std::cin >> matNr;
			success = testList.deleteByMatNr(matNr);
			if (success)
			{
				std::cout << "Person zur Matrikelnummer: " << matNr
						<< " gelöscht!";
			}
			else
			{
				std::cout << "MATRIKELNUMMER NICHT VORHANDEN!\n";
			}

		}
			break;

		case '6':
		{
			unsigned int matNr = 0;
			std::string name = "";
			std::string dateOfBirth = "";
			std::string address = "";

			std::cout
					<< "Bitte geben sie die Daten für den Studenten ein.\nName: ";
			std::cin.ignore(10, '\n'); // ignore character '\n', which still is in the buffer
			getline(std::cin, name);    // get entire line, including whitespace
			std::cout << "Geburtsdatum: ";
			getline(std::cin, dateOfBirth);
			std::cout << "Adresse: ";
			getline(std::cin, address);
			std::cout << "Matrikelnummer: ";
			std::cin >> matNr;

			student = Student(matNr, name, dateOfBirth, address);

			testList.enqueue_tail(student);
		}
			break;

		case '7':
			std::cout << "Das Programm wird nun beendet";
			break;

		default:
			std::cout << "Falsche Eingabe, bitte nochmal";
			break;
		}
	} while (abfrage != '7');

	return 0;
}
