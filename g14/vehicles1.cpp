#include <iostream>
#include "C:\Users\User\Desktop\QtPrpjects\ProjectsCPP\rusinconsole.h"
using namespace std;

class road_vehicle
{
	int 	wheels_;
	int 	passengers_;
public:
	void set_wheels(int wheels)
	{ 
		wheels_ = wheels;
	}
	int get_wheels()
	{
		return wheels_;
	}
	void set_pass(int passengers){
		passengers_ = passengers;
	}
	int get_pass(){
		return passengers_;
	}
};

class truck: public road_vehicle
{
	int cargo_;
public:
	void set_cargo(int cargo)
	{
		cargo_ = cargo;
	}
	int get_cargo()
	{
		return cargo_;
	}
	void show();
};

enum type{car, van, wagon};

const char* TypeNames[]={
	"легковой",
	"автофургон",
	"фура"
};

class automobile : public road_vehicle{
	type car_type_;
public:
	void set_type(type car_type)
	{
		car_type_ = car_type;
	}
	type get_type()
	{
		return car_type_;
	}
	void show();
};

void truck::show()
{
	cout<<"Пассажиров:	"	<<get_pass()	<<'\n';	
	cout<<"Колёс:		"	<<get_wheels()	<<'\n';
	cout<<"Груз:		"	<<get_cargo()	<<"кг\n";
}

void automobile::show()
{
	cout<<"Пассажиров: 	"	<<get_pass()			<<'\n';	
	cout<<"Колёс: 		"	<<get_wheels()			<<'\n';
	cout<<"Тип:		"		<<TypeNames[get_type()]	<<'\n';
}


int main(int argv, char* argc[]){
	
	truck t1, t2;
	automobile a1;
	
	t1.set_wheels(18);
	t1.set_pass(2);
	t1.set_cargo(3200);
	
	t2.set_wheels(6);
	t2.set_pass(3);
	t2.set_cargo(1200);
	
	t1.show();
	cout<<'\n';
	t2.show();
	cout<<'\n';
	a1.set_wheels(4);
	a1.set_pass(6);
	a1.set_type(van);
	
	a1.show();
	cout<<'\n';
	return 0;
}