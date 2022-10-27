#ifndef GIVMERUSSIAN_H
#define GIVMERUSSIAN_H
#include <windows.h>
class GivMeRussian{
	int oldin;
	int oldout;
	public:
	GivMeRussian()
	{
		oldin = GetConsoleCP();
		oldout = GetConsoleOutputCP();
	    SetConsoleOutputCP(65001);
		SetConsoleCP(65001);	
		//std::cout<<"GMR worck\n";
	}

	~GivMeRussian()
	{
		SetConsoleOutputCP(oldout);
		SetConsoleCP(oldin);
		//std::cout<<"GMR worck\n";
	}
};
static GivMeRussian gmr;
#endif //GIVMERUSSIAN_H