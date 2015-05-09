#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

string szyfroj(string);
string odszyfroj(string);
bool powtorz;

void wypisz(short, short, string, fstream &);

int main() {
	
	string wyraz;
	fstream plik;
	short wybor1, wybor2, wybor3;
	powtorz = false;

	do{
		
		cout << "Czytanie stringu z :\n[1]Pliku\n[2]Klawiatury\n"
			"W przypadku pliku umiesc go w tym samym folderze co .exe\n" 
			"nazwij go dane.txt i na koncu wstaw ' (tylde) " << endl;
		cin >> wybor1;


		if (wybor1 == 1)
		{
			plik.open("dane.txt", ios::in);
			getline(plik, wyraz, '`');
			plik.close();
		}


		cout << "Wypisanie wyniku:\n[1]Plik\n[2]Ekran" << endl;
		cin >> wybor3;


		cout << "[1] Zaszyfroj \n[2] Odszyfroj" << endl;
		cin >> wybor2;


		cin.clear();
		cin.sync();


		switch (wybor1)
		{

			case 2: // Odczyt z ekranu

				cout << "Podaj string (Aby zakonczyc wpisywanie wcisnij ` (tylde) i enter!" << endl;
				getline(cin, wyraz, '`');
				wypisz(wybor2, wybor3, wyraz, plik);
				break;

			case 1: // Odczyt z pliku

				wypisz(wybor2, wybor3, wyraz, plik);
				break;

			default:

				cout << "Podałes zla liczbe!";

		}
		
		cout << "Kontynuowac?\n[1]Tak\n[0]Nie" << endl;
		cin >> powtorz;

		system("CLS");

	} while (powtorz);


	return 0;
}

void wypisz(short w2, short w3, string wyraz, fstream & plik )
{
	
	switch (w3)
	{

		case 2: // Wypisanie na ekran
			
			if (w2 == 1)
				cout << szyfroj(wyraz) << endl;
			else
				cout << odszyfroj(wyraz) << endl;

			break;



		case 1: // Wypisanie do pliku
			
			plik.open("dane.txt", ios::out | ios::trunc );
			
			if (w2 == 1)
				plik << szyfroj(wyraz);
			else
				plik << odszyfroj(wyraz);

			if (powtorz == true)
				plik << "`";

			plik.close();
		
	}
				
			
}

string szyfroj(string wyraz)
{
	string kod;
	string pomoc;
	pomoc.reserve(1);
	fstream klucz;
	char pomocnicza;
	int ile;

	cout << "Podaj kod:  ";
	cin >> kod;

	klucz.open("klucz.txt", ios::out | ios::trunc );
	klucz << kod;
	klucz.close();


	for (int j = 0; j < kod.length(); j++)
	{
		
		pomoc = kod[j];
		ile = atoi(pomoc.c_str());
		if (ile == 0) continue;

		short c = wyraz.length() / ile,
			  d = wyraz.length() % ile,
			  e = ile,
			  i = 0;

		while (c)
		{

			pomocnicza = wyraz[ile - 1];
			wyraz.replace(i + 1, e - 1, wyraz, i, e - 1);
			wyraz[i] = pomocnicza;
			i += e, ile += e, c--;

		}

		if (d > 0)
		{
			pomocnicza = wyraz[wyraz.length() - 1];
			wyraz.replace(i + 1, d - 1, wyraz, i, d - 1);
			wyraz[i] = pomocnicza;

		}

	}

	return wyraz;
}

string odszyfroj(string wyraz)
{
	string kod;
	string pomoc;
	char pomocnicza;
	int ile;

	cout << "Podaj kod:  ";
	cin >> kod;

	for (int j = kod.length()-1; j >= 0; j--)
	{
		
		pomoc = kod[j];
		ile = atoi(pomoc.c_str());
		if (ile == 0) continue;

		short c = (wyraz.length()) / ile,
			d = (wyraz.length()) % ile,
			e = ile,
			i = 0;
	
		while (c)
		{

			pomocnicza = wyraz[i];
			wyraz.replace(i, e - 1, wyraz, i + 1, e - 1);
			wyraz[ile - 1] = pomocnicza;
			ile += e, i += e, c--;

		}

		if (d > 0)
		{

			pomocnicza = wyraz[i];
			wyraz.replace(i, d - 1, wyraz, i + 1, d - 1);
			wyraz[wyraz.length() - 1] = pomocnicza;

		}

	}
	
	return wyraz;
}
