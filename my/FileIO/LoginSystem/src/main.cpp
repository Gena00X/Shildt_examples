#include <iostream>
#include <string>
#include <fstream>
#include "rusinconsole.h"
using namespace std;
/*
1: Register
2: Login
1 - запросить username и password создать файл с именем username
	содержащий две строки в формате 
	username: строка
	password: строка
	если файл с именем username существует - выдать ошибку
2- 	запросить username и password, открыть файл с именем username
	проверить совпадает ли password с записанным в файле
	если совпадает - ок, иначе ошибка 
	если файл не существует - ошибка

данные храняться в объекте класса user который имеет методы файлового ввода-вывода (опционально)
*/


inline bool exists_test (const string& name) {
    ifstream f(name.c_str());
    return f.good();
}

int menu();

int main(int argc, char* argv[]){
	if(argc==2) cout << "Hello "<<argv[1]<<"\nПривет "<<argv[1]<<endl;
	else cout << "Hello World!\nПривет Мир!\n";
	int i;
	do{
		i = menu();
		system("cls");
		cout << "your choise: " << i << endl;
	}while(i!=3);
	cout << "Exiting..." << endl;
	return 0;
}



int menu(){
	string temp;
	do{
	cout << "Enter your choice:\n";
	cout << "\t1: Register\n";
	cout << "\t2: Login\n";
	cout << "\t3: Exit\n>>";
	cin >> temp;
	}while(!(temp==string("1")|temp==string("2")|temp==string("3")));
	return stoi( temp );
}