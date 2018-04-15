//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVIII
// Versuch 02
// Prüfling: Bjarne Wirsen, 368588
// Datum: 14.04.18
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>

int fibonacci(int n)
{
//	int previousFib = 1;
	int previousFib = 0; //Start ist die 0. FibZahl, also 0 und nicht 1.
	int currentFib = 1;
	if (n == 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}

//	 for (int i = 0; i <= n; i++)
//	 {
//	 int newFib = previousFib + currentFib ;
//	 previousFib = newFib ;
//	 currentFib = previousFib ;
//	 }
	for (int i = 0; i <= n - 2; i++) //Maximum der Schleifen-Durchläufe angepasst, sodass die Ergebnisse passen.
	{								 //Vor der Änderung waren die Ergebnisse zwar korrekt, aber um jeweils 2 Ziffern zu früh.
		int newFib = previousFib + currentFib; //richtig
		//Die beiden folgenden Zeilen wurden logisch angepasst, sodass die mathematische Definition aufgeht:
		//Es müssen stets die beiden vorherigen FibZahlen addiert werden , um die neue zu bestimmen.
		previousFib = currentFib;
		currentFib = newFib;

	}
	return currentFib; //richtig

}

int main()
{
	std::cout << " Fibonacci - Zahlen von 0 bis 42:" << std::endl;
	//for (int i = 1; i <= 12 ; i ++)
	for (int i = 0; i <= 42; i++) //Laufvariable geändert, da Zahlen von 0 an berechnet werden sollen
	{
		std::cout << "f(" << i << ") = " << fibonacci(i) << std::endl;
	}
	return 0;
}

