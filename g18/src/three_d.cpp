#include "three_d.hpp"
void *three_d::operator new(size_t size)
{
	void *p;
	
	cout<<"Выделение памяти для объекта класса three_d\n";
	p = malloc(size);
	if(!p){
		bad_alloc ba;
	
	throw ba;
	}
	return p;
}

void *three_d::operator new[](size_t size)
{
	void *p;
	
	cout<<"Выделение памяти для массива объектов класса three_d\n";
	p = malloc(size);
	if(!p){
		bad_alloc ba;
		throw ba;
	}
	return p;
}

void three_d::operator delete( void *p)
{
	cout<<"Удаление объекта класса three_d\n";
	free(p);
}


void three_d::operator delete[]( void *p)
{
	cout<<"Удаление массива объектов класса three_d\n";
	free(p);
}

void three_d::show()
{
	cout<<"x = "<<x<<", y = "<<y<<", z = "<<z<<"\n";
}

ostream &operator<<(ostream &os, three_d &obj)
{
	os<<obj.x<<" "<<obj.y<<" "<<obj.z<<'\n';
	return os;
}

istream &operator>>(istream &is, three_d &obj)
{
	is>>obj.x>>obj.y>>obj.z;
	return is; 
}

