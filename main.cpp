#include <iostream>
#include <unordered_map>
#include <fstream>
#include <string>
#include <map>
#include <regex>
using namespace std;

//struct RuntimeModel
typedef std::unordered_map<std::string,int> Map;


std::smatch parse(string &str)
{
	std::regex r("\\w+");
	std::smatch sm;
	std::regex_match (str , sm , r);
	//cout << "\"" << str << "\" : " << sm.size() << " matches\n";
	for (auto i : sm) cout << i << endl;
	return sm;	
}


class Dict{
	Map table;
public:
	Dict(std::istream &is)
	{
		int c = 0;
		if (!is) throw "Empty stream.";
		for (string str; std::getline(is,str,'\n'); ) 
				table.insert(pair<string,char>(str,'\0'));	
	}
	inline int isElem(string str)
	{
		return (bool)(this->table).count(str);
	}
	void checkStream(std::istream &is,std::ostream &os)
	{
		for (string str; std::getline(is,str,'\n');) 
				if (!isElem(str)) os<< "Maybe mistake at \"" << str << "\"" << endl;
	}


};



int main(int argc,char* argv[])
{
	ifstream init(argv[1]); 
	//ifstream test(argv[2]); 
	//ofstream out(argv[3]);

	ostream *out;	
	
	
	ifstream inp("test_in.TXT");
	ifstream mer("test.txt");
	Dict dict(inp);

	dict.checkStream(mer,cout);
	
	return 0;
}