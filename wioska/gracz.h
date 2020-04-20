#pragma once
#include "pch.h"
#include <iostream>
#include <windows.h>
#include <string>
#include "budynki.h"
#include<time.h>
using namespace std;

class gracz
{
public:
	friend class budynek;
	friend class tartak;
	friend class kamieniolom;
	friend class huta;
	friend class farma;
	friend class koszary;
	friend class mur;
	gracz()
	{
		drewno = 100;
		zelazo = 100;
		kamien = 100;
		zywnosc = 10;
		imie = "pusto";
	};

	void poczatek()
	{
		if (first == 0)
		{
			cout << "Witaj wodzu! Podaj swoje imie : ";
			cin >> imie;
		}
		system("cls");
		cout << "Plemie wielkiego " << imie << "a !!!" << endl;
		cout << "Twoje surowce:"; cout.width(10); cout << "drewno = " << drewno << " zelazo = " << zelazo << " kamien = " << kamien << " zywnosc = " << zywnosc << endl;
		cout << "Armia :"; cout.width(17); cout << " lucznicy=" << lucznicy << " pikinierzy=" << pikinierzy << endl;
		first = 1;
	};

private:
	double pikinierzy = 0;
	double lucznicy = 0;
	int first = 0;
	int drewno;
	int zelazo;
	int kamien;
	int zywnosc;
	double przeciwnik = 1;
	int i = 1;
	string imie;
};