#include <iostream>
#include "rusinconsole.h"
using namespace std;

class myclass{
public:
	int sum;
	void sum_it(int x);
};

void myclass::sum_it(int x){
	int i;
	
	sum = 0;
	for(i = x; i; i--) sum += i;
}
void pointers_to_members_with_object(){
	int myclass::*dp; 			//указатель на int член класса
	void (myclass::*fp)(int x); //указатель на функцию - член
	
	myclass c;
	
	dp = &myclass::sum; 		//получаем адрес int-члена класса
	fp = &myclass::sum_it; 		//получаем адрес функции-члена
	
	(c.*fp)(3); 				//вызов функции-члена объекта с через указатель на функцию-член класса
	cout<<"c.sum = "<<c.*dp;	//обращение к члену объекта с через указатель на член класса
}

void pointers_to_members_with_pointer(){
	int myclass::*dp; 			//указатель на int член класса
	void (myclass::*fp)(int x); //указатель на функцию - член
	
	myclass *c, d;
	
	c = &d;
	
	dp = &myclass::sum; 		//получаем адрес int-члена класса
	fp = &myclass::sum_it; 		//получаем адрес функции-члена
	
	(c->*fp)(4); 				//вызов функции-члена объекта с через указатель на функцию-член класса
	cout<<"c.sum = "<<c->*dp;	//обращение к члену объекта с через указатель на член класса
}

int main(int argc, char* argv[]){
	if(argc==2) cout << "Hello "<<argv[1]<<"\nПривет "<<argv[1]<<endl;
	else cout << "Hello World!\nПривет Мир!\n";

	
	return 0;
}
