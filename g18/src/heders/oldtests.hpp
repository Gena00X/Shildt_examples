#ifndef OLDTESTS_H
#define OLDTESTS_H

#include <iostream>
#include "rusinconsole.h"
#include "mymanip.hpp"
#include "three_d.hpp"
#include <cstdlib>
#include <exception>
#include <cstring>
#include <new> //for bad_alloc exeption

#include <fstream>//add file stream functionality
#include "str_type.hpp"//my string type

using namespace std;
namespace oldtests{
#define DATA_DIR "D:/CPP/QtPrpjects/ProjectsCPP/shildt/g18/data/"
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



/*void *operator new(size_t size )
{
	cout<<"моя глобальная версия оператора new\n";
	cout<<"Вызвана с параметром size = "<<size<<"\n";
	void *p = malloc(size);
	if(!p){
	bad_alloc ba;
	throw ba;
	}
	return p;
}*/

/*void operator delete(void *p){
	
	cout<<"Моя глобальная версия оператора delete\n";
	free(p);
}*/

void test_memory_allocation()
{
	three_d *p1, *p2;
	try{
		int *i = new int;
	p1 = new three_d[3];
	p2 = new three_d(5, 6, 7);
	delete i;
	}
	catch(bad_alloc){
		cout<<"Ошибка выделения памяти\n";
		return;
	}
	
	p1[1].show();
	p2->show();
	
	delete[] p1;
	delete p2;
}

void test_object_io()
{
	three_d td;
	cout<<"Ввод объекта three_d из cin\n";
	cin>>td;
	cout<<"Печать объекта three_d в cout\n";
	cout<<td;
}

template<class T, int sz=0> void d_bin(T u)//display binary
{
	int size;
	if(!sz){
	size = sizeof(T)*8;
	}else{
		size = sz;
	}
	for(int i = size-1; i>=0; i--)
	{
		cout.width(2);
		cout<<i<<" ";
	}
	cout<<endl;
	for(int i = size-1; i>=0; i--)
	{
		
		if((u&(1<<i))) cout.width(3), cout << "1 ";
			else cout.width(3), cout << "0 ";
	}
	cout<<'\n';
	/*1<<i:
	//пояснение алгоритма 1:
	//1<<i = 000|100000...0000|
	//          |<  i шагов  >|
	//1<<i берет число один в двоичной 
	//записи: 0000...0001
	//... - число знаков зависит от типа данных
	//и смещает единицу влево на i
	//разрядов 
	//пояснение алгоритма 2:
	//поразрядное И (&) оставляет 
	//единицу только в том месте 
	//где единица есть в обоих 
	//операндах:
	//       101010101010101010
	//    &  000010000000000000
	//    =  000010000000000000
	// или
	//       101010101010101010
	//    &  000001000000000000
	//    =  000000000000000000
	//т.е. u &(1<<i) = true 
	//только тогда когда в 
	//позиции i числа u стоит 1*/
}

void fmflagstest()
{
	ios::fmtflags f;
	f = cout.flags();
	d_bin<ios::fmtflags,15>(f);
	
	cout.setf(ios::showpos);
	cout.setf(ios::scientific);
	cout<<123<<" "<<1.23<<" "<<-1<<endl;
	f = cout.flags();
	d_bin<ios::fmtflags,15>(f);
	
	cout.unsetf(ios::scientific);
	cout<<123<<" "<<1.23<<" "<<-1<<endl;
	f = cout.flags();
	d_bin<ios::fmtflags,15>(f);
	
	cout.unsetf(ios::showpos);
	cout<<123<<" "<<1.23<<" "<<-1<<endl;
	f = cout.flags();
	d_bin<ios::fmtflags,15>(f);
	
	int 	wpdth_old 		= cout.width(10);
	char 	fill_old 		= cout.fill('_');
	int 	precision_old 	= cout.precision(20);
	cout<<1.0000009<<endl;
	cout<<"wpdth_old = "		<<wpdth_old		<<"\n";
	cout<<"fill_old = "			<<fill_old		<<"\n";
	cout<<"precision_old = "	<<precision_old	<<"\n";
	
	cout.width(wpdth_old);
	cout.fill(fill_old);
	cout.precision(precision_old);
	
	//file io
	
}
	void add_path(char *file, const char * name){
		file[0]='\0';
		strcat(file, DATA_DIR);
		strcat(file, name);
	}
	int text_file_io_test()
	{
		str_type mystr;
		mystr+=DATA_DIR;
		mystr+="test3.txt";
		char file[80];
		add_path(file,"test2.txt");
		ofstream out(mystr);
		if(!out)
		{
			cout<<"Не удалось создать файл!\n";
			return 1;
		}
		else
		{
			cout<<"Файл\n "<<(mystr-str_type(DATA_DIR))<<" \nоткрыт на запись в папке\n"<<DATA_DIR<<'\n';
			out<<10<<" "<<12.2<<"\n";
			out<<"Test";
		}
		out.close();
		if(!out.is_open()) cout<<"Файл закрыт\n";
		else cout<<"Файл НЕ закрыт\n";
		ifstream in(mystr);
		char ch;
		int i;
		float f;
		char str[80];
		if(!in)
		{
			cout<<"Не удалось открыть файл!\n";
			return 1;
		}
		else
		{
			cout<<"Файл\n "<<(mystr-str_type(DATA_DIR))<<" \nоткрыт на чтение в папке\n"<<DATA_DIR<<'\n';;
			in >> i;
			in >> f;
			//in >> ch;
			in >> str;
		}
		in.close();
		if(!in.is_open()) cout<<"Файл закрыт\n";
		else cout<<"Файл НЕ закрыт\n";
		cout<<"i = "<<i<<'\n'
			<<"f = "<<f<<'\n'
			//<<"ch = "<<ch<<'\n'
			<<"str = "<<str<<'\n';
	return 0;
	}
	
	void binary_file_io_test()
	{
	str_type mystr;
	mystr+=DATA_DIR;
	mystr+="bfio.txt";
	ofstream fo;
	ifstream fi;
	fo.open(mystr, ios::out|ios::binary);
	if(!fo){
		cout<<"Файл fo не открыт!\n";
		return;
	}
	int n[5] = {1, 2, 3, 4, 5};
	int n2[5];
	fo.write((char*) &n, sizeof n);
	fo.close();
	fi.open(mystr, ios::in|ios::binary);
	if(!fi) cout<<"Файл fi не открыт!\n";
	fi.read((char *) &n2 , sizeof n);
	for(int i =0; i<5; i++) cout<<"n2["<<i<<"] = "<<n2[i]<<"\n";
	fi.close();
	}

};
#endif //OLDTESTS_H