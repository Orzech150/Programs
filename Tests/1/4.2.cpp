#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    fstream plik("slowa.txt");
    string liczby[1000] = {};
    short pomoc = 0, wynik = 0;

    // Wczytaj wszystkie liczby do tablicy string
    for( int i = 0; i < 1000; ++i)
    {
        plik >> liczby[i];
    }

    for( int i = 0; i < 1000;  ++i)
    {
        for(int j = 0; j < liczby[i].length()-1; ++j)
        {
            // Jesli pierwsza cyfra to 1 to odpada od razu
            if((liczby[i])[0] == 49)
                break;

            // Wyszukiwanie "skoku" z 0 do 1
            if((liczby[i])[j] != (liczby[i])[j+1])
                ++pomoc;
        }
        // Jesli skok byl tylko jeden to liczba spelnia wymagania
        if(pomoc == 1)
            ++wynik;
        pomoc = 0;
    }
    cout << wynik;

    plik.close();
    getchar();
    getchar();
}
