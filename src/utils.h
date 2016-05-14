#ifndef UTILS_H
#define UTILS_H
#include <sstream>
#include <iostream>
//#include <regex>
//#include <cctype>
//#include <cwctype>
//#include <vector>
//#include <locale>

//std::locale locs[] = {"en_US.UTF8","ru_RU.UTF8"};
//int locsc = 2;

inline bool isAlpha(char c)
{
	return (c >= 'a' && c <= 'z');
	//-----------------------------------------'а'--------------'я'---;
}

void normalize(std::istream &in,std::stringstream &out)
{
	//bool isA;
	bool needNewline = false;
	//std::locale ru("ru_RU.UTF-8"), 
	//std::locale en("en_US.UTF8");
	for (char i; in.get(i); )
	{
		i = tolower(i);
		//isA = isAlpha(i,en);
		if (isAlpha(i)) {
			needNewline = true;
			out.put(i);
		} else if (needNewline) {
			out.put('\n');
			needNewline = false;
		} 		
	}
}




#endif