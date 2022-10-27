#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif //IOSTREAM
#include "rusinconsole.h"
#include "simple_queue.h"
using namespace std;

void queuetest(){
	cout<<"Простой пример класса\n";
	queue a(1), b(2);
	
	a.qput(10);
	a.qput(11);
	
	b.qput(19);
	b.qput(20);
	
	cout<<"a: "	<<a.qget();
	cout<<' '	<<a.qget();
	cout<<' '	<<a.qget()<<"\n\n";
	
	cout<<"b: "	<<b.qget();
	cout<<' '	<<b.qget();
	cout<<' '	<<b.qget()<<'\n';
}



int main( int argv, char** argc){
	
	
	return 0;
}