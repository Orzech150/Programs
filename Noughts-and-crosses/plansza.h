#pragma once
/* W przypadku innego kompilatora niz M$ należy użyć:
#ifndef PLANSZA_H
#define PLANSZA_H
-kod programu-
endif
*/
#include <string>
#include <iostream>
#include <Windows.h>

using namespace std;

extern short ruch;
extern char tab[3][3];

class plansza
{
	string tresc;
public:
	plansza();
	
	void wyswietl();
	void rysuj_kolko(short);
	void rysuj_krzyzyk(short);
	char sprawdz();
	void koniec(char);
	void zapisz_ruch(short);
	void wypelnij();
};
