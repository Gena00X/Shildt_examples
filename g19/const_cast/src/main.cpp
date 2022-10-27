#include <iostream>
#include "rusinconsole.h"
using namespace std;

void f(const int *p){
	int *v;
	
	v = const_cast<int *>(p);
	*v = 100;
}

class Base{
public:
	virtual void f(){cout<< "В классе Base\n"<<endl;}
};

class Derived : public Base{
public:
	void f(){cout<<"В классе Derived\n"<<endl;}
};

void const_cast_test(){
	//использование оператора const_cast
	//оператор const_cast используется для 
	//явного ереопределения модификаторов 
	//const и volatile. 
	//использовать с осторожностью!
	int x = 99;
	cout << "x before coll f() x="<<x<<endl;
	f(&x);
	cout<< "x after call f() x="<<x<<endl; 
}
void syatic_cast_test(){
	/*
	*оператор используется для неполиморфного приведения типов 
	*при этом никаких проверок на допустимость не производится
	*может использоваться для стандартных преобразований типов
	*вместо
	*(new_type)exp 	(C-style cast) 
	*и
	*new_type(exp) 	(functional notation)
	*не используется для переопределения параметров const и volatile.
	*/
	int 	i;
	float 	f;
	f = 199.22F;
	i = static_cast<int>(f);
	cout<<"value after static cast float 199.22F to int:"<<i<<endl;
}

void reinterpret_cast_test(){
	/*
	*оператор reinterpret_cast используется для фундаментального 
	*изменения типа например указателя в целое значение или
	*приведения наследственно несовместимых типов указателей
	*/
	
	int i;
	const char *p = "Это короткая строка\n";
	i = reinterpret_cast<int>(p);
	cout <<"Строка (char*) приведенная к типу int:"<<i<<endl;
	cout <<"обратно приведём к указателю:"<<reinterpret_cast<const char*>(i)<<endl;
	
}

void dynamic_cast_test(){
	/*
	*оператор dynamic_cast используется для полиморфного 
	*приведения типов, тоесть приведения типов между  
	*полиморфными классами (классами связанными 
	*отношениями наследования и имеющими виртуальные функции)
	*при этом возможность выполнения операции проверяется
	*во время выполнения программы
	*/
	//**************************************//
	// Использование оператора dynamic_cast	//
	//**************************************//
	Base *bp, b_ob;
	Derived *dp, d_ob;
	
	bp = &b_ob;
	dp = dynamic_cast<Derived *>(bp);
	if(dp){
		cout << "Ошибка, приведение типа "
			 << "НЕ должно быть реализовано\n";
		dp->f();
	}else{
		cout << "Операция приведения указателя на объект типа Base "
			 << "к указателю на объект типа Derived не выполнилась.\n";
	}
	
	bp = &d_ob;
	dp = dynamic_cast<Derived *>(bp);
	if(bp){
		dp->f();
	}else{
		cout << "Ошибка, приведение типа "
			 << "должно быть реализовано\n";		
	}
}
int main(int argc, char *atgv[]){
	cout<<"Привет мир! Hello world!\n";
	//const_cast_test();
	//syatic_cast_test();
	//reinterpret_cast_test();
	//dynamic_cast_test();
	return 0;
}