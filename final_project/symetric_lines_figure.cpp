#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

//----------------------------------------------------------------------------------------------------------

void gotoxy(int x, int y);                                     //funkcja ustawia kursor na �adanej pozycji
void rysuj_figure(char znak, int rozmiar);                    //funkcja rysuje figur�

//----------------------------------------------------------------------------------------------------------

int main()
{
	char znak;                                                 //Wczytujemy znak ASCII
	cout << "Podaj znak ASCII\n\n";                           //do narysowania figury
	cin >> znak;
	cout << "\n\n";
	 
	int rozmiar;                                              //Wczytujemy pocz�tkowy 
	cout << "Podaj poczatkoway rozmiar figury\n\n";          //rozmiar figury
    cin >> rozmiar;
	cout << "\n\n";

	rysuj_figure(znak, rozmiar);

system("pause");
return 0;
}

//----------------------------------------------------------------------------------------------------------

void gotoxy(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

//----------------------------------------------------------------------------------------------------------

void rysuj_figure(char znak, int rozmiar)
{
	int x0, y0;                                              //ustawiamy kursor na �rodku
	x0 = 40;                                                //ekranu konsoli
	y0 = 13;
	gotoxy(x0, y0);

	int i;
	cout << znak;
	for (i = 1; i <= rozmiar; i++)
	{
		int y = y0 + i;
		gotoxy(x0, y);
		cout << znak;
	}
}

//----------------------------------------------------------------------------------------------------------
