#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "ListTyre.h"
#include <locale.h>
#include <string>

using namespace std;



int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");

	cout << "База Данных обеспечивает работу с несколькими списками.\n Первоначально загружается основной список.\n";
	ListTyre mylist;		// список шин, исходный
	menu(argv[1],mylist);		// если файл есть, чтение информации из файла; если нет- создается новый список, отображается меню
					// организует бесконечный цикл, пока не введено значение 6.
	ListTyre winterlist = mylist;	// список шин для зимы
	cout << "Зделана копия базы данных\n";
	cout << "Введите имя файла, куда будет помещена копия: ";
	//char namecopybd[30];	// строка для названия файла БД
	string namecopybd;	// строка для названия файла БД
	cin >> namecopybd;
	menu((namecopybd.c_str()), winterlist); // если файл есть, чтение информации из файла; если нет- создается новый список, отображается меню
						// организует бесконечный цикл, пока не введено значение 6.
	cout << "В дальнейшем можно создавать неограниченное количество списков.\n";
	cout << "Завершение работы...\n";
	return 0;
}
