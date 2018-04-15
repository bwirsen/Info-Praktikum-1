//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVIII
// Versuch 2.1: Fibonacci Rekursiv
// Prüfling: Bjarne Wirsen, 368588
// Datum: 14.04.18
// Datei:  fib.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

//Erstellen der rekursiven Fibonnacci Funktion
int fibonacci(unsigned int n)
{
	if (n == 0)
	{
		return 0;
	}
	else if (n == 1)
	{
		return 1;
	}

	//Herzstück der Funktion - der rekursive Aufruf nach der Fibonacci-Bedingung
	int fib = fibonacci(n - 1) + fibonacci(n - 2);

	//Rückgabe der berechneten Fibonacci-Zahl
	return fib;
}

int main()
{
	//Definition der Variable maxFib und erstellen des Zielarrays, in welchem die n-ten Fibonacci-Zahlen gespeichert werden
	const unsigned int maxFib = 25;

	//Aufrufen der Fibonacci Funktion und iteratives Ausgeben der n-ten Ergbenisse für n,max=maxFib
	for (unsigned int var = 0; var <= maxFib; ++var)
	{
		cout << "Fibonacci-Zahl für n=" << var << " ==> " << fibonacci(var)<<endl;
	}

	return 0;
}

