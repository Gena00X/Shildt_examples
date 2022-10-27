#include <iostream>
#include ".\..\..\..\rusinconsole.h"
using namespace std;

class myclass{
	int a, b;
public:
	myclass(int i, int j){ a = i; b = j; }
	friend int mysum(myclass &x);
};

class myclass2{
	int a, b;
public:
	myclass2(int i, int j){ a = i; b = j; }
	friend int mysum(myclass2 &x);
};


int mysum(myclass &x){
	return x.a + x.b;
}


int mysum(myclass2 &x){
	return x.a + x.b;
}

int main(int argv, char* ardc[])
{
	cout<<"Friend function example\nПример с функцией-\"другом\"\n";
	myclass a(1,2);
	myclass2 b(3,4);
	cout<<"myclass a(1,2);\n";
	cout<<"myclass2 b(3,4);\n";
	cout<<"mysum(a) = "<<mysum(a)<<'\n';
	cout<<"mysum(b) = "<<mysum(b)<<'\n';
	return 0;
}