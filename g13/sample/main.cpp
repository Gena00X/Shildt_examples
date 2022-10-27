//перегрузка операторов
#include <iostream>
#include "C:\Users\User\Desktop\QtPrpjects\ProjectsCPP\rusinconsole.h"
#include <cstring>
#include <cstdlib>
using namespace std;

class sample{
	char *s;
public:
	sample();
	sample(const sample &obj);
	~sample(){
		if(s){ 
			delete[] s;
		cout << "Освобождение s-памяти\n";
		}
	}
	void show(){ cout << s << '\n'; }
	void set(const char *str);
	sample operator=(const sample &obj);
};

sample::sample(){
	s = new char('\0');
	//cout<<"Выделение памяти\n";
}

sample::sample(const sample &obj){
	s=new char(strlen(obj.s)+1);
	strcpy(s,obj.s);
}

void sample::set(const char* str){
	s=new char(strlen(str)+1);
	strcpy(s,str);
	//cout<<"Выделение памяти\n";
}

sample sample::operator=(const sample &obj){
	if(strlen(obj.s)>strlen(s)){
		delete[] s;
		//cout<<"освобождение s-памяти\n";
		s = new char[strlen(obj.s)+1];
		//cout<<"Выделение памяти\n";
	}
	strcpy(s,obj.s);
	return *this;
}

sample input(){
	
	char instr[80];
	sample str;
	
	cout<<"введите строку: ";
	cin>>instr;
	
	str.set(instr);
	return str;
}

int main(int argv, char* argc[]){
	sample ob;
	
	ob = input();
	
	ob.show();
	
	return 0;
}