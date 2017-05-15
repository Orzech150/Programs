#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream plik;
    plik.open("slowa.txt");
    string tab[1000], tab_1[1000];
    short zera = 0, maximum = 0, ilosc = 0, k = 0;

    for(int i =0; i < 1000; ++i)
    {
        plik >> tab[i];
    }

    for( int i = 0; i < 1000; ++i)
    {
        for( int j = 0; j < tab[i].length(); ++j)
        {
            if((tab[i])[j] == 48) // 48 to wartosc ASCII dla 0
            {
                zera++;
                // Jesli jest to ostatnia cyfra i jest wiecej zer
                if (j == tab[i].length()-1 && zera > maximum)
                {
                    maximum = zera;
                    zera = 0;
                }
            }
            else if ( zera > maximum )
            {
                maximum = zera;
                zera = 0;
            }
            else
            {
                zera = 0;
            }
        }
        zera = 0;
    }

    for( int i = 0; i < 1000; ++i)
    {
        for( int j = 0; j < tab[i].length(); ++j)
        {
            if((tab[i])[j] == 48)
            {
                zera++;
                // Jesli liczba zer rowna sie naszemu maximum
                if( zera == maximum)
                {
                    tab_1[k++] = tab[i];
                    ++ilosc;
                    break;
                }
            }
            else
                zera = 0;
        }
        zera = 0;
    }

    cout << maximum << endl;
    for( int i = 0; i < ilosc; ++i)
    {
        cout << tab_1[i] << endl;
    }


}
