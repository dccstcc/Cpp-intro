#include <iostream>
#include <conio.h>

using namespace std;

struct element
{
	int wartosc;
	struct element *nastepny;
};

struct info
{
	element *glowa;
	element *ogon;
};

void tworz_liste(int n, info *wsk);
void do_listy(int w, info *wsk);
void pisz_liste(int n, info *wsk);
void elementy_nieparzyste(int n, info *wsk);
void usun_liste(info *wsk);
int main()
{
	int n;
	cout << "Podaj dlugosc listy: \n\n";
	cin >> n;
	cout << "\n";

	info *wsk;
	wsk = new info;
	wsk->glowa = NULL;
	wsk->ogon = NULL;

	tworz_liste(n, wsk);
	pisz_liste(n, wsk);
	elementy_nieparzyste(n, wsk);
	usun_liste(wsk);

	system("pause");
	return 0;
}

void tworz_liste(int n, info *wsk)
{
	int i;
	int w;
	for (i = 1; i <= n; i++)
	{
		w = rand() % (20 - 1 + 1) + 1;
		do_listy(w, wsk);
	}
}

void do_listy(int w, info *wsk)
{
	element *nowy;
	nowy = new element;

	if (wsk->glowa == NULL)
	{
		wsk->glowa = nowy;
		wsk->ogon = wsk->glowa;
	}
	else
	{
		wsk->ogon->nastepny = nowy;
		wsk->ogon = nowy;
	}

	nowy->wartosc = w;
	nowy->nastepny = NULL;
}

void pisz_liste(int n, info *wsk)
{
	element *biezacy;
	biezacy = wsk->glowa;
	int i;

	if (wsk->glowa == NULL)
	{
		cout << "lista jest pusta \n\n";
	}
	else
	{
		for (i = 1; i <= n; i++)
		{
			cout << "element." << i << " = " << biezacy->wartosc << "\n";
			biezacy = biezacy->nastepny;
		}
	}
}

void elementy_nieparzyste(int n, info *wsk)
{
	element *biezacy;
	biezacy = wsk->glowa;
	int i, nieparzysta, suma;
	suma = 0;

	cout << "\nliczby nieparzyste na liscie: ";
	
	for (i = 1; i <= n; i++)
	{
		if (biezacy->wartosc % 2 == 1)
		{
			nieparzysta = biezacy->wartosc;
			cout << biezacy->wartosc << ", ";
			suma = suma + nieparzysta;
		}
		biezacy = biezacy->nastepny;
	}

	cout << "\n\nsuma liczb nieprzystych wynosi: " << suma << "\n\n";
}  

void usun_liste(info *wsk)
{
	element *biezacy, *usuniety;
	biezacy = wsk->glowa;
	if (wsk->glowa = NULL)
	{
		cout << "lista jest pusta\n\n\n\n";
	}
	else
	{
		while (biezacy != NULL)
		{
			usuniety = biezacy;
			biezacy = biezacy->nastepny;
			delete usuniety;
		}
		if (biezacy == NULL)
		{
			cout << "liste usunieto\n\n\n\n";
		}
	}
}