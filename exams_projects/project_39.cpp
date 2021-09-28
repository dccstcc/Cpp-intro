#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>

using namespace std;

struct uczen
{
	string imie, nazwisko;
	int polski, matematyka, fizyka, informatyka;
};

void czyt_dane(int n, uczen dane[20]);void pisz_dane(int n, uczen dane[20]);void sort_dane(int n, uczen dane[20]);void srednia(int n, uczen dane[20]);int main()
{
	uczen dane[20];

	cout << "podaj ilosc uczniow (do 20)\n";
	int n;
	cin >> n;

	czyt_dane(n, dane);
	pisz_dane(n, dane);
	sort_dane(n, dane);
	cout << "\n\n-----------------po sortowaniu: \n\n";
	pisz_dane(n, dane);
	srednia(n, dane);

	
	system("pause");
}
void czyt_dane(int n, uczen dane[20]){
	int i;
	for (i = 0; i < n; i++)
	{
		cout << "podaj imie ucznia "; cout << i+1 << "\n";
		cin >> dane[i].imie;
		cout << "podaj nazwisko ucznia " << i+1 << "\n";
		cin >> dane[i].nazwisko;
		cout << "podaj stopien z polskiego ucznia " << i+1 << "\n";
		cin >> dane[i].polski;
		cout << "podaj stopien z matematyki ucznia " << i+1 << "\n";
		cin >> dane[i].matematyka;
		cout << "podaj stopien z fizyki ucznia " << i+1 << "\n";
		cin >> dane[i].fizyka;
		cout << "podaj stopien z informatyki ucznia " << i+1 << "\n";
		cin >> dane[i].informatyka;
		cout << "\n\n\n";
	}
}

void pisz_dane(int n, uczen dane[20])
{
	int i;
	for (i = 0; i < n; i++)
	{
		cout << "Imie i nazwisko: \n\n" << dane[i].imie + " " + dane[i].nazwisko << "\n\n";
		cout << "_____ oceny: _____\n" << "fizyka: " << dane[i].fizyka << "\n";
		cout << "matematyka: " << dane[i].matematyka << "\n" << "informatyka: " << dane[i].informatyka << "\n" << "polski: " << dane[i].polski << "\n\n\n";
	}
}

void sort_dane(int n, uczen dane[20])
{
	int i, j;
	uczen pom;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (dane[i].nazwisko < dane[j].nazwisko)
			{
				pom = dane[i];
				dane[i] = dane[j];
				dane[j] = pom;
			}
		}
	}
}

void srednia(int n, uczen dane[20])
{
	int i;
	float *srednie_uczniow = new float[n];
	
	for (i = 0; i < n; i++)
	{
		srednie_uczniow[i] = (dane[i].informatyka + dane[i].fizyka + dane[i].polski + dane[i].matematyka) / 4;
		cout << "\n\nsrednia ucznia: " << dane[i].imie + " " + dane[i].nazwisko << " wynosi: " << srednie_uczniow[i] << "\n\n";
	}

	
	
	float pom;
	int j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (srednie_uczniow[i] < srednie_uczniow[j])
			{
				pom = srednie_uczniow[i]; 
				srednie_uczniow[i] = srednie_uczniow[j]; 
				srednie_uczniow[j] = pom;
			}
		}
	}
	cout << "\n\nnajnizsza srednia to " << srednie_uczniow[0] << "\n\n";
	const float najnizsza_srednia = srednie_uczniow[0];
	
	
	for (i = 0; i < n; i++)
	{
		srednie_uczniow[i] = (dane[i].informatyka + dane[i].fizyka + dane[i].polski + dane[i].matematyka) / 4;
	}
	
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (srednie_uczniow[i] > srednie_uczniow[j])
			{
				pom = srednie_uczniow[i];
				srednie_uczniow[i] = srednie_uczniow[j]; 
				srednie_uczniow[j] = pom;
			}
		}
	}
	cout << "\n\nnajwyzsza srednia to " << srednie_uczniow[0] << "\n\n";
	const float najwyzsza_srednia = srednie_uczniow[0];

	
	
	for (i = 0; i < n; i++)
	{
		srednie_uczniow[i] = (dane[i].informatyka + dane[i].fizyka + dane[i].polski + dane[i].matematyka) / 4;
	}

	string uczen_najwysza_srednia;
	string uczen_najnizsza_srednia;
	for (i = 0; i < n; i++) 
	{
		if (srednie_uczniow[i] == najwyzsza_srednia) { uczen_najwysza_srednia = dane[i].imie + " " + dane[i].nazwisko; }
		if (srednie_uczniow[i] == najnizsza_srednia) { uczen_najnizsza_srednia = dane[i].imie + " " + dane[i].nazwisko; }
	}
 
	cout << "\n\nnajnizsza srednia ma: " << uczen_najnizsza_srednia << "\n\nnajwyzsza srednia ma: " << uczen_najwysza_srednia;

	delete new float[n];

}



