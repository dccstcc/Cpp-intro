//-----------------------------------------------------------------------------------------------------------------------------
//
//Program umo�liwia narysowanie figury geometrycznej.
//U�ytkownik okre�la znak ASCII, kt�rym figura ma by� narysowana oraz pocz�tkow� wielko�� figury w skali od 1 do 12.
//Narysowan� figur� mo�na przesuwa� po ekranie konsoli przy pomocy strza�ek na klawiaturze.
//Mo�na powi�ksza� lub pomniejsza� figur� przy u�yciu klawiszy '+' oraz '-'.
//Aby zako�czy� prac� programy nale�y nacisn�� klawisz Esq.
//
//-----------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

//-----------------------------------------------------------------------------------------------------------------------------

void HideCursor();                                                              //funkcja ukrywa kursor konsoli
void ClrScr();                                                                 //funkcja czy�ci ekran konsoli
void gotoxy(int x, int y);                                                    //funkcja ustawia kursor na ��danej pozycji
void rysuj_figure(char znak, int rozmiar, int x0, int y0);                   //funkcja rysuje figur�
void sterowanie(char znak, int rozmiar, int &x0, int &y0, char klawisz);    //funkcja umo�liwia przesuwanie figury strza�kami
void zmniejsz_zwieksz(char znak, int rozmiar, int x0, int y0);             //funkcja zmniejsza lub zwi�ksza rozmiar figury

//-----------------------------------------------------------------------------------------------------------------------------

int main()
{

	int x0, y0;                                                        //ustawiam wsp�rz�dne �rodka konsoli
	x0 = 40;
	y0 = 12;

	char znak;                                                        //Wczytuj� znak ASCII
	cout << "Podaj znak ASCII\n\n";                                  //do narysowania figury
	cin >> znak;
	cout << "\n\n";

	int rozmiar;                                                    //Wczytuj� pocz�tkowy 
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
	system("CLS");
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
	gotoxy(x0, y0);                                        //ustawiam kursor na �rodku konsoli

	int i, x, y;
	cout << znak;
	for (i = 1; i <= rozmiar; i++)
	{
		y = y0 - i;                                        //rysuj� g�rn� cz�� figury
		gotoxy(x0, y);
		cout << znak;

		y = y0 + i;                                        //rysuj� doln�, lew� cz�� figury
		x = x0 - 2 * i;
		gotoxy(x, y);
		cout << znak;

		x = x0 + 2 * i;                                    //rysuj� doln�, praw� cz�� figury
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
		if (x0 < 2 * rozmiar)                                                //ograniczam przsuni�cie figury
		{                                                                   //do lewej kraw�dzi ekranu
			x0 = 2 * rozmiar; break;
		}
		else
		{
			ClrScr(); rysuj_figure(znak, rozmiar, x0, y0); break;           //przesuwam figur� w lewo
		}
	}
	case strzalka_w_prawo:
	{
		x0++;
		if (x0 > 79 - 2 * rozmiar)                                         //ograniczam przsuni�cie figury
		{                                                                 //do prawej kraw�dzi ekranu
			x0 = 79 - 2 * rozmiar; break;
		}
		else
		{
			ClrScr(); rysuj_figure(znak, rozmiar, x0, y0); break;         //przesuwam figur� w prawo
		}
	}

	case strzalka_w_gore:
	{
		y0--;
		if (y0 < rozmiar)                                                //ograniczam przsuni�cie figury
		{                                                               //do g�rnej kraw�dzi ekranu
			y0 = rozmiar; break;
		}
		else
		{
			ClrScr(); rysuj_figure(znak, rozmiar, x0, y0); break;       //przesuwam figur� w g�r�
		}
	}
	case strzalka_w_dol:
	{
		y0++;
		if (y0 > 24 - rozmiar)                                          //ograniczam przsuni�cie figury 
		{                                                              //do dolnej kraw�dzi ekranu
			y0 = 24 - rozmiar; break;
		}
		else
		{
			ClrScr(); rysuj_figure(znak, rozmiar, x0, y0); break;       //przesuwam figur� w d�
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
		klawisz = _getch();                                   //wczytujemy klawisz wci�ni�ty podczas
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
		case '+':                                            //zwi�kszamy rozmiar figury o jeden
		{
			rozmiar++;

			if (rozmiar > 12)                                //ustawiamy maksymalny rozmiar figury
			{
				rozmiar = 12;
				break;
			}
			else if (rozmiar > 24 - y0)                       //ograniczamy powi�kszenie figury 
			{                                                //do dolnej kraw�dzi konsoli
				rozmiar = 24 - y0;
				break;
			}
			else if (rozmiar > y0)                           //ograniczamy powiekszenie figury 
			{                                               //do g�rnej kraw�dzi konsoli
				rozmiar = y0;
				break;
			}
			else if (rozmiar * 2 > 79 - x0)                  //ograniczamy powi�kszenie figury 
			{                                               //do prawej kraw�dzi konsoli
				rozmiar = (79 - x0) / 2;
				break;
			}
			else if (rozmiar * 2 > x0)                      //ograniczmay powiekszenie figury
			{                                              //do lewej kraw�dzi konsoli
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
		sterowanie(znak, rozmiar, x0, y0, klawisz);      //wczytujemy funkcj� steruj�c� figur� strza�kami

	} while (klawisz != Esq);

}
//-----------------------------------------------------------------------------------------------------------------------------


