#include <iostream>
#include <string>

using namespace std;

int main()
{
	string wyraz, wyraz_pom, wyraz_pom2, wyraz_pom3, wyraz_koncowy;
	cout << "podaj wyraz\n";
	getline(cin, wyraz, '\n');



	int i,j,n, k, k2, liczba_spacji, m;
	liczba_spacji = 0;
	n = wyraz.size();
	
	for (i = 0; i < n;i++)
	{
		if (wyraz[i] == char(32)) { liczba_spacji ++; }
	}
	
	for (i = 0; m <= liczba_spacji; i++)
	{
		for (i = 0; i < n; i++)
		{
			if (wyraz[i] == char(32)) { string wyraz_pom(wyraz, 0, i); k = i; wyraz_pom m  = wyraz_pom; break; }
		}
		cout << k << wyraz_pom2;

		for (i = k; i < n; i++)
		{
			if (wyraz[i + 1] == char(32)) { string wyraz_pom(wyraz, k + 1, i); k2 = i; wyraz_pom3 = wyraz_pom; break; }
		}

		cout << k2 << wyraz_pom3;
		wyraz_koncowy += wyraz_pom[m];
	}

	system("pause");
	return 0;
}
