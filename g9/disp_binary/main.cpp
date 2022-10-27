#include <iostream>
#include <conio.h>
//#include <ctype.h>
#include <Windows.h>
using namespace std;

void disp_binary(unsigned u)
{
		register int t;
		for(t=128; t>0; t/=2)
			if(u & t) cout << 1;
			else cout << 0;
		cout<< '\n';
}

template<class T> void d_bin(T u)
{
	int size = sizeof(T)*8;
	for(int i = size-1; i>=0; i--)
	{
		if((u&(1<<i))) cout << 1;
			else cout << 0;
	}
	cout<<'\n';
	//1<<i:
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
	//позиции i числа u стоит 1
}

int main(int argv, char* argc[]){
	SetConsoleOutputCP(CP_UTF8);
	unsigned u =0;
	char test;
	
	while(true)
	{
		cout<<"введите число в диапазоне 0-255\n";
		cout<<"(или список чисел через пробел)\n";
		cout<<"Для выхода нажмите q\n>>";
		cin>> test;
		if(isdigit(test)||test=='-') 
		{
			cin.putback(test);
			cin >> u;
			//disp_binary(u);
			cout<<u <<" в двоичной записи: "<<'\t';
			d_bin(u);
		}
		else if(test=='q'){
			break;
		}
		else{
			cout<<"ошибка: "<<test<<" не число!\n";
		}

	}
	return 0;
}