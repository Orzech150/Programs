#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

int main()
{
	srand(time(NULL));
	bool isSmall = false, isBig = false, isSpecial = false, isDigit = false;
	string password;
	short quantity, length;
	char check;
	bool file;
	fstream plik;

	char special[] = { 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
		58, 59, 60, 61, 62, 63, 64, 91, 92, 93, 94, 95, 96, 123, 124, 125, 126 };

	cout << "Ile hasel wygenerowac? ";
	cin >> quantity;
	cout << "Jak dlugie maja byc hasla? ";
	do{
		cin >> length;
		if (length < 8)
			cout << "Haslo musi miec conajmniej 8 znakow!";
	}
	while (length < 8);
	cout << "Zapisac hasla do pliku? (1 - Tak 0 - Nie) ";
	cin >> file;
	if (file)
        plik.open("Passwords.txt", ios::app | ios::out);

	for (int i = 1; i <= quantity; ++i)
	{
		for (int j = 0; j < length; ++j)
		{
			check = !isSmall + !isBig + !isDigit + !isSpecial;
			if (length - password.length() > check)
			{
				switch (rand() % 6 + 1) // 1-2 small letters 3-4 big letters 5 - digits - 6 specials
				{
				case 1:
				case 2:
					password += rand() % 26 + 97;
					isSmall = true;
					break;
				case 3:
				case 4:
					password += rand() % 26 + 65;
					isBig = true;
					break;
				case 5:
					password += rand() % 10 + 48;
					isDigit = true;
					break;
				case 6:
					password += special[rand() % 32 + 0];
					isSpecial = true;
					break;
				}
			}
			else if (isSmall == false)
			{
				password += rand() % 26 + 97;
				isSmall = true;
			}
			else if (isBig == false)
			{
				password += rand() % 26 + 65;
				isBig = true;
			}
			else if (isSpecial == false)
			{
				password += special[rand() % 32 + 0];
				isSpecial = true;
			}
			else if (isDigit == false)
			{
				password += rand() % 10 + 48;
				isDigit = true;
			}
		}

		cout << " Nr " << i << " -  " << password << endl;
		if( file )
        	{
            		password += '\n';
            		plik << " Nr " << i << " -  " << password;
        	}
		password.clear();
		isSmall = false, isBig = false, isSpecial = false, isDigit = false;

	}
	getchar();
	getchar();
}
