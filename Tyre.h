#ifndef TYRE_H
#define TYRE_H

#include <cstring>
#include <iostream>
#include <fstream>


// класс моделирующий описание одной шины, которая может быть частью списка
class Tyre
{
	char* marka;				// марка шины 
	float price;				// цена шины
	float shirina_profila;			// ширина профиля шины
	float diam;				// диаметр шины 
	float visota_profila;			// высота профиля шины 
	int winter;				// признак сезона 1-зима, 0-лето
	Tyre *next_ty;				// указатель на следующий элемент
public:

	Tyre()
	{
		next_ty = 0;			// нет следующего элемента
		marka = 0;			// нет текущего элемента
		price = 0;
		shirina_profila = 0;
		diam = 0;
		visota_profila = 0;
		winter = 0;
	}
	Tyre(char* m, float pr, float sh, float dm, float vis, int w)
	{
		marka = new char[strlen(m) + 1];
		strcpy(marka, m);
		price = pr;
		shirina_profila = sh;
		diam = dm;
		visota_profila = vis;
		winter = w;
		next_ty = 0;
	}
	~Tyre()
	{
		delete[]marka;
	}
	Tyre(const Tyre &nt)// конструктор копий
	{
	marka = new char[strlen(nt.marka) + 1];
	strcpy(marka, nt.marka);
	price = nt.price;
	shirina_profila = nt.shirina_profila;
	diam = nt.diam;
	visota_profila = nt.visota_profila;
	winter = nt.winter;
	next_ty = nt.next_ty;
	}
	Tyre* GetNext()
	{
		return next_ty;// возвращается указатель на следующий элемент списка
	}
	float GetPrice()				// цена шины
	{
		return price;
	}
	float GetShirina_Profila()		// ширина профиля шины
	{
		return shirina_profila;
	}
	float GetDiam()					// диаметр шины 
	{
		return diam;
	}
	float GetVisota_profila()		// высота профиля шины 
	{
		return visota_profila;
	}
	int GetWinter()					// признак сезона 1-зима, 0-лето
	{
		return winter;
	}
	void SetNext(Tyre* nxt)    // задание следующего элемента для данного
	{
		next_ty = nxt;
	}
	char* GetMarka()
	{
		return marka;
	}

	friend 	Tyre* ReadBD(std::ifstream& file);
};


#endif
