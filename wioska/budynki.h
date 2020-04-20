#pragma once
#include "pch.h"
#include <iostream>
#include <windows.h>
#include <string>
#include<time.h>
#include"gracz.h"
using namespace std;


class budynek
{
public:
	void virtual przyrost(gracz *gr) {};
	void virtual atak(gracz *gr) {};
	friend class gracz;
	budynek()
	{
		nazwa = "pusto";
		level = 0;
		koszt_drewna = 0;
		koszt_zelaza = 0;
		koszt_kamienia = 0;
		produkcja = 0;
		obrona = 1;
		produkcja_jedzenia = 5;
	};
	void wypisz()
	{
		cout << "Nazwa budynku :";
		cout.width(12);
		if (nazwa == "Mur")cout << nazwa << " level :" << level << " Poziom Obrony =" << obrona << endl;
		else if (produkcja == 0)cout << nazwa << " level :" << level << endl;
		else cout << nazwa << " level :" << level << " produkcja: " << produkcja << endl;
	};
	void buduj(gracz *gr)
	{
		int b;
		system("cls");
		cout << "Twoje surowce drewno=" << gr->drewno << " kamien=" << gr->kamien << " zelazo=" << gr->zelazo << endl;
		cout << "Nazwa budynku :";
		cout.width(12);
		if (produkcja == 0)cout << nazwa << " level :" << level << " Cena budowy: drewno=" << koszt_drewna << " zelazo=" << koszt_zelaza << " kamien=" << koszt_kamienia << endl;
		else cout << nazwa << " level :" << level << " produkcja: " << produkcja << " Cena budowy: drewno=" << koszt_drewna << " zelazo=" << koszt_zelaza << " kamien=" << koszt_kamienia << endl;
		cout << "1.Buduj" << endl;
		cout << "2.Cofnij" << endl;
		cout << "Podaj liczbe:";
		cin >> b;
		if (b != 1 && b != 2)
		{
			cout << "Podales zla liczbe!!!\nPodaj liczbe: ";
			cin >> b;
		}
		if (b == 1)
		{
			if (koszt_drewna <= gr->drewno && koszt_kamienia <= gr->kamien && koszt_zelaza <= gr->zelazo)
			{
				gr->drewno -= koszt_drewna;
				gr->kamien -= koszt_kamienia;
				gr->zelazo -= koszt_zelaza;
				level++;
				koszt_drewna += koszt_kamienia;
				koszt_kamienia += koszt_kamienia;
				koszt_zelaza += koszt_zelaza;
				obrona += 0.5;
				if (produkcja != 0)produkcja += produkcja;
				if (produkcja_jedzenia == 5) gr->zywnosc += 5;
				cout << "Udalo ci sie ulepszyc " << nazwa << " na " << level << " level!";
				Sleep(1500);
			}
			else cout << "za malo surowcow!";
			Sleep(1500);
			system("cls");
		}
		if (b == 2)system("cls");
	};
	void virtual rekrutuj(gracz *gr) {};
protected:
	string nazwa;
	int level;
	int koszt_drewna;
	int koszt_zelaza;
	int koszt_kamienia;
	int produkcja;
	double obrona=1;
	int produkcja_jedzenia = 5;
};

class tartak : public budynek
{
public:
	void przyrost(gracz *gr)
	{
		gr->drewno += produkcja;
	};
	tartak()
	{
		nazwa = "Tartak";
		level = 1;
		koszt_drewna = 40;
		koszt_zelaza = 40;
		koszt_kamienia = 40;
		produkcja = 10;
	};
};

class ratusz : public budynek
{
public:
	ratusz()
	{
		nazwa = "Ratusz";
		level = 1;
		koszt_drewna = 100;
		koszt_zelaza = 100;
		koszt_kamienia = 100;
		produkcja = 0;
	};
};

class farma : public budynek
{
public:
	void przyrost(gracz *gr)
	{
		gr->zywnosc += produkcja;
	};
	farma()
	{
		nazwa = "Farma";
		level = 1;
		koszt_drewna = 30;
		koszt_zelaza = 10;
		koszt_kamienia = 30;
		produkcja_jedzenia = 5;
	};
protected:
	int produkcja_jedzenia;
};

class koszary : public budynek
{
public:
	void rekrutuj(gracz *gr)
	{
		if (level == 0) 
		{
			cout << "Musisz zbudowac koszary!" << endl;
			Sleep(2000);
			goto koszary1;
		}
		int r;
		cout << "Kogo chcesz rekrutowac? Kazda jednostka kosztuje 1 zywnosci." << endl;
		cout << "1.Lucznik koszt 15 drewna i 10 zelaza" << endl;
		cout << "2.Pikinier koszt 20 drewna i 5 zelaza" << endl;
		cin >> r;
		if (r != 1 && r != 2)
		{
			cout << "Podales zla liczbe!!!\nPodaj liczbe: ";
			cin >> r;
		}
		if (r == 1 && gr->zywnosc > 0 && gr->zelazo >= 10 && gr->drewno >= 15)
		{
			gr->lucznicy++;
			gr->zywnosc--;
			gr->zelazo -= 10;
			gr->drewno -= 15;
		}else if (r == 2 && gr->zywnosc > 0 && gr->zelazo >= 5 && gr->drewno >= 20)
		{
			gr->pikinierzy++;
			gr->zywnosc--;
			gr->zelazo -= 5;
			gr->drewno -= 20;
		}
		else { cout << "Za malo masz surowcow ."; Sleep(1000); };
	koszary1:;
	};
	koszary()
	{
		nazwa = "Koszary";
		level = 0;
		koszt_drewna = 100;
		koszt_zelaza = 100;
		koszt_kamienia = 100;
		produkcja = 0;
	};
};

class kamieniolom : public budynek
{
public:
	void przyrost(gracz *gr)
	{
		gr->kamien += produkcja;
	};
	kamieniolom()
	{
		nazwa = "Kamieniolom";
		level = 1;
		koszt_drewna = 50;
		koszt_zelaza = 20;
		koszt_kamienia = 30;
		produkcja = 10;
	};
};

class huta : public budynek
{
public:
	void przyrost(gracz *gr)
	{
		gr->zelazo += produkcja;
	};
	huta()
	{
		nazwa = "Huta";
		level = 1;
		koszt_drewna = 50;
		koszt_zelaza = 20;
		koszt_kamienia = 30;
		produkcja = 10;
	};
};

class mur : public budynek
{
public:
	friend class gracz;
	void atak(gracz *gr)
	{
		system("cls");
		cout << "Atakuje cie " << gr->przeciwnik * 2 << " jednostek!" << endl;
		if ((gr->pikinierzy + gr->lucznicy)* (obrona) < gr->przeciwnik)
		{
			cout << "Przykro nam , polegles na " << gr->i << " fali! Koniec gry" << endl;
			Sleep(3000);
			exit(1);
		}
		else cout << "Udolo ci sie odeprzec  " << gr->i << " atak!" << endl;
		Sleep(3000);
		gr->przeciwnik *= 2;
		gr->i++;
	}
	mur()
	{
		nazwa = "Mur";
		level = 0;
		koszt_drewna = 80;
		koszt_zelaza = 40;
		koszt_kamienia = 50;
		produkcja = 0;
		obrona = 1;
	};
private:
	double obrona;
};