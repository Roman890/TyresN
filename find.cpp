#include "ListTyre.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <math.h>



void ListTyre::FindBD()
{// поиск по атрибуту
	int i;
	char m[30];
	float pr, sh, dm, vis;
	int w;
	std::cout << "\t По какому признаку будем искать? \n";
	std::cout << "1 : Поиск по марке шины\n";
	std::cout << "2 : Поиск по цене шины\n";
	std::cout << "3 : Поиск по ширине профиля шины\n";
	std::cout << "4 : Поиск по диаметру шины\n";
	std::cout << "5 : Поиск по высоте профиля шины\n";
	std::cout << "6 : Поиск по признаку сезона: 1-зима, 0-лето\n";
	std::cout << "Поле для ввода: ";
	std::cin >> i;
	switch (i)
	{
	case 1:
	{
		std::cout << "Введите марку шины: ";
		std::cin >> m;
		Tyre* p = first_elem;
		std::cout << "МАРКА\t" << "ЦЕНА\t" << "ШИРИНА ПРОФИЛЯ\t" << "ДИАМЕТР\t" << "ВЫСОТА ПРОФИЛЯ\t" << "СЕЗОН(1-ЗИМА,0-ЛЕТО)\t" << std::endl;
		while (p != NULL)
		{
			if (strcmp(m, p->GetMarka()) == 0)
			{

				std::cout << std::endl << p->GetMarka() << " \t" << p->GetPrice() << " \t\t"
					<< p->GetShirina_Profila() << " \t" << p->GetDiam() << " \t\t"
					<< p->GetVisota_profila() << " \t\t" << p->GetWinter() << std::endl;
			}
			if (p->GetNext() == NULL)
				break;
			p = p->GetNext();
				
		}
	}
	break;
	case 2:
	{
		std::cout << "Введите цену шины: ";
		std::cin >> pr;
		Tyre* p = first_elem;
		std::cout << "МАРКА\t" << "ЦЕНА\t" << "ШИРИНА ПРОФИЛЯ\t" << "ДИАМЕТР\t" << "ВЫСОТА ПРОФИЛЯ\t" << "СЕЗОН(1-ЗИМА,0-ЛЕТО)\t" << std::endl;
		while (p != NULL)
		{
			if (p->GetPrice() == pr)
			{
				std::cout << std::endl << p->GetMarka() << " \t" << p->GetPrice() << " \t\t"
					<< p->GetShirina_Profila() << " \t" << p->GetDiam() << " \t\t"
					<< p->GetVisota_profila() << " \t\t" << p->GetWinter() << std::endl;
			}
			if (p->GetNext() == NULL)
				break;
			p = p->GetNext();
		}
	}
	break;
	case 3:
	{
		std::cout << "Введите ширину профиля шины: ";
		std::cin >> sh;
		Tyre* p = first_elem;
		std::cout << "МАРКА\t" << "ЦЕНА\t" << "ШИРИНА ПРОФИЛЯ\t" << "ДИАМЕТР\t" << "ВЫСОТА ПРОФИЛЯ\t" << "СЕЗОН(1-ЗИМА,0-ЛЕТО)\t" << std::endl;
		while (p != NULL)
		{
			if (p->GetShirina_Profila() == sh)
			{
				std::cout << std::endl << p->GetMarka() << " \t" << p->GetPrice() << " \t\t"
					<< p->GetShirina_Profila() << " \t" << p->GetDiam() << " \t\t"
					<< p->GetVisota_profila() << " \t\t" << p->GetWinter() << std::endl;
			}
			if (p->GetNext() == NULL)
				break;
			p = p->GetNext();
		}
	}
	break;
	case 4:
	{
		std::cout << "Введите диаметр шины: ";
		std::cin >> dm;
		Tyre* p = first_elem;
		std::cout << "МАРКА\t" << "ЦЕНА\t" << "ШИРИНА ПРОФИЛЯ\t" << "ДИАМЕТР\t" << "ВЫСОТА ПРОФИЛЯ\t" << "СЕЗОН(1-ЗИМА,0-ЛЕТО)\t" << std::endl;
		while (p != NULL)
		{
			if (p->GetDiam() == dm)
			{
				std::cout << std::endl << p->GetMarka() << " \t" << p->GetPrice() << " \t\t"
					<< p->GetShirina_Profila() << " \t" << p->GetDiam() << " \t\t"
					<< p->GetVisota_profila() << " \t\t" << p->GetWinter() << std::endl;
			}
			if (p->GetNext() == NULL)
				break;
			p = p->GetNext();
		}
	}
	break;
	case 5:
	{
		std::cout << "Введите высоту профиля шины: ";
		std::cin >> vis;
		Tyre* p = first_elem;
		std::cout << "МАРКА\t" << "ЦЕНА\t" << "ШИРИНА ПРОФИЛЯ\t" << "ДИАМЕТР\t" << "ВЫСОТА ПРОФИЛЯ\t" << "СЕЗОН(1-ЗИМА,0-ЛЕТО)\t" << std::endl;
		while (p != NULL)
		{
			if (p->GetVisota_profila() == vis)
			{
				std::cout << std::endl << p->GetMarka() << " \t" << p->GetPrice() << " \t\t"
					<< p->GetShirina_Profila() << " \t" << p->GetDiam() << " \t\t"
					<< p->GetVisota_profila() << " \t\t" << p->GetWinter() << std::endl;
			}
			if (p->GetNext() == NULL)
				break;
			p = p->GetNext();
		}
	}
	break;
	case 6:
	{
		std::cout << "Введите признак сезона 1-зима, 0-лето : ";
		std::cin >> w;
		Tyre* p = first_elem;
		std::cout << "МАРКА\t" << "ЦЕНА\t" << "ШИРИНА ПРОФИЛЯ\t" << "ДИАМЕТР\t" << "ВЫСОТА ПРОФИЛЯ\t" << "СЕЗОН(1-ЗИМА,0-ЛЕТО)\t" << std::endl;
		while (p != NULL)
		{
			if (p->GetWinter() == w)
			{
				std::cout << std::endl << p->GetMarka() << " \t" << p->GetPrice() << " \t\t"
					<< p->GetShirina_Profila() << " \t" << p->GetDiam() << " \t\t"
					<< p->GetVisota_profila() << " \t\t" << p->GetWinter() << std::endl;
			}
			if (p->GetNext() == NULL)
				break;
			p = p->GetNext();
		}
	}
	break;
	default:
		std::cout << "Некорректная команда. Повторите ввод" << std::endl;
	}
}
