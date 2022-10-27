#ifndef ruconsole_H
#define ruconsole_H
#include <Windows.h>
class helper{
	unsigned int old_COCP;
public:
	helper(){
		//cout<<"Helper created\n";
		old_COCP = GetConsoleOutputCP();
		SetConsoleOutputCP(CP_UTF8);
		SetConsoleCP(CP_UTF8);
		//cout<<"old Console Output Code Page: " << old_COCP<<'\n';
		//cout<<"actual  Console Output Code Page: " <<GetConsoleOutputCP()<<'\n';
		//cout<<"Русский текст\n";
	}
	~helper(){
		//cout<<"helper deleted\n";
		SetConsoleOutputCP(old_COCP);
		SetConsoleCP(old_COCP);
		//cout<<"Русский текст\n";
	}
};
static helper sh; 
#endif //ruconsole_H