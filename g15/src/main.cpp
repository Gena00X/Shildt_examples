#include <iostream>
#include "rusinconsole.h"
#include "base_class.h"	 
using namespace std;

int main(int argv, char* argc[]){
	cout<<"Test тест тест\n";
	const int SIZE=4;
	my_base_class base;
	my_base_class* pb[SIZE];
	derived1 d1;
	derived2 d2;
	derived_1_2 d12;
	pb[0]=&base;
	pb[1]=&d1;
	pb[2]=&d2;
	pb[3]=&d12;
	for(int i=0; i<SIZE; i++)
		cout<<pb[i]->showname()<<'\n';
	
	return 0;
}