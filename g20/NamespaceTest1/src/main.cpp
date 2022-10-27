#include <iostream>
#include "rusinconsole.h"
using namespace std;
//Демонстрация использования пространства имён
namespace CounterNamespace{
	int upper_bound;
	int lower_bound;
	
}

namespace CounterNamespace{
	//пространство имён можно разбить на несколько частей
	class counter{
		int count;
	public:
		counter(int n){
			if(n<=upper_bound) count = n;
			else count = upper_bound;
		}
		
		void reset(int n){
			if(n <= upper_bound) count = n;
		}
		
		int run(){
			if(count > lower_bound) return count--;
			else return lower_bound;
		}
	};
	
}

int main(int argc, char* argv[]){
	if(argc==2) cout << "Hello "<<argv[1]<<"\nПривет "<<argv[1]<<endl;
	else cout << "Hello World!\nПривет Мир!\n";
	
	CounterNamespace::upper_bound = 100;
	CounterNamespace::lower_bound = 0;
	
	CounterNamespace::counter ob1(10);
	int i;
	
	do{
		i=ob1.run();
		cout << "ob1::count=" << i << "\n";
	}while(i > CounterNamespace::lower_bound);
	cout<<endl;
	CounterNamespace::counter ob2(20);
	
	do{
		i=ob2.run();
		cout << "ob2::count=" << i << "\n";
	}while(i > CounterNamespace::lower_bound);
	cout<<endl;
	ob2.reset(100);
	CounterNamespace::lower_bound = 90;
	cout<<"ob2 resetted to 100\n";
	cout<<"CounterNamespace::lower_bound resetted to 90\n";
	do{
		i=ob2.run();
		cout << "ob2::count=" << i << "\n";
	}while(i > CounterNamespace::lower_bound);
	cout<<endl;
	return 0;
}

