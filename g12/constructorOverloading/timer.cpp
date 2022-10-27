#include <iostream>
#include ".\..\..\..\rusinconsole.h"
#include <cstdlib>
#include <ctime>
using namespace std;

class timer{
	int seconds;
public:
	timer(const char *t){ seconds = atoi(t); }
	timer(int t){ seconds = t; }
	timer(int min, int sec){ seconds = min*60 + sec; }
	void run();
};

void timer::run(){
	clock_t t1, t2, t3;
	t1 = t2 = t3 = clock();
	while((clock()/CLOCKS_PER_SEC - t1/CLOCKS_PER_SEC)<seconds) 
	{	t2 = clock();
		if((t2/CLOCKS_PER_SEC - t3/CLOCKS_PER_SEC)*10>5){
			t3 = clock();
			int time_remaning = (seconds-(clock()/CLOCKS_PER_SEC - t1/CLOCKS_PER_SEC));
			cout<<"\rtimer running "<<time_remaning/60<<" min "<<time_remaning%60<<" sec";
		}
	}
	cout<< "\a";
}

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

int main(int argv, char* argc[]){

	cout<<"Введите время в формате \"Минуты Секунды\"\n";
	int min, sec;
	cin>>min>>sec;
	time_t lt = time(0);
	tm* now = localtime(&lt);
	cout<<asctime(now)<<'\n';
	timer a(min, sec);
	a.run();
	cout<<"Время вышло"<<'\n';
	lt = time(0);
	now = localtime(&lt);
	cout<<asctime(now);
	
	return  0;
}