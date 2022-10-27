#include <iostream>
#include <typeinfo>
#include <memory>
#include "rusinconsole.h"
#include "figure.hpp"
#include "myclass.hpp"
#include "figure_template.hpp"

using std::cout;
using std::cin;
using std::endl;
class base{
	public:
	virtual void f(){}
	//...
};

class derived1: public  base{
	//...
};

class derived2: public base{
	//...
};

class derived3: public derived1{
	//...
};

void WhatType(base& ob){
	cout<<"Параметр ob ссылается на объект типа ";
	cout<<typeid(ob).name()<<endl;
}

void test1(){
	base *p, base_obj;
	derived1 d1_obj;
	derived2 d2_obj;
	derived3 d3_obj;
	
	p=&base_obj;
	cout<<"Переменная p указывает на объект типа ";
	cout<<typeid(*p).name()<<endl;
	WhatType(base_obj);
	
	p=&d1_obj;
	cout<<"Переменная p указывает на объект типа ";
	cout<<typeid(*p).name()<<endl;
	WhatType(d1_obj);	
	
	p=&d2_obj;
	cout<<"Переменная p указывает на объект типа ";
	cout<<typeid(*p).name()<<endl;
	WhatType(d2_obj);
	
	p=&d3_obj;
	cout<<"Переменная p указывает на объект типа ";
	cout<<typeid(*p).name()<<endl;
	WhatType(d3_obj);
}

void figures(){
	
	std::shared_ptr<P::figure> p;
	int i;
	
	int t=0, r=0, c=0;
	
	for(i=0;i<10;i++){
		p=P::factory();
		cout<< "Объект имеет тип "<<typeid(*p).name();
		cout<< ". площадь равна: "<<p->area()<<"\n";
		if(typeid(*p)==typeid(P::rectangle)) r++;
		if(typeid(*p)==typeid(P::circle)) c++;
		if(typeid(*p)==typeid(P::triangle)) t++;
	}
	cout<<"Сгенерированы такие фигуры:\n";
	cout<<"Треугольников: "<<t<<"\n";
	cout<<"Прямоугольников: "<<r<<"\n";
	cout<<"Кругов: "<<c<<endl;
}

void templatetest1(){
	myclass<int> mi1(10), mi2(2);
	myclass<double> md1(10.5);
	
	cout<<"Object mi1 has type "<<typeid(mi1).name()<<endl;
	
	cout<<"Object mi2 has type "<<typeid(mi2).name()<<endl;
	
	cout<<"Object md1 has type "<<typeid(md1).name()<<endl;
	
	if(typeid(mi1)==typeid(mi2)) cout << "Objects mi1 and mi2 has the same type\n";
	
	if(typeid(mi1)!=typeid(md1)) cout<<"Objects mi1 and md1 has different types\n";
}

template <class T> void test_template_figure(){
	std::shared_ptr<figure<T>> p;
	int i;
	
	int t=0, r=0, c=0;
	
	for(i=0;i<10;i++){
		p=factory<T>();
		cout<< "Объект имеет тип "<<typeid(*p).name();
		cout<< ". площадь равна: "<<p->area()<<"\n";
		if(typeid(*p)==typeid(rectangle<T>)) r++;
		if(typeid(*p)==typeid(circle<T>)) c++;
		if(typeid(*p)==typeid(triangle<T>)) t++;
	}
	cout<<"Сгенерированы такие фигуры:\n";
	cout<<"Треугольников: "<<t<<"\n";
	cout<<"Прямоугольников: "<<r<<"\n";
	cout<<"Кругов: "<<c<<endl;
}



int main(int argc, char *atgv[]){
	
	test_template_figure<double>();
	test_template_figure<int>();
	return 0;
}