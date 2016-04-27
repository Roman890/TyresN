#include "ListTyre.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void ListTyre::ShowBD()

{// просмотр состояния списка
	Tyre* p = first_elem;
	std::cout << "МАРКА\t" << "ЦЕНА\t" << "ШИРИНА ПРОФИЛЯ\t" << "ДИАМЕТР\t" << "ВЫСОТА ПРОФИЛЯ\t" << "СЕЗОН(1-ЗИМА,0-ЛЕТО)\t" << std::endl;
	while (p != NULL)
	{
		std::cout << std::endl << p->GetMarka() << " \t" << p->GetPrice() << " \t\t"
			<< p->GetVisota_profila() << " \t" << p->GetDiam() << " \t\t"
			<< p->GetVisota_profila() << " \t\t" << p->GetWinter() << std::endl;
		if (p->GetNext() == NULL)
			break;
		p = p->GetNext();
	}

}
