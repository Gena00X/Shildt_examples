#include <iostream>
#include <typeinfo>
#include "rusinconsole.h"
using namespace std;

class Base{
public:
	virtual void f(){cout<< "В классе Base\n"<<endl;}
};

class Derived : public Base{
public:
	void f(){cout<<"В классе Derived\n"<<endl;}
};

void test1(){
	Base 	*bp, b_ob;
	Derived *dp, d_ob;
	
	//из Derived* в Derived*
	dp = dynamic_cast<Derived *>(&d_ob);
	
	if(dp){
		cout << "Приведение типов из "
			 << "Derived* в Derived* реализовано.\n";
	dp->f();
	}else{
		cout << "Ошибка\n";
	}
	
	cout << endl;
	
	//Из Derived* в Base*
	bp = dynamic_cast<Base *>(&d_ob);
	
	if(bp){
		cout << "Приведение типов из "
			 << "Derived* в Base* реализовано.\n";
	bp->f();
	}else{
		cout << "Ошибка\n";
	}
	
	cout << endl;
	
	//Из Base* в Base*
	bp = dynamic_cast<Base *>(&b_ob);
	
	if(bp){
		cout << "Приведение типов из "
			 << "Base* в Base* реализовано.\n";
	bp->f();
	}else{
		cout << "Ошибка\n";
	}
	
	cout << endl;
	
	//Из Base* в Derived*
	dp = dynamic_cast<Derived *>(&b_ob);
	
	if(dp){
		cout << "Ошибка\n";
	}else{
		cout << "Приведение типов из "
			 << "Base* в Derived* не реализовано.\n";
	}
	
	cout << endl;
	
	bp = &d_ob; //Указатель типа Base указывает на объкласса Derived
	dp = dynamic_cast<Derived *>(bp);
	if(dp){
		cout << "Приведение Base указателя bp к типу Derived*\n"
			 << "реализовано поскольку bp действительно\n"
			 << "указывает на объект класса Derived\n";
		dp->f();
	}else{
		cout << "Ошибка\n";
	}
	cout << endl;
	
	bp = &b_ob; //bp указывает на объект класса Base
	dp = dynamic_cast<Derived *>(bp);
	if(dp){
		cout << "Ошибка\n";
	}else{
		cout << "Теперь приведение Base указателя bp к типу Derived*\n"
			 << "не реализовано поскольку bp в дейсствительности\n"
			 << "указывает на объект класса Base\n";
	}
	cout << endl;
	
	dp = &d_ob; //Указатель dp типа Derived указывает на объект типа Derived
	bp = dynamic_cast<Base*>(dp);
	if(bp){
		cout << "Приведение указателя типа Derived к типу Base* реализовано\n";
		bp->f();
	}else{
		cout << "Ошибка\n";
	}
}



int main(int argc, char *atgv[]){
	cout<<"Привет мир! Hello world!\n";
	
	Base *bp, b_ob;
	Derived *dp, d_ob;
	
	//********************************//
	// Использование оператора typeid //
	//********************************//
	
	bp = &b_ob;
	if(typeid(*bp)==typeid(Derived)){
		dp = (Derived *) bp;
		dp->f();
	}else{
		cout << "Операция приведения указателя на объект типа Base "
			 << "к указателю на объект типа Derived не выполнилась.\n";
	}
	
	bp = &d_ob;
	if(typeid(*bp)==typeid(Derived)){
		dp = (Derived *) bp;
		dp->f();
	}else{
		cout << "Ошибка, приведение типа "
			 << "должно быть реализовано\n";
	}
	
	//**************************************//
	// Использование оператора dynamic_cast	//
	//**************************************//
	
	bp = &b_ob;
	dp = dynamic_cast<Derived *>(bp);
	if(dp){
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
	
	
	
	return 0;
}