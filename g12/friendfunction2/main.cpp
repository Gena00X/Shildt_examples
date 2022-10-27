#include <iostream>
#include ".\..\..\..\rusinconsole.h"
using namespace std;

const int IDLE = 0;
const int INUSE = 1;

class C2;

class C1{
	int status;
public:
	void set_status(int state);
	friend int idle(C1 a, C2 b);
};

class C2{
	int status;
public:
	void set_status(int state);
	friend int idle(C1 a, C2 b);
};

void C1::set_status(int state){ status = state; }
void C2::set_status(int state){ status = state; }

int idle(C1 a, C2 b){
	if(a.status||b.status) return 0;
		else return 1;
}




int main(int argv, char* argc[]){
	cout<<"Привет\n";
	C1 x;
	C2 y;
	
	x.set_status(IDLE);
	y.set_status(IDLE);
	
	idle(x, y) ? cout<<"Экран свободен\n" : cout<<"Отображается сообщение\n";
	
	x.set_status(INUSE);
	y.set_status(IDLE);
	
	idle(x, y) ? cout<<"Экран свободен\n" : cout<<"Отображается сообщение\n";
	
	
	return 0;
}