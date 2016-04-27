#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "ListTyre.h"


void menu(const char* fil, ListTyre &NList)					// fil - имя файла
{// строка с именем файла
	int  d;
	std::ifstream infile(fil);
	if (infile.good() == false)// если файла нет
	{
		NList.Dop();// добавление шины в список в оперативной памяти
		std::ofstream offile(fil);
		if (offile.good() == true)
			printf("Файл БД создан.\n");
		NList.RecBD(offile);
		offile.close();
		infile.open(fil);
		if (infile.good() == true)
			printf("БД подключена\n");
	}
	NList.ReadListBD(infile);// чтение из файла в оператиную память списка шин
	infile.close();
	while (1)
	{
		std::cout << " -----------------База данных: КАТАЛОГ ШИН -----------------\n";
		std::cout << "| База данных из файла : " << fil << "                     |\n";
		std::cout << "|                                                          |\n";
		std::cout << "|                      Главное меню                        |\n";
		std::cout << "|                 1 Поиск шины по атрибуту                 |\n";
		std::cout << "|                 2 Добавление новой шины                  |\n";
		std::cout << "|                 3 Удаление шины                          |\n";
		std::cout << "|                 4 Сохрания базы данных в файл            |\n";
		std::cout << "|                 5 Просмотр базы данных                   |\n";
		std::cout << "|                 6 Выход                                  |\n\n";
		std::cout << " ----------------------------------------------------------\n";
		std::cout << "Поле для ввода: ";
		std::cin >> d;
		std::ofstream offile;
		switch (d)
		{
		case 1:// поиск
			std::cout << "Поиск\n";
			NList.FindBD();
			continue;
		case 2:// дополнение
			NList.Dop();// добавление шины в список в оперативной памяти
			continue;
		case 3:// удаление
			NList.Delet();// марка шины вводится в функции delete
			continue;
		case 4:// запись спика из оперативной памяти в файл
			offile.open(fil);
			NList.RecBD(offile);
			offile.close();
			continue;
		case 5:// просмотр
			NList.ShowBD();
			continue;
		case 6:
			return;
		default:
			std::cout << "Некорректная команда" << std::endl;
		}
	}
}
