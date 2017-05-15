#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    fstream plik("liczby.txt");
    string liczby[1000];
    short dlugosc[1000], maxymalne[1000], minimalne[1000];
    short max, min, ile_max = 0, ile_min = 0;

    for(int i = 0; i < 1000; ++i)
    {
        getline(plik, liczby[i], '\n');
        dlugosc[i] = liczby[i].length();
    }

    max = dlugosc[0];
    min = dlugosc[0];
    for( int i = 1; i < 1000; ++i)
    {
        if( dlugosc[i] > max )
            max = dlugosc[i];

        if( dlugosc[i] < min )
            min = dlugosc[i];
    }
    int g = 0, j = 0;
    for( int i = 0; i < 1000; ++i)
    {
        if( dlugosc[i] == max )
        {
            maxymalne[g++] = i;
            ++ile_max;
        }

        if( dlugosc[i] == min )
        {
            minimalne[j++] = i;
            ++ile_min;
        }
    }

    if( ile_max == 1 )
        cout << liczby[maxymalne[0]] << "  ";

    if( ile_min == 1 )
        cout << liczby[minimalne[0]] << "  ";

    cout << "Ile max: " << ile_max << endl;
    cout << "Ile min: " << ile_min << endl;

    int suma, p, najwieksza = 0, najmniejsza = 0, ktory_max = 0, ktory_min = 0;
    if( ile_max > 1 )
    {
        for( int i = 0; i < ile_max; ++i)
        {
            suma = 1, p = 1;
            while(true){
                if( (liczby[maxymalne[i]])[p++] == 49 )
                    suma+=1;
                else if ( suma > najwieksza )
                    {
                        najwieksza = suma;
                        ktory_max = maxymalne[i];
                        break;
                    }
                else
                    break;
            }
        }
    }

    if( ile_min > 1 )
    {
        for( int i = 0; i < ile_min; ++i)
        {
            suma = 1, p = 1;
            while(true){
                if( (liczby[minimalne[i]])[p++] == 48 )
                    suma+=1;
                else if ( suma > najmniejsza )
                    {
                        najmniejsza = suma;
                        ktory_min = minimalne[i];
                        break;
                    }
                else
                    break;
            }
        }
    }

    cout << "Max w linijce: " << ktory_max+1 << " i ma on wartosc:\n" << liczby[ktory_max] << endl;
    cout << "Min w linijce: " << ktory_min+1 << " i ma on wartosc:\n" << liczby[ktory_min] << endl;

    getchar();
    getchar();
}
