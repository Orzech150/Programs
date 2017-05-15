#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    fstream plik;
    plik.open("slowa.txt");
    string liczby[1000] = {};
    short jedynki = 0, zera = 0, wynik = 0;

    // Wczytanie wszystkich liczb do tablicy string
    for( int i = 0; i < 1000; ++i)
    {
        getline(plik, liczby[i], '\n');
    }

    for( int i = 0; i < 1000; ++i)
    {
        for( int k = 0; k < liczby[i].length(); ++k)
        {
            if((liczby[i])[k] == 48) // 48 to wartosc ASCII dla 0
                ++zera;
            else
                ++jedynki;
        }
        if( zera > jedynki )
            ++wynik;

        zera = 0; jedynki = 0;
    }
    cout << wynik;

    plik.close();
    getchar();
    getchar();
}
