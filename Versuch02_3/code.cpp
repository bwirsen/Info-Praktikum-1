//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVIII
// Versuch 02
// Pr�fling: Bjarne Wirsen, 368588
// Datum: 15.04.18
// Datei:  code.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
using namespace std;

//Funktion zum Verschl�sseln des �bergebenen Wortes mithilfe der Lookup Tabelle
string encode(string message, char table[][26])
{
	//	Deklaration eines quasi Strings mit det L�nge des �bergebenen Wortes
	char code[message.length()];

	for (unsigned int i = 0; i < message.length(); ++i)
	{
		int pos = message[i] % 32; //Berechnet f�r jeden der Buchstaben im Wort die Position im Alphabet
		code[i] = table[1][pos - 1]; //Verschl�sselt die Nachricht indem die Position beibehalten wird und lediglich zur zweiten
									 //Tabellen-Zeile, dem Verschl�sselungsalphabet, gewechselt wird. => eindeutige Paarbildung
	}

	return code; //R�ckgabe des verschl�sselten Wortes als String.
}

string decode(string code, char table[][26])
{

	char message[code.length()];

	//Entschl�sselung durch 2 verschachtelte for-Schleifen
	for (unsigned int i = 0; i < code.length(); ++i)
	{
		for (unsigned int j = 0; j < 26; ++j)
		{

			if (code[i] == table[1][j]) //Abgleich von jedem Buchstaben im Wort mit dem Schl�ssel-Alphabet um Position zu finden
			{
				message[i] = table[0][j]; //Decodierung des Buchstabens durch Wecheln zum Ziel-Alphabet mit gleicher Position.
			}

		}
	}

	return message; //R�ckgabe des entschl�sselten Wortes als String
}


int main()
{

	char lookup[2][26] = { {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'},
						   {'Q','W','E','R','T','Z','U','I','O','P','A','S','D','F','G','H','J','K','L','Y','X','C','V','B','N','M'} };
	string text;

	cout << "Bitte ein Wort zum Verschl�sseln eingeben: ";
	cin >> text;
	cout << "Eingabe: " << text << endl;
	cout << "Verschl�sselte Eingabe: " << encode(text, lookup) << endl;
	cout << "entschl�sselter Code: " << decode(encode(text, lookup), lookup) << endl;

	return 0;
}


