#include <iostream>
#include "ternary.h"
#include <fstream>
#include "utils.h"

using namespace std;

int main()
{
	ifstream test("test2.txt");
	stringstream stest;
	normalize(test,stest);

	for (string s; stest >> s;) cout << s << endl;

	return 0;
}

