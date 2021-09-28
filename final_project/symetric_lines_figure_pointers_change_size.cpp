#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

//----------------------------------------------------------------------------------------------------------

void gotoxy(int x, int y);                                          //funkcja ustawia kursor na ¿adanej pozycji
void rysuj_figure(char znak, int rozmiar, int x0, int y0);       //funkcja rysuje figurê
void HideCursor();                                                //funkcja ukrywa kursor konsoli 
int wherex();                                                    //funkcja zeruje pozycjê x kursora konsoli
int wherey();                                                   //funkcja zeruje pozycjê y kursora konsoli
void ClrScr();                                                 //funkcja czyœci ekran konsoli
void zmniejsz_zwieksz(char znak, int rozmiar, int x0, int y0);//funkcja zmniejsza lub zwiêksza rozmiar figury
void sterowanie(char znak, int rozmiar, int &x0, int &y0, char klawisz);   //funkcja umo¿liwia przesuwanie figury strza³kami

//----------------------------------------------------------------------------------------------------------

int main()
{

	int x0, y0;                                                //ustawiamy wspó³rzêdne œrodka konsoli
	x0 = 40;                                                
	y0 = 12;
	
	char znak;                                                 //Wczytujemy znak ASCII
	cout << "Podaj znak ASCII\n\n";                           //do narysowania figury
	cin >> znak;
	cout << "\n\n";

	int rozmiar;                                              //Wczytujemy pocz¹tkowy 
	cout << "Podaj poczatkoway rozmiar figury\n\n";          //rozmiar figury
	cin >> rozmiar;
	cout << "\n\n";

	HideCursor();
	ClrScr();
	rysuj_figure(znak, rozmiar, x0, y0);
	zmniejsz_zwieksz(znak, rozmiar, x0, y0);
	
	

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

void rysuj_figure(char znak, int rozmiar, int x0, int y0)
{
    gotoxy(x0, y0);                                        //ustawiamy kursor na œrodku konsoli

	int i, x, y;
	cout << znak;
	for (i = 1; i <= rozmiar; i++)
	{
		y = y0 - i;                                        //rysujemy górn¹ czêœæ figury
		gotoxy(x0, y);
		cout << znak;

		y = y0 + i;                                        //rysujemy doln¹, lew¹ czêœæ figury
		x = x0 - 2 * i;
		gotoxy(x, y);
		cout << znak;

		x = x0 + 2 * i;                                    //rysujemy doln¹, praw¹ czêœæ figury
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

void zmniejsz_zwieksz(char znak, int rozmiar, int x0, int y0)
{
	char klawisz;
	const int Esq = 27;
	
	do
	{
		klawisz = _getch();                                   //wczytujemy klawisz wciœniêty podczas
		switch (klawisz)                                     //pracy konsoli
		{
		case '-':                                       //zmniejszamy rozmiar figury o jeden
		{
			rozmiar--;

			if (rozmiar < 1)                             //ustawiamy minimalny rozmiar figury
			{
				rozmiar = 1;
				break;
			}
			else
			{
				ClrScr();
				rysuj_figure(znak, rozmiar, x0, y0);
				break;
			}
		}
		case '+':                                       //zwiêkszamy rozmiar figury o jeden
		{
			rozmiar++;

			if (rozmiar > 12)                           //ustawiamy maksymalny rozmiar figury
			{
				rozmiar = 12;
				break;
			}
			else
			{
				ClrScr();
				rysuj_figure(znak, rozmiar, x0, y0);
				break;
			}
		}
		}
		sterowanie(znak, rozmiar, x0, y0, klawisz);      //wczytujemy funkcjê steruj¹c¹ figurê strza³kami

	} 
	while (klawisz != Esq);
	
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
	x = 0;
	y = 0;
	gotoxy(x, y);
	for (int i = 0; i <= 25*80; i++)
		cout << " ";
	x = 0;
	y = 0;
	gotoxy(x, y);
}
//----------------------------------------------------------------------------------------------------------

void sterowanie(char znak, int rozmiar, int &x0, int &y0, char klawisz)
{
	const int strzalka_w_lewo = 75;
	const int strzalka_w_prawo = 77;
	const int strzalka_w_gore = 72;
	const int strzalka_w_dol = 80;
 
	switch (klawisz)
	{
	case strzalka_w_lewo:
	{
		x0--;
		if (x0 < 2*rozmiar)
		{
			x0 = 2*rozmiar; break;
		}
		else
		{
			ClrScr(); rysuj_figure(znak, rozmiar, x0, y0); break;   //przesuwamy figurê w lewo
		}
	}
	case strzalka_w_prawo:
	{
		x0++; ClrScr(); rysuj_figure(znak, rozmiar, x0, y0); break;   //przesuwamy figurê w prawo
	}
	case strzalka_w_gore:
	{
		y0--; ClrScr(); rysuj_figure(znak, rozmiar, x0, y0); break;   //przesuwamy figurê w górê
	}
	case strzalka_w_dol:
	{
		y0++; ClrScr(); rysuj_figure(znak, rozmiar, x0, y0); break;   //przesuwamy figurê w dó³
	}
	}
}