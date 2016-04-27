#ifndef LIST_TYRE_H
#define LIST_TYRE_H

#include "Tyre.h"
class ListTyre // класс моделирующий односвязный список шин
{
	Tyre* first_elem;	// указатель на первый элемент списка 
public:
	ListTyre()// конструктор по умолчанию создает пустой спискок
	{
		first_elem = 0;
	}
	ListTyre(Tyre* f_e)// конструктор, создающий список из одного элемента
	{
		first_elem = f_e;
	}
	void Dop();				//функция добавления
	Tyre* ReadListBD(std::ifstream& file);	//функция чтения из файла 
	void FindBD();				//функция поиска
	void ShowBD();				//функция просмотра
	void RecBD(std::ofstream& f);		//функция записи в файл
	void Delet();
};

void menu(const char* fil, ListTyre &NList);	// fil - имя файла

#endif
