#include<iostream>
#include<Windows.h>
#include<conio.h>

using namespace std;

struct trojkat
{
	int a, b, c;
};


void obwod_trojkata(struct trojkat dane, int &wynik);
int main()
{
	
	trojkat dane;
    
	cout << "Podaj dlugosc boku a\n";
	cin >> dane.a;
	cout << "\nPodaj dlugosc boku b\n";
	cin >> dane.b;
	cout << "\nPodaj dlugosc boku a\n";
	cin >> dane.c;

	int wynik = 0;
	obwod_trojkata(dane, wynik);

	cout << "\n\nobwod trojkata wynosi: " << wynik << "\n\n\n\n";

	system("pause");
	return 0;
}
void obwod_trojkata(struct trojkat dane, int &wynik)
{
	wynik = dane.a + dane.b + dane.c;
}