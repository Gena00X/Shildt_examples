#include <iostream>
#include "rusinconsole.h"
using namespace std;

int main(int argc, char* argv[]){
	if(argc==2) cout << "Hello "<<argv[1]<<"\nПривет "<<argv[1]<<endl;
	else cout << "Hello World!\nПривет Мир!\n";

	
	return 0;
}
