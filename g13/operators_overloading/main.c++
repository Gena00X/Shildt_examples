#include "str_type.h"
using namespace std;

int main(int argv, char* argc[]){
	
	str_type a("Всем "), b("привет"), c;
	
	c = a + b;
	c.show();
	a = "для программирования по тому, что";
	c = "о";
	b = a - c;
	cout<<"a-c: ";
	b.show();
	cout<<"\na: ";
	a.show();
	b = c = "С++ это супер";
	b.show();
	c.show();
	
	c = c+" "+a+" "+b;
	c.show();
	
	
	return 0;
}