#include "ListTyre.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <math.h>


// Добавить одну шину
void ListTyre::Dop()
{
	char m[30];
	float pr, sh, dm, vis;
	int w;

	std::cout << "Введите марку шины :";
	std::cin >> m;
	std::cout << "Цена шины : ";
	std::cin >> pr;
	std::cout << "Ширина профиля шины : ";
	std::cin >> sh;
	std::cout << "Диаметр шины : ";
	std::cin >> dm;
	std::cout << "Высота профиля шины : ";
	std::cin >> vis;
	std::cout << "Признак сезона 1-зима, 0-лето :";
	std::cin >> w;
	Tyre* q = new Tyre(m, pr, sh, dm, vis, w);       // указателю q на добавленный в список элемент
	Tyre* p = first_elem;	      			 // Запоминаем указатель на начало списка
	if (p != NULL){
		while (p->GetNext() != NULL)  		 // получение указателя p на последний элемент списка
			p = p->GetNext();
		// p - указатель на последний элемент списка
		// Выделение памяти под новую шину

		p->SetNext(q);				 // Указатель на вновь созданную шину
	}
	else
		first_elem = q;

}
