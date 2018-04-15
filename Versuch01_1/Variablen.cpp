//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVIII
// Versuch 1.1: Datentypen und Typumwandlung
// Prüfling: Bjarne Wirsen, 368588
// Datum: 14.04.18
// Datei:  Variablen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
using namespace std;
/* Sorgt dafür, dass jegliche Funktionen der C++-Standardbibliothek
 * auch ohne "std::" aufrufbar sind, da der Namensraum std als
 * Standard für alle Funktionen angenommen wird. */

int main()
{

	int iErste = 0;
	int iZweite = 0;

	// Hier folgt Ihr eigener Code

	// Aufgabe 1.6.1_1
	cout << "Bitte ganze Zahl iErste eingeben:" << endl;
	cin >> iErste; //Eingabe der ersten Zahl
	cout << "Bitte ganze Zahl iZweite eingeben:" << endl;
	cin >> iZweite; //Eingabeaufforderung der zweiten Zahl

	int iSumme = iErste + iZweite; //Addition der Zahlen
	int iQuotient = iErste / iZweite; //Divison der Zahlen

	cout << "Summe beider Zahlen: " << iSumme << endl; //Ausgabe der Variable iSumme
	cout << "Quotient beider Zahlen: " << iQuotient << endl; //Ausgabe der Variable iQuotient

	//Aufgabe 1.6.1_2
	double dSumme = iErste + iZweite;
	double dQuotient = iErste / iZweite;

	cout << "Summe beider Zahlen als Double: " << dSumme << endl;
	cout << "Quotient beider Zahlen als Double: " << dQuotient << endl;

	//Aufgabe 1.6.1_3, Typumwandlung der Operanden zum Typ Double vor Operation
	double dSummeCast = (double) iErste + (double) iZweite;
	double dQuotientCast = (double) iErste / (double) iZweite;

	cout << "Summe beider Zahlen als Double nach Typecast: " << dSummeCast
			<< endl;
	cout << "Quotient beider Zahlen als Double nach Typecast: " << dQuotientCast
			<< endl;

	/* Die Ergbenisse unterscheiden sich nach dem Typecast zu den vorheringen
	 * Ergbnissen, da die Division von Variablen des Typ double die Möglichkeit
	 * von Nachkommastellen im Ergebnis bietet, was hingegen bei der Division
	 * von Integer-Variablen nicht der Fall ist.
	 */

	//Aufgabe 1.6.1_4
	string sVorname, sNachname; //Deklaration der Zeichenketten sVorname und sNachname
	cout << "Bitte Vorname eingeben: " << endl;
	cin >> sVorname;
	cout << "Bitte Nachname eingeben" << endl;
	cin >> sNachname;

	string space = " ";
	string comma = ",";
	string sVornameName = sVorname + space + sNachname; //+-Operator zum Verbinden 2er Strings
	string sNameVorname = sNachname + comma + space + sVorname;

	cout << "Vorname Name: " << sVornameName << endl;
	cout << "Name, Vorname: " << sNameVorname << endl;

	//Aufgabe 1.6.1_5
	{
		//a)
		int iFeld[2] =
		{ 1, 2 }; //Erstellen eines 2 elementigen Arrays mit den Elementen 1 und 2.
		cout << "1. Element aus iFeld: " << iFeld[0] << endl;
		cout << "2. Element aus iFeld: " << iFeld[1] << endl;
	}

	{
		//b)
		int spielfeld[2][3] =
		{
		{ 1, 2, 3 }, //Erzeugen eines 2D-Arrays
				{ 4, 5, 6 } };

		cout << spielfeld[0][0] << " " << spielfeld[0][1] << " " //Komponentenweise Ausgabe
				<< spielfeld[0][2] << endl;
		cout << spielfeld[1][0] << " " << spielfeld[1][1] << " "
				<< spielfeld[1][2] << endl;
	}

	{
		//c)
		const int iZweite = 1;
		cout << iZweite << endl;
	}
	cout << iZweite << endl; //Holt sich iZweite aus Zeile 29, da der vorherige Block geschlossen wurde.

	//Aufgabe 1.6.1_6
	int iName1 = sVorname[0]; //Betrachtung eines Strings als Array vom Typ char und automatischem typecast zum Typen int
	int iName2 = sVorname[1];

	cout << "Erster Buchstabe des Vornamens nach ASCII: " << iName1
			<< ", zweiter Buchstabe des Vornamens nach ASCII: " << iName2
			<< endl;

	//Aufgabe 1.6.1_7
	int pos1 = iName1 % 32;
	int pos2 = iName2 % 32;

	cout << "Position im Alphabet des ersten Buchstabens: " << pos1
			<< ", Position im Alphabet des zweiten Buchstabens: " << pos2
			<< endl;

	return 0;

}
