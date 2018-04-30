/** @mainpage
 *
 * Praktikum Informatik 1 MMXVIII
 * Versuch 7: Überladung
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
#include <vector>
#include <algorithm>

/**
 * @brief global function for operator <<()
 * @param out reference of std::cout
 * @param student element to be printed
 * @return call of the class-function print()
 */
std::ostream& operator<<(std::ostream& out, Student& student)
{
	return student.print(out);
}

/**
 *@brief int main()
 * main routine
 * @return 0 to close .exe
 */
int main()
{
	std::vector<Student> database;
	Student student = Student();

	char abfrage;
	std::cout << "Wollen sie die Liste selbst fuellen? (j)/(n) ";
	std::cin >> abfrage;

	if (abfrage != 'j')
	{
		student = Student(34567, "Harro Simoneit", "19.06.1971", "Am Markt 1");
		database.push_back(student);
		student = Student(74567, "Vera Schmitt", "23.07.1982", "Gartenstr. 23");
		database.push_back(student);
		student = Student(12345, "Siggi Baumeister", "23.04.1983",
				"Ahornst.55");
		database.push_back(student);
		student = Student(64567, "Paula Peters", "9.01.1981", "Weidenweg 12");
		database.push_back(student);
		student = Student(23456, "Walter Rodenstock", "15.10.1963",
				"Wüllnerstr.9");
		database.push_back(student);
	}

	do
	{
		std::cout << "\nMenue:" << std::endl << "-----------------------------"
				<< std::endl << "(1): Datenelement hinzufügen (push)"
				<< std::endl << "(2): Datenelement abhängen (pop)" << std::endl
				<< "(3): Datenbank ausgeben" << std::endl
				<< "(4): Datenbank in umgekehrter Reihenfolge ausgeben"
				<< std::endl << "(5): Datenelement löschen" << std::endl
				<< "(6): Datenelement hinten ergänzen -- identisch zu (1)"
				<< std::endl << "(7): Datenbank sortieren und ausgeben"
				<< std::endl << "(0): Beenden" << std::endl;
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

			//For documentaion visit http://www.cplusplus.com/reference/vector/vector/push_back/
			database.push_back(student);
		}
			break;

		case '2':
		{
			if (database.empty())
			{

				std::cout << "Die Liste ist leer!\n";
			}
			else
			{

				std::cout << "Das letzte Datenelement wird entfernt: \n";
				//For documentaion visit http://www.cplusplus.com/reference/vector/vector/back/
				//and http://www.cplusplus.com/reference/vector/vector/pop_back/
				//database.back().print();
				database.pop_back();
			}
		}
			break;

		case '3':
			std::cout << "Inhalt der Liste:\n";
			//Create iterator (pointer-like operator) to iterate through the container Vector from begin to end
			//again http://www.cplusplus.com/reference/vector/vector/
			for (std::vector<Student>::iterator it = database.begin();
					it != database.end(); ++it)
			{
				//dereference the iterator and print
				std::cout << *it << std::endl;
			}

			break;

		case '4':
			std::cout << "Inhalt der Liste rückwerts:\n";
			for (std::vector<Student>::iterator it = (database.end() - 1);
					it != (database.begin() - 1); --it)
			{
				std::cout << *it << std::endl;
			}
			break;

		case '5':
		{
			unsigned int matNr = 0;
			std::cout << "Matrikelnummer der zu löschenden Person eingeben: ";
			std::cin >> matNr;
			//possible, because default-parameters were added to the constructor in Student.h
			Student search(matNr);

			//function out of <algorithm> : documentation http://www.cplusplus.com/reference/algorithm/find/
			//related to task: find() uses now the overloaded ==() to find the student
			std::vector<Student>::iterator it = std::find(database.begin(),
					database.end(), search);
			if (it != database.end())
			{
				std::cout << "Element found in database: " << *it << '\n';
				database.erase(it); //http://www.cplusplus.com/reference/vector/vector/erase/
				std::cout << "Element erased" << std::endl;
			}
			else
				std::cout << "Element not found in database\n";

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

			database.push_back(student);
		}
			break;

		case '7':
		{
			//using deafault comparison (overloaded operator <)
			std::sort(database.begin(), database.end());

			for (std::vector<Student>::iterator it = database.begin();
					it != database.end(); ++it)
			{
				std::cout << *it << std::endl;
			}
		}
			break;

		case '0':
			std::cout << "Das Programm wird nun beendet";
			break;

		default:
			std::cout << "Falsche Eingabe, bitte nochmal";
			break;
		}
	} while (abfrage != '0');

	return 0;
}
