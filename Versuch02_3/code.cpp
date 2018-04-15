//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVIII
// Versuch 02
// Prüfling: Bjarne Wirsen, 368588
// Datum: 15.04.18
// Datei:  code.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
using namespace std;

string encode(string message, char table[][26])
{

	char code[message.length()];
	for (unsigned int i = 0; i < message.length(); ++i) {

		int pos=message[i]%32;
		code[i]=table[1][pos-1];
	}


	return code;
}

int main()
{

	string text = "HALLO";
	char lookup[2][26] = { {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'},
						   {'Q','W','E','R','T','Z','U','I','O','P','A','S','D','F','G','H','J','K','L','Y','X','C','V','B','N','M'} };


string text_enc=encode(text,lookup);
cout<<text_enc;



}


