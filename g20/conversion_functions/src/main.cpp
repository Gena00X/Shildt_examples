#include <iostream>
#include "rusinconsole.h"
using namespace std;

class three_d{

	int x, y, z;

public:

	three_d(int a, int b, int c){x = a; y = b; z = c;}
	
	three_d operator+(three_d op2);

	friend ostream &operator<<(ostream &stream, three_d &obj);
	
	operator int(){ return x * y * z; }
	
};

ostream &operator<<(ostream &stream, three_d &obj){
	stream 	<< "{" 
			<< " \nx = " << obj.x 
			<< ",\ny = " << obj.y 
			<< ",\nz = " << obj.z 
			<< "\n}";
	return stream;
}

three_d three_d::operator+(three_d op2){
	three_d temp(0, 0, 0);
	temp.x = x + op2.x;
	temp.y = y + op2.y;
	temp.z = z + op2.z;
	return temp;
}

int main(int argc, char* argv[]){
	if(argc==2) cout << "Hello "<<argv[1]<<"\nПривет "<<argv[1]<<endl;
	else cout << "Hello World!\nПривет Мир!\n";
	
	three_d a(1, 2, 3), b(2, 3, 4);
	
	cout<< "a=" << a<< "b=" << b;
	
	cout << 100+b; //работает функция преобразования в int
	
	cout << "\n";
	
	a = a + b;
	
	cout << "a + b =" << a;
	
	return 0;
}
