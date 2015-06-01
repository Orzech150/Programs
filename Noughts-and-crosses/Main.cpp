#include "plansza.h"

short ruch = 0;
char tab[3][3] = {}; // x = krzyzyk stoi o = kolko stoi;
plansza pole;

ostream & operator<<(ostream & ekran, plansza & gra)
{
	ekran << gra.tresc;
	return ekran;
}

int main()
{
	ios_base::sync_with_stdio(false);
	short wybor;
	char wynik;
	pole.wypelnij();
	cout << pole << flush;
	while (true)
	{
		cout << "\n\n\n Prosze wybrac pole na ktorym chcesz postawic\n Pola sa ponumerowane jak na klawiaturze numerycznej\n\t\t\t" << endl;
		
		do{
			cin >> wybor;
		} while (wybor < 1 || wybor > 9 || tab[(wybor-1)/3][(wybor-1)%3] != NULL );
		ruch++;
		
		if (ruch % 2 == 0)
			pole.rysuj_kolko(wybor);
		else
			pole.rysuj_krzyzyk(wybor);

		system("cls");

		cout << pole << flush;
		pole.zapisz_ruch(wybor);
		wynik = pole.sprawdz();
		if (wynik)
			pole.koniec(wynik);
			
	}
}
