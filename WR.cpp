#include "ListTyre.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <math.h>



void ListTyre::RecBD(std::ofstream& f)
{// Запись списка в файл
	int n, t;
	float d;
	Tyre* p = first_elem;
	while (1)
	{
		n = strlen(p->GetMarka());
		f.write((char*)(&n), sizeof(int));				// запись длины строки с названием марки
		f.write(p->GetMarka(), strlen(p->GetMarka())); 			// запись марки
		d = p->GetPrice();
		f.write((char*)&d, sizeof(float));				// цена
		d = p->GetDiam();
		f.write((char*)&d, sizeof(float));				// диаметр
		d = p->GetShirina_Profila();
		f.write((char*)&d, sizeof(float));				// профиль
		d = p->GetVisota_profila();
		f.write((char*)&d, sizeof(float));				// профиль
		t = p->GetWinter();
		f.write((char*)&t, sizeof(int));				// сезон
		if (p->GetNext() != NULL)
			p = p->GetNext();
		else
			break;
	}
}


////////////////////////////////////////////////////////////////////////////
/// Чтение из файла сведений о шине
////////////////////////////////////////////////////////////////////////////

Tyre* ReadBD(std::ifstream& file)	// чтение одного набора из фмйла
{
	int t;
	file.read((char*)&t, sizeof(int));	// длина строки с нозванием марки шины
	if (file.eof() == true)			// Достигнут конец файла
		return 0;
	Tyre* f = new Tyre;		
	f->marka = new char[t + 1];      // выделение памяти под название
	file.read(f->marka, t);          // f->marka содержит адрес памяти по которому надо записать, прочитанную из файла шины
	f->marka[t] = 0;                 // фиксируем признак конца строки
	file.read((char*)&(f->price), sizeof(float));
	file.read((char*)&(f->diam), sizeof(float));
	file.read((char*)&(f->shirina_profila), sizeof(float));
	file.read((char*)&(f->visota_profila), sizeof(float));
	file.read((char*)&(f->winter), sizeof(int));
	f->next_ty = NULL;
	return f;
}

////////////////////////////////////////////////////////////////////////////
/// Чтение из файла сведений о списке шин
////////////////////////////////////////////////////////////////////////////

Tyre* ListTyre::ReadListBD(std::ifstream& file)
{// чтение,  заполнение пустого списка
	Tyre* forlastelem;			// Указатель на предпоследний элемент списка
	Tyre* lastelem;				// Указатель на последний элемент списка
	bool begin = true;			// приступаем к чтению
	while (!file.eof())// если файл не пустой 
	{
		if (begin) {			// Чтение первого элемента списка
			lastelem = ReadBD(file);// запоминаем адрес первого элемента
			first_elem = lastelem;	// в firstelem запоминаем адрес первого элемента списка
			begin = false;		// запоминаем, что первое чтение состоялось
		}
		forlastelem = lastelem;		// запоминаем указатель на только что прочитанный элемент списка
		lastelem = ReadBD(file);	// чтение следующего элемента списка
		if (lastelem == 0)		// если прочитать не удалось
			break;		// Выход из цикла
		forlastelem->SetNext(lastelem);// запоминем, что элемент forlastelem ссылается на добаленный в список элемент lastelem
	}
	return first_elem;
}
