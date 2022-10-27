#include <iostream>
#include <fstream>
#include "rusinconsole.h"
#include "mymanip.hpp"
#include "three_d.hpp"
#include "oldtests.hpp"
#include "str_type.hpp"
using namespace std;
#define DATA_DIR "D:/CPP/QtPrpjects/ProjectsCPP/shildt/g18/data/"

int tesfileiowithobject(){
	ofstream fo(
		"D:/CPP/QtPrpjects/ProjectsCPP/shildt/g18/data/test4",
		ios::out
		);
	if(!fo) {cout<<"file not open!"; return 1;}
	three_d a(1, 2, 3), b(7,8,9);
	fo<<a<<b;
	fo.close();
	ifstream fi(
		"D:/CPP/QtPrpjects/ProjectsCPP/shildt/g18/data/test4",
		ios::in
		);
	if(!fi) {cout<<"file not open!"; return 1;}
	three_d c, d;
	fi>>c>>d;
	cout<<"c: "<<c<<"d: "<<d;
	fi.close();
	return 0;
}
void put_and_get_test()
{
	ofstream fo((str_type(DATA_DIR)+str_type("test5.txt")), ios::out|ios::binary);
	//fo<<1<<" "<<2<<" "<<3<<'\n';
	if(!fo) cout<<"file not open!/n";
	fo.put(10);
	fo.put(11);
	fo.put(12);
	fo.close();
	int a, b, c;
	ifstream fi((str_type(DATA_DIR)+str_type("test5.txt")), ios::in|ios::binary);
	if(!fi) cout<<"file not open!/n";
	fi.get((char&)a);
	fi.get((char&)b);
	fi.get((char&)c);
	cout<<"a="<<a<<"b="<<b<<"c="<<c;
	fi.close();
}

void eof_test(int argc, char* argv[]){
	char ch;
	if(argc!=2){
		cout<<"применение: имя_программы <имя_файла>\n";
		cout<<"имя файла пишется с полным путём к нему";
		exit(1);
	}
	
	ifstream in(argv[1], ios::in|ios::binary);
	if(!in){
		cout<<"Не удаётся открыть файл";
		exit(1);
	}
	
	while(!in.eof()){
		in.get(ch);
		if(!in.eof()) cout<<ch;
	}
	in.close();
}

void file_compare(int argc, char* argv[]){
	int i;
	unsigned char buf1[1024], buf2[1024];
	
	if(argc!=3){
		cout<<"Использование: имя_программы <имя_файла1> <имя_файла2>\n";
	}
	
	ifstream f1(argv[1], ios::in|ios::binary);
	if(!f1){
		cout<<"Не удаётся открыть файл 1";
		exit(1);
	}
	
	ifstream f2(argv[2], ios::in|ios::binary);
	if(!f2){
		cout<<"Не удаётся открыть файл 2";
		exit(1);
	}
	
	cout<<"Сравнение файлов...";
	
	do{
		f1.read((char *)buf1,sizeof(buf1));
		f2.read((char *)buf2,sizeof(buf2));
		
		if(f1.gcount()!=f2.gcount()){
			cout<<"Файлы имеют разные размеры\n";
			f1.close();
			f2.close();
			exit(0);
		}
		
		for(int i =0; i<f1.gcount(); i++){
			if(buf1[i]!=buf2[i]){
				cout<<"Файлы различны\n";
				f1.close();
				f2.close();
				exit(0);
			}
		}
		
	}while(!f1.eof() && !f2.eof());
	
	cout<<"Файлы совпадают";
}

void test_put(int argc, char* argv[]){
	const char *path = "D:\\CPP\\QtPrpjects\\ProjectsCPP\\shildt\\g18\\data\\test_put.txt";
	if(argc!=3){
		cout<<"Применение: имя_программы <имя_файла> <байт>\n";
		cout<<"имя файла пишется с полным путём к нему\n";
	}
	
	fstream out(argv[1], ios::in|ios::out|ios::binary);
	if(!out){
		cout<<"Не удаётся открыть файл.";
		exit(1);
	}
	out.seekp(atoi(argv[2]),ios::beg);
	
	out.put('X');
	out.close();
}

void test_get(int argc, char* argv[]){
	char ch;
	if(argc!=3){
		cout<<"Применение: имя_программы <имя_файла> <стартовая позиция>\n";
		cout<<"имя файла пишется с полным путём к нему\n";
		exit(1);
	}
	
	fstream out(argv[1], ios::in|ios::out|ios::binary);
	if(!out){
		cout<<"Не удаётся открыть файл.";
		exit(1);
	}
	
	out.seekg(atoi(argv[2]),ios::beg);
	
	while(out.get(ch)){
		cout<<ch;
	}
}

int main(int argc, char* argv[]){
	
	return 0;
}



