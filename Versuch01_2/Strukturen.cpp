/////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVIII
// Versuch 1.2: Strukturen
// Prüfling: Bjarne Wirsen, 368588
// Datum 14.04.18
// Datei:  Strukturen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
using namespace std;

int main()
{
	//Deklaration der Struktur Person
	struct Person
	{
		string sNachname, sVorname;
		int iGeburtsjahr, iAlter;
	};

	Person nBenutzer; //Definition der struct-Variable nBenutzer

	//Eingabe der Daten vom Benutzer
	cout << "Bitte Nachnamen eingeben: " << endl;
	cin >> nBenutzer.sNachname;
	cout << "Bitte Vorname eingeben: " << endl;
	cin >> nBenutzer.sVorname;
	cout << "Bitte Geburtsjahr eingeben: " << endl;
	cin >> nBenutzer.iGeburtsjahr;
	cout << "Bitte Alter eingeben: " << endl;
	cin >> nBenutzer.iAlter;

	//Ausgabe der Eingegeben Daten
	cout << "Daten für nBenutzer:" << endl;
	cout << endl;
	cout << "Name: " << nBenutzer.sNachname << ", " << nBenutzer.sVorname
			<< endl;
	cout << "Alter, Geburtsjahr: " << nBenutzer.iAlter << ", "
			<< nBenutzer.iGeburtsjahr << endl;

	//Kopie von nBenutzer zu nKopieEinzeln, Variante 1
	Person nKopieEinzeln;

	nKopieEinzeln.sNachname = nBenutzer.sNachname;
	nKopieEinzeln.sVorname = nBenutzer.sVorname;
	nKopieEinzeln.iGeburtsjahr = nBenutzer.iGeburtsjahr;
	nKopieEinzeln.iAlter = nBenutzer.iAlter;

	//Kopie von nBenutzer zu nKopieGesamt, Variante 2
	Person nKopieGesamt = nBenutzer;

	//Ausagbe Variante 1
	cout << endl;
	cout << endl;
	cout << "Daten für nKopieEinzeln:" << endl;
	cout << endl;
	cout << "Name: " << nKopieEinzeln.sNachname << ", "
			<< nKopieEinzeln.sVorname << endl;
	cout << "Alter, Geburtsjahr: " << nKopieEinzeln.iAlter << ", "
			<< nKopieEinzeln.iGeburtsjahr << endl;

	//Ausagbe Variante 2
	cout << endl;
	cout << endl;
	cout << "Daten für nKopieGesamt:" << endl;
	cout << endl;
	cout << "Name: " << nKopieGesamt.sNachname << ", "
			<< nKopieGesamt.sVorname << endl;
	cout << "Alter, Geburtsjahr: " << nKopieGesamt.iAlter << ", "
			<< nKopieGesamt.iGeburtsjahr << endl;



	return 0;

}
