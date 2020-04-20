#include "pch.h"
#include <iostream>
#include <windows.h>
#include<chrono>
#include <string>
#include<time.h>
#include"budynki.h"
#include "gracz.h" ////SFML biblioteka graficzna
using namespace std;

int a = 1;
int liczba_dni = 1;
void My_interface(budynek *R, budynek *F, budynek *K, budynek *KM, budynek *T, budynek *H, budynek *M, gracz *gr);

int main()
{
	gracz *gr;
	gr = new gracz;
	gr->poczatek();
	budynek *R, *F, *K, *KM, *T, *H, *M;
	R = new ratusz;
	F = new farma;
	K = new koszary;
	KM = new kamieniolom;
	T = new tartak;
	H = new huta;
	M = new mur;

	My_interface(R, F, K, KM, T, H, M, gr);

	return 0;
}

void My_interface(budynek *R, budynek *F, budynek *K, budynek *KM, budynek *T, budynek *H, budynek *M, gracz *gr)
{
buduj1:
	gr->poczatek(); R->wypisz();K->wypisz(); M->wypisz(); F->wypisz(); KM->wypisz(); T->wypisz(); H->wypisz();
	cout << endl;
	int liczba, liczba2;
	cout << "\nDzien numer "<<liczba_dni<<" Atak nastapi za " << 10 - a << " dni" << endl;
	cout << endl;
	cout << "1.Buduj" << endl;
	cout << "2.Rekrutuj" << endl;
	cout << "3.Odswiez" << endl;
	cout << "4.Wyjscie" << endl;

	cout << "Podaj liczbe: ";
	cin >> liczba;
	if (liczba != 1 && liczba != 2 && liczba != 3 && liczba != 4 )
	{
		cout << "Podales zla liczbe!!!\nPodaj liczbe: ";
		cin >> liczba;
	}

	switch (liczba)
	{
	case 1:
		system("cls");
		cout << "1.Ratusz" << endl;
		cout << "2.Farma" << endl;
		cout << "3.Koszary" << endl;
		cout << "4.Kamieniolom" << endl;
		cout << "5.Tartak" << endl;
		cout << "6.Huta" << endl;
		cout << "7.Mur" << endl;
		cout << "Podaj liczbe: ";
		cin >> liczba2;
		if (liczba2 != 1 && liczba2 != 2 && liczba2 != 3 && liczba2 != 4 && liczba2 != 5 && liczba2 != 6 && liczba2 != 7)
		{
			cout << "Podales zla liczbe!!!\nPodaj liczbe: ";
			cin >> liczba2;
		}

		switch (liczba2)
		{
		case 1:
			R->buduj(gr);
			goto buduj1;
			break;
		case 2:
			F->buduj(gr);
			goto buduj1;
			break;
		case 3:
			K->buduj(gr);
			goto buduj1;
			break;
		case 4:
			KM->buduj(gr);
			goto buduj1;
			break;
		case 5:
			T->buduj(gr);
			goto buduj1;
			break;
		case 6:
			H->buduj(gr);
			goto buduj1;
			break;
		case 7:
			M->buduj(gr);
			goto buduj1;
			break;
		}
		break;

	case 2:
		cout << "Rekrutacja!" << endl;
		Sleep(1000);
		K->rekrutuj(gr);
		goto buduj1;
		break;
	case 3:
		cout << "Odswiezanie!!!";
		Sleep(1000);
		T->przyrost(gr);
		KM->przyrost(gr);
		H->przyrost(gr);
		if (a == 10)
		{
			M->atak(gr);
			a = 0;
		}
		a++;
		goto buduj1;
		break;
	case 4:
		cout << "Wyjscie z gry!" << endl;
		Sleep(500);
		exit(1);
		break;
	}
}