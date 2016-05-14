#include <iostream>
#include "ternary.h"
#include <fstream>


using namespace std;

int main()
{
	Tree a; // = new Ternary('c');
	ifstream init("REALLY_BIG_DICTIONARY.txt");
	//ifstream init("test_in.TXT");
	ifstream test("test.txt");

	cout << "loading dictionary\n";

	for (string i; init >> i; ) 
	{ 
		a.insert(i.c_str());
		//cout << i.c_str() << "; " << a.count(i.c_str()) << endl;

		//cout << "\'" << i << "\' inserted\n";
	}

	init.close();
	cout << "loaded successfull!\nready to check user input...\n";


	for (string i; test >> i; )
	{
		if (!a.count(i.c_str())) cout << "\'" << i << "\' isn't matched any known word. Maybe mistake!\n";
		else cout << "everythings OK with \'" << i << "\'\n";
	}

	cout << "top 10:\n";
	auto t = a.freqs();
	for (auto i = t.begin(); i!= t.begin()+10; i++)
		cout << i->first << " : " << i->second << endl;


	return 0;
}

