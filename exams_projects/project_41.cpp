#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

struct ulamek
{
	int licznik, mianownik;
	float x;
};

void mnozenie_ulamkow(struct ulamek dane, struct ulamek &wynik);
int main()
{
	ulamek dane;
	ulamek wynik;
	
	cout << "podaj licznik \n";
	cin >> dane.licznik;
	cout << "podaj mianownik \n";
	cin >> dane.mianownik;

	float licznik_float = dane.licznik;
	float mianownik_float = dane.mianownik;
	dane.x = licznik_float / mianownik_float;

	cout << dane.x;

	mnozenie_ulamkow(dane, wynik);

	cout << "\n\nwynikiem mnozenia ulamka przez siebie samego jest: " << wynik.x << "\n\n\n\n";

	system("pause");
	return 0;
}
void mnozenie_ulamkow(struct ulamek dane, struct ulamek &wynik)
{
	wynik.x = (dane.x)*(dane.x);
}