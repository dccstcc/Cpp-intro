#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

//----------------------------------------------------------------------------------------------------------

void gotoxy(int x, int y);                                     //funkcja ustawia kursor na ¿adanej pozycji
void rysuj_figure(char znak, int rozmiar);                    //funkcja rysuje figurê
void HideCursor();                                           //funkcja ukrywa kursor konsoli 
int wherex();                                               //funkcja zeruje pozycjê x kursora konsoli
int wherey();                                              //funkcja zeruje pozycjê y kursora konsoli
void ClrScr();                                            //funkcja czyœci ekran konsoli
void zmniejsz_zwieksz(char znak, int rozmiar);           //funkcja zmniejsza lub zwiêksza rozmiar figury

//----------------------------------------------------------------------------------------------------------

int main()
{
	char znak;                                                 //Wczytujemy znak ASCII
	cout << "Podaj znak ASCII\n\n";                           //do narysowania figury
	cin >> znak;
	cout << "\n\n";

	int rozmiar;                                              //Wczytujemy pocz¹tkowy 
	cout << "Podaj poczatkoway rozmiar figury\n\n";          //rozmiar figury
	cin >> rozmiar;
	cout << "\n\n";

	rysuj_figure(znak, rozmiar);
	ClrScr();
	zmniejsz_zwieksz(znak, rozmiar);

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
	

	int x0, y0;                                              //ustawiamy kursor na œrodku
	x0 = 40;                                                //ekranu konsoli
	y0 = 13;
	gotoxy(x0, y0);

	int i, x, y;
	cout << znak;
	for (i = 1; i <= rozmiar; i++)
	{
		y = y0 - i;                                        //rysujemy górn¹ czêœæ figury
		gotoxy(x0, y);
		cout << znak;

		y = y0 + i;                                        //rysujemy doln¹, lew¹ czêœæ figury
		x = x0 - 2*i;
		gotoxy(x, y);
		cout << znak;

		x = x0 + 2*i;                                      //rysujemy doln¹, praw¹ czêœæ figury
		gotoxy(x, y);
		cout << znak;
	}
}

//----------------------------------------------------------------------------------------------------------

void HideCursor()
{
	::HANDLE hConsoleOut = ::GetStdHandle(STD_OUTPUT_HANDLE);
	::CONSOLE_CURSOR_INFO hCCI;
	::GetConsoleCursorInfo(hConsoleOut, &hCCI);
	hCCI.bVisible = FALSE;
	::SetConsoleCursorInfo(hConsoleOut, &hCCI);
}

void zmniejsz_zwieksz(char znak, int rozmiar)
{
	char klawisz;
	do
	{
		HideCursor();
		klawisz = _getch();
		switch (klawisz)
		{
		case '-' : {rozmiar--;}
		case '+': {rozmiar++;}
		}
		ClrScr();
		rysuj_figure(znak, rozmiar);
	} while (klawisz != 27);
}

int wherex()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	return csbi.dwCursorPosition.X;
}

int wherey()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	return csbi.dwCursorPosition.Y;
}

void ClrScr()
{
	int x, y;
	x = wherex();
	y = wherey();
	gotoxy(x, y);
	for (int i = x; i <= 25; i++)
		cout << endl;
	gotoxy(x, y);
}
//----------------------------------------------------------------------------------------------------------
