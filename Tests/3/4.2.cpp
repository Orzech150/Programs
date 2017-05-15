#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    fstream plik("liczby.txt");
    string liczby[1000] = {};
    short dwa = 0, osiem = 0, pomoc;

    for( int i = 0; i < 1000; ++i)
    {
        plik >> liczby[i];
    }
    for( int i = 0; i < 1000; ++i)
    {
        pomoc = liczby[i].length();
        if((liczby[i])[pomoc-1] == 48)
            ++dwa;

        if((liczby[i])[pomoc-1] == 48 && (liczby[i])[pomoc-2] == 48 && (liczby[i])[pomoc-3] == 48)
            ++osiem;
    }
    cout << dwa << "  " << osiem;
    plik.close();
    getchar();
    getchar();

}
