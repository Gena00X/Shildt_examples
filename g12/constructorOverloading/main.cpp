#include <iostream>
#include ".\..\..\..\rusinconsole.h"
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
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
			cout<<"timer running "<<seconds-(clock()/CLOCKS_PER_SEC - t1/CLOCKS_PER_SEC)<<"                               \r";
		}
	}
	cout<< "\a";
}

void f(){
	cout<<"thread 1\n";
	 
}

int main(int argv, char* argc[]){
	timer a(5); timer b("5"); timer c(1,0);
	//a.run();
	//b.run();
	//c.run();
	std::this_thread::sleep_for(std::chrono::milliseconds(10));
	
	thread task1(f);
    thread task2(&timer::run,&c);
    thread task3(&timer::run,&a);
    thread task4(&timer::run,&b);

    task1.join();
    task2.join();
    task3.join();
    task4.join();
	
	return  0;
}