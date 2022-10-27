#include "heder1.hpp"
#include <cstdlib>
#include <exception>
#include <cstring>
#include <new> //for bad_alloc exeption

void abort(){
	cout<<"Моя версия функции abort выполняется"<<endl;
	exit(EXIT_FAILURE);
}
typedef void (*pvf)();
pvf a = set_terminate(
					[]()//лямбда-функция
					{
						cout << "It is my terminate"<<endl;
						abort();
					}
					);


void test1()
{
	try{
		throw 5.0;
		
	}catch(int i){
		cout<<"Ошибка "<<i<<" перехвачена"<<endl;
	}catch(...){
		cout<<"Ошибка перехвачена"<<endl;
	}
}

class MyExeption
{
	char str[80];
	int N;
public:
	MyExeption(){strcpy(str,"Undefinid");}
	MyExeption(const char* s, int nn =0){strcpy(str,s); N=nn;}
	char* what(){return str;}
	int number(){return N;}
};


void test2()
{
	try
	{
		throw MyExeption("Это ошибка",7);
	}
	catch(MyExeption w)
	{
		cout<<w.what()<<" ";
		cout<<"Номер ошибки: "<<w.number()<<endl;
	}
}

class three_d{
	int x, y, z;
public:
	three_d()
	{
		x = y = z = 0;
		cout<<"three_d конструктор по умолчанию\n";
	}
	three_d(int i, int j, int k)
	{
		x = i; y = j; z = k;
		cout<<"three_d конструктор с параметрами: i = "<<i<<", j = "<<j<<", k = "<<k<<"\n";
	}
	~three_d()
	{
		cout<<"Разрушение объекта three_d\n";
	}
	
	void *operator new(size_t size);
	void *operator new[](size_t size);
	void operator delete(void *p);
	void operator delete[](void *p);
	void show();
};

void *operator new(size_t size )
{
	cout<<"моя глобальная версия оператора new\n";
	cout<<"Вызвана с параметром size = "<<size<<"\n";
	void *p = malloc(size);
	if(!p){
	bad_alloc ba;
	throw ba;
	}
	return p;
}

void operator delete(void *p){
	
	cout<<"Моя версия delete\n";
	free(p);
}

int main(int argv, char* argc[]){
	
	
	three_d *p1, *p2;
	try{
		int *i = new int;
	p1 = new three_d[3];
	p2 = new three_d(5, 6, 7);
	delete i;
	}
	catch(bad_alloc){
		cout<<"Ошибка выделения памяти\n";
		return 1;
	}
	
	p1[1].show();
	p2->show();
	
	delete[] p1;
	delete p2;
	
	return 0;
}



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






