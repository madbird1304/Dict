#include <iostream>
#include "ternary.h"
#include <fstream>
#include "utils.h"


using namespace std;

int main(int argc,char *argv[])
{
	Tree a;
	ifstream init_(argv[1]);
	ifstream test(argv[2]);
	
	cout << "Загрузка словаря.\n";

	for (string i; init_ >> i; ) 
	{ 
		a.insert(i.c_str());
	}

	init_.close();
	cout << "Словарь успешно загружен.\nПодготовка к проверке...\n";


	for (string i; test >> i; )
	{
		if (!a.count(i.c_str())) cout << "Не найдено совпадений для \'" << i << "\'.\n";
		else cout << "Всё в порядке с \'" << i << "\'\n";
	}
	test.close();

	cout << "Топ 10:\n";
	auto t = a.freqs();
	for (auto i = t.begin(); i!= t.begin()+10; i++)
		cout << i->first << " : " << i->second << endl;

	return 0;
}

