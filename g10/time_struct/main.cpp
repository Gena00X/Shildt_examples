#include <iostream>
#include <ctime>
#include <windows.h>
#include "month.h"
using namespace std;
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
	}
	void showoldCP()
	{
		cout<<"oldinCP: "<<oldin<<'\n';
		cout<<"oldoutCP: "<<oldout<<'\n';
	}
	
	~GivMeRussian()
	{
		SetConsoleOutputCP(oldout);
		SetConsoleCP(oldin);
	}
};
static GivMeRussian gmr;




struct mytm
{
	int tm_sec;		//секунды 0-61
	int tm_min;		//минуты 0-59
	int tm_hour;	//часы 0-23
	int tm_mday;	//день месяца 1-31
	int tm_mon;		//месяц начиная с января 0-11
	int tm_year;	//год после 1900
	int tm_wday;	//день начиная с воскресенья 0-6
	int tm_yday;	//день начиная с первого января 0-365
	int tm_isdst;	//индикатор летнего времени 1-ленее время 0-зимнее
};

void print_data(ostream& c, tm* now)
{
	c<<"секунды 0-61\t"										<<now->tm_sec<<'\n';
	c<<"минуты 0-59\t"										<<now->tm_min<<'\n';
	c<<"часы 0-23\t"										<<now->tm_hour<<'\n';
	c<<"день месяца 1-31\t"									<<now->tm_mday<<'\n';
	c<<"месяц начиная с января 0-11\t"						<<now->tm_mon<<" ("<<months[now->tm_mon]<<")"<<'\n';	
	c<<"год после 1900\t"									<<now->tm_year<<'\n';	
	c<<"день начиная с воскресенья 0-6\t"					<<now->tm_wday<<" ("<<days_of_week[now->tm_wday]<<")"<<'\n';
	c<<"день начиная с первого января 0-365\t"				<<now->tm_yday<<'\n';
	c<<"индикатор летнего времени 1-ленее время 0-зимнее\t"	<<now->tm_isdst<<'\n';	
	c<<asctime(now)<<'\n';
}

int main(int argv, char* argc[]){
	
	cout<<"Русский текст\n";
	cout<<time('\0')<<'\n';
	time_t lt = time(0);
	cout<<2022-lt/(60*60*24*365)<<'\n';
	tm now, *nowptr;
	tm* ptr = localtime(&lt);
	now = *ptr;
	nowptr = &now;
	print_data(cout, nowptr);
	/*
	cout<<"секунды 0-61\t"										<<now.tm_sec<<'\n';
	cout<<"минуты 0-59\t"										<<now.tm_min<<'\n';
	cout<<"часы 0-23\t"											<<now.tm_hour<<'\n';
	cout<<"день месяца 1-31\t"									<<now.tm_mday<<'\n';
	cout<<"месяц начиная с января 0-11\t"						<<now.tm_mon<<" ("<<months[now.tm_mon]<<")"<<'\n';	
	cout<<"год после 1900\t"									<<now.tm_year<<'\n';	
	cout<<"день начиная с воскресенья 0-6\t"					<<now.tm_wday<<" ("<<days_of_week[now.tm_wday]<<")"<<'\n';
	cout<<"день начиная с первого января 0-365\t"				<<now.tm_yday<<'\n';
	cout<<"индикатор летнего времени 1-ленее время 0-зимнее\t"	<<now.tm_isdst<<'\n';	
	*/
	cout<<months[0]<<'\n';
	cout<<days_of_week[0]<<'\n';
	return 0;
}