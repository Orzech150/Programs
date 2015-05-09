#include "plansza.h"


plansza::plansza()
{
	tresc.reserve(1380);
}

void plansza::rysuj_kolko(short wybor)
{
	int i;
	switch (wybor)
	{
	case 7:
		i = 51;
		break;
	case 8:
		i = 66;
		break;
	case 9:
		i = 81;
		break;
	case 4:
		i = 511;
		break;
	case 5:
		i = 526;
		break;
	case 6:
		i = 541;
		break;
	case 1:
		i = 971;
		break;
	case 2:
		i = 986;
		break;
	case 3:
		i = 1001;
		break;
	}


	tresc.replace(i, 4, 4, 'o');
	tresc.replace(i + 44, 2, 2, 'o');
	tresc.replace(i + 50, 2, 2, 'o');
	tresc.replace(i + 88, 2, 2, 'o');
	tresc.replace(i + 98, 2, 2, 'o');

	tresc.replace(i + 134, 1, 1, 'o');
	tresc.replace(i + 145, 1, 1, 'o');

	tresc.replace(i + 180, 2, 2, 'o');
	tresc.replace(i + 190, 2, 2, 'o');
	tresc.replace(i + 228, 2, 2, 'o');
	tresc.replace(i + 234, 2, 2, 'o');
	tresc.replace(i + 276, 4, 4, 'o');

}

void plansza::rysuj_krzyzyk(short wybor)
{
	int i;
	switch (wybor)
	{
	case 7:
		i = 47;
		break;
	case 8:
		i = 62;
		break;
	case 9:
		i = 77;
		break;
	case 4:
		i = 507;
		break;
	case 5:
		i = 522;
		break;
	case 6:
		i = 537;
		break;
	case 1:
		i = 967;
		break;
	case 2: 
		i = 982;
		break;
	case 3:
		i = 997;
		break;
	}


	tresc.replace(i, 1, 1, 'x');
	tresc.replace(i + 12, 1, 1, 'x');
	tresc.replace(i + 48, 1, 1, 'x');
	tresc.replace(i + 56, 1, 1, 'x');
	tresc.replace(i + 96, 1, 1, 'x');
	tresc.replace(i + 100, 1, 1, 'x');

	tresc.replace(i + 144, 1, 1, 'x');

	tresc.replace(i + 188, 1, 1, 'x');
	tresc.replace(i + 192, 1, 1, 'x');
	tresc.replace(i + 232, 1, 1, 'x');
	tresc.replace(i + 240, 1, 1, 'x');
	tresc.replace(i + 276, 1, 1, 'x');
	tresc.replace(i + 288, 1, 1, 'x');

}

void plansza::wyswietl()
{
	cout << tresc;
}

char plansza::sprawdz()
{
	// Poziomo - x
	if ((tab[0][0] == 'x' && (tab[0][1] == 'x' && tab[0][2] == 'x')) || (tab[1][0] == 'x' && (tab[1][1] == 'x' && tab[1][2] == 'x')) || (tab[2][0] == 'x' && (tab[2][1] == 'x' && tab[2][2] == 'x')))
		return 'x';
	// Poziomo - o
	if ((tab[0][0] == 'o' && (tab[0][1] == 'o' && tab[0][2] == 'o')) || (tab[1][0] == 'o' && (tab[1][1] == 'o' && tab[1][2] == 'o')) || (tab[2][0] == 'o' && (tab[2][1] == 'o' && tab[2][2] == 'o')))
		return 'o';
	// Pionowo - x
	if ((tab[0][0] == 'x' && (tab[1][0] == 'x' && tab[2][0] == 'x')) || (tab[0][1] == 'x' && (tab[1][1] == 'x' && tab[2][1] == 'x')) || (tab[0][2] == 'x' && (tab[1][2] == 'x' && tab[2][2] == 'x')))
		return 'x';
	// Pionowo - o
	if ((tab[0][0] == 'o' && (tab[1][0] == 'o' && tab[2][0] == 'o')) || (tab[0][1] == 'o' && (tab[1][1] == 'o' && tab[2][1] == 'o')) || (tab[0][2] == 'o' && (tab[1][2] == 'o' && tab[2][2] == 'o')))
		return 'o';
	// Po skosie - x
	if ((tab[0][0] == 'x' && (tab[1][1] == 'x' && tab[2][2] == 'x')) || (tab[0][2] == 'x' && (tab[1][1] == 'x' && tab[2][0] == 'x')))
		return 'x';
	// Po skosie - o
	if ((tab[0][0] == 'o' && (tab[1][1] == 'o' && tab[2][2] == 'o')) || (tab[0][2] == 'o' && (tab[1][1] == 'o' && tab[2][0] == 'o')))
		return 'o';
	// Czy wszystkie pelne
	if (ruch == 9)
		return 'r';

	return false;
}

void plansza::koniec(char wynik)
{
	switch (wynik)
	{
	case 'x':
		cout << "\n\t Wygral gracz nr 1 - Gratuluje!";
		break;
	case 'o':
		cout << "\n\t Wygral gracz nr 2 - Gratuluje!";
		break;
	case 'r':
		cout << "\n\t\t    Remis!";
	}
	
	Sleep(2200);
	wypelnij();
	ruch = 0;
	for (int i = 0; i < 9; ++i)
	{
		tab[i / 3][i % 3] = 0;
	}
	system("cls");
	wyswietl();

}

void plansza::zapisz_ruch(short wybor)
{
	char znak;
	if (ruch % 2 == 0)
		znak = 'o';
	else
		znak = 'x';

	tab[(wybor-1) / 3][(wybor-1) % 3] = znak;
}

void plansza::wypelnij()
{
	tresc.assign(1380, ' ');

	short j = 15, k = 30, l = 46;

	for (int i = 1; i <= 30; ++i)
	{

		if (i == 10 || i == 20)
		{
			tresc.replace(46 * (i - 1), 45, 45, '*');
		}
		else
		{
			tresc.replace(j - 1, 1, 1, '*');
			tresc.replace(k - 1, 1, 1, '*');
		}

		tresc[l - 1] = '\n';

		j += 46; k += 46; l += 46;

	}
}
