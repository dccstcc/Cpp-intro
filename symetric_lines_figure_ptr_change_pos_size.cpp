//-----------------------------------------------------------------------------------------------------------------------------
//
//Program umo¿liwia narysowanie figury geometrycznej.
//U¿ytkownik okreœla znak ASCII, którym figura ma byæ narysowana oraz pocz¹tkow¹ wielkoœæ figury w skali od 1 do 12.
//Narysowan¹ figurê mo¿na przesuwaæ po ekranie konsoli przy pomocy strza³ek na klawiaturze.
//Mo¿na powiêkszaæ lub pomniejszaæ figurê przy u¿yciu klawiszy '+' oraz '-'.
//Aby zakoñczyæ pracê programy nale¿y nacisn¹æ klawisz Esq.
//
//-----------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

//-----------------------------------------------------------------------------------------------------------------------------

void HideCursor();                                                              //funkcja ukrywa kursor konsoli
void ClrScr();                                                                 //funkcja czyœci ekran konsoli
void gotoxy(int x, int y);                                                    //funkcja ustawia kursor na ¿¹danej pozycji
void rysuj_figure(char znak, int rozmiar, int x0, int y0);                   //funkcja rysuje figurê
void sterowanie(char znak, int rozmiar, int &x0, int &y0, char klawisz);    //funkcja umo¿liwia przesuwanie figury strza³kami
void zmniejsz_zwieksz(char znak, int rozmiar, int x0, int y0);             //funkcja zmniejsza lub zwiêksza rozmiar figury

//-----------------------------------------------------------------------------------------------------------------------------

int main()
{

	int x0, y0;                                                        //ustawiam wspó³rzêdne œrodka konsoli
	x0 = 40;
	y0 = 12;

	char znak;                                                        //Wczytujê znak ASCII
	cout << "Podaj znak ASCII\n\n";                                  //do narysowania figury
	cin >> znak;
	cout << "\n\n";

	int rozmiar;                                                    //Wczytujê pocz¹tkowy 
	cout << "Podaj poczatkoway rozmiar figury (1-12)\n\n";         //rozmiar figury
	cin >> rozmiar;
	cout << "\n\n";

	HideCursor();
	ClrScr();
	rysuj_figure(znak, rozmiar, x0, y0);
	zmniejsz_zwieksz(znak, rozmiar, x0, y0);

	system("pause");
	return 0;
}

//-----------------------------------------------------------------------------------------------------------------------------

void HideCursor()
{
	::HANDLE hConsoleOut = ::GetStdHandle(STD_OUTPUT_HANDLE);
	::CONSOLE_CURSOR_INFO hCCI;
	::GetConsoleCursorInfo(hConsoleOut, &hCCI);
	hCCI.bVisible = FALSE;
	::SetConsoleCursorInfo(hConsoleOut, &hCCI);
}

//-----------------------------------------------------------------------------------------------------------------------------

void ClrScr()
{
	int x, y;
	x = 0;
	y = 0;
	gotoxy(x, y);
	for (int i = 0; i <= 25 * 80; i++)
		cout << " ";
	x = 0;
	y = 0;
	gotoxy(x, y);
}

//-----------------------------------------------------------------------------------------------------------------------------

void gotoxy(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

//-----------------------------------------------------------------------------------------------------------------------------

void rysuj_figure(char znak, int rozmiar, int x0, int y0)
{
	gotoxy(x0, y0);                                        //ustawiam kursor na œrodku konsoli

	int i, x, y;
	cout << znak;
	for (i = 1; i <= rozmiar; i++)
	{
		y = y0 - i;                                        //rysujê górn¹ czêœæ figury
		gotoxy(x0, y);
		cout << znak;

		y = y0 + i;                                        //rysujê doln¹, lew¹ czêœæ figury
		x = x0 - 2 * i;
		gotoxy(x, y);
		cout << znak;

		x = x0 + 2 * i;                                    //rysujê doln¹, praw¹ czêœæ figury
		gotoxy(x, y);
		cout << znak;
	}
}

//-----------------------------------------------------------------------------------------------------------------------------

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
		if (x0 < 2 * rozmiar)                                                //ograniczam przsuniêcie figury
		{                                                                   //do lewej krawêdzi ekranu
			x0 = 2 * rozmiar; break;
		}
		else
		{
			ClrScr(); rysuj_figure(znak, rozmiar, x0, y0); break;           //przesuwam figurê w lewo
		}
	}
	case strzalka_w_prawo:
	{
		x0++;
		if (x0 > 79 - 2 * rozmiar)                                         //ograniczam przsuniêcie figury
		{                                                                 //do prawej krawêdzi ekranu
			x0 = 79 - 2 * rozmiar; break;
		}
		else
		{
			ClrScr(); rysuj_figure(znak, rozmiar, x0, y0); break;         //przesuwam figurê w prawo
		}
	}

	case strzalka_w_gore:
	{
		y0--;
		if (y0 < rozmiar)                                                //ograniczam przsuniêcie figury
		{                                                               //do górnej krawêdzi ekranu
			y0 = rozmiar; break;
		}
		else
		{
			ClrScr(); rysuj_figure(znak, rozmiar, x0, y0); break;       //przesuwam figurê w górê
		}
	}
	case strzalka_w_dol:
	{
		y0++;
		if (y0 > 24 - rozmiar)                                          //ograniczam przsuniêcie figury 
		{                                                              //do dolnej krawêdzi ekranu
			y0 = 24 - rozmiar; break;
		}
		else
		{
			ClrScr(); rysuj_figure(znak, rozmiar, x0, y0); break;       //przesuwam figurê w dó³
		}
	}
	}
}

//-----------------------------------------------------------------------------------------------------------------------------

void zmniejsz_zwieksz(char znak, int rozmiar, int x0, int y0)
{
	char klawisz;
	const int Esq = 27;

	do
	{
		klawisz = _getch();                                   //wczytujemy klawisz wciœniêty podczas
		switch (klawisz)                                     //pracy konsoli
		{
		case '-':                                            //zmniejszamy rozmiar figury o jeden
		{
			rozmiar--;

			if (rozmiar < 1)                                 //ustawiamy minimalny rozmiar figury
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
		case '+':                                            //zwiêkszamy rozmiar figury o jeden
		{
			rozmiar++;

			if (rozmiar > 12)                                //ustawiamy maksymalny rozmiar figury
			{
				rozmiar = 12;
				break;
			}
			else if (rozmiar > 24 - y0)                       //ograniczamy powiêkszenie figury 
			{                                                //do dolnej krawêdzi konsoli
				rozmiar = 24 - y0;
				break;
			}
			else if (rozmiar > y0)                           //ograniczamy powiekszenie figury 
			{                                               //do górnej krawêdzi konsoli
				rozmiar = y0;
				break;
			}
			else if (rozmiar * 2 > 79 - x0)                  //ograniczamy powiêkszenie figury 
			{                                               //do prawej krawêdzi konsoli
				rozmiar = (79 - x0) / 2;
				break;
			}
			else if (rozmiar * 2 > x0)                      //ograniczmay powiekszenie figury
			{                                              //do lewej krawêdzi konsoli
				rozmiar = x0 / 2;
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

	} while (klawisz != Esq);

}
//-----------------------------------------------------------------------------------------------------------------------------


