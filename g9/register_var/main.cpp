#include <iostream>
#include <ctime>
#include <Windows.h>
using namespace std;

unsigned int i, delay;

int main(int argv, char* argc[]){
	SetConsoleOutputCP(CP_UTF8);
	register unsigned int j;
	long start, end;
	
	start = clock();
	for (delay = 0; delay<50; delay++)
	{	
		for(i = 0; i < 64000000; i++);
		cout<<'\r';
		for(int k = 0; k<delay; k++)
			cout<<'#';
	}
	end = clock();
	cout<<"\nколичество тиков для не register-цикла :";
	cout<<end-start<<'\n';
	
	start = clock();
	for (delay = 0; delay<50; delay++)
	{
		for(j = 0; j < 64000000; j++);
		cout<<'\r';
		for(int k = 0; k<delay; k++)
			cout<<'#';
	}	
	end = clock();
	cout<<"\nколичество тиков для register-цикла :";
	cout<<end-start<<'\n';
	
	return 0;
}