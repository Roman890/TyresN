#include "ListTyre.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void ListTyre::Delet()

{// эта функция удаляет элементы 
	int i;
	std::cout << "\t По какому признаку будем удалять элемент списка? \n";
	std::cout << "1 : Удаление по марке шины\n";
	std::cout << "2 : Удаление по цене шины\n";
	std::cout << "Поле для ввода: ";
	std::cin >> i;
	switch (i)
	{
	case 1:// удаление по марке
	{
		char m[30];
		Tyre* start = first_elem;                      // указатель на первый элемент списка
		std::cout << "Введите удаляемую марку\n";
		std::cin >> m;
		Tyre* p = start;
		if (strcmp(m, p->GetMarka()) == 0)   // удаляется первый элемент списка
		{
			if (p->GetNext() != NULL)		        // Первый элемент - не единственный
				first_elem = p->GetNext();
			else
				first_elem = NULL;       // список будет пустой
			delete[]p->GetMarka();       // освобождаем память
			return;
		}
		else if (p->GetNext() == NULL)// список состоит из одного элемента
		{
			return;
		}

		while (p->GetNext() != NULL)// поиск удаляемого звена внутри списка
		{
			if (strcmp(m, p->GetNext()->GetMarka()) == 0 && p->GetNext()->GetNext() != NULL)// нашли удаляемое звено
			{// p указывает на звено предшествующее удаляемому, удалется не последнее звено 
				start = p->GetNext()->GetNext();		// запоминаем указатель на следующее за удаляемым звеном
				char* pdm = p->GetNext()->GetMarka();
				delete[]pdm;	
				Tyre* pdelel = p->GetNext();
				p->SetNext(start);
				return;										// выход из цикла  и функции 
			}
			start = p;
			p = p->GetNext();
		}
		// проверка последнего звена
		if ((strcmp(m, p->GetMarka()) == 0))// надо удалить последнее звено
		{
			delete[](p->GetMarka()); // Удаление строки с маркой машины
			start->SetNext(NULL);
			return;
		}
	}
	case 2:// удаление по цене
	{
		float pr;
		Tyre* start = first_elem;                      // указатель на первый элемент списка
		std::cout << "Введите удаляемую цену\n";
		std::cin >> pr;
		Tyre* p = start;
		if (pr == p->GetPrice())   // удаляется первый элемент списка
		{

			if (p->GetNext() != NULL)		        // Первый элемент - не единственный
				first_elem = p->GetNext();
			else
				first_elem = NULL;       // список будет пустой
			delete[]p->GetMarka();       // освобождаем память
			return;
		}
		else if (p->GetNext() == NULL)// список состоит из одного элемента
		{
			return;
		}

		while (p->GetNext() != NULL)// поиск удаляемого звена внутри списка
		{
			if (pr == p->GetNext()->GetPrice() && p->GetNext()->GetNext() != NULL)// нашли удаляемое звено
			{// p указывает на звено предшествующее удаляемому, удалется не последнее звено 
				start = p->GetNext()->GetNext();		// запоминаем указатель на следующее за удаляемым звеном
				char* pdm = p->GetNext()->GetMarka();
				delete[]pdm;	
				Tyre* pdelel = p->GetNext();
				p->SetNext(start);
				return;										// выход из цикла  и функции 
			}
			start = p;
			p = p->GetNext();
		}
		// проверка последнего звена
		if (pr == p->GetPrice())// надо удалить последнее звено
		{
			delete[](p->GetMarka());
			start->SetNext(NULL);
			return;
		}
	}
	default:
		std::cout << "Некорректная команда. Повторите ввод" << std::endl;
	}
}
