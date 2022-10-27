#include <iostream>
#include <cstdlib>
using namespace std;

void play(int);

int main(int argv, char* argc[]){
	int option, magic;
	
	magic = rand();
	
	do{
		cout<<"1.\t Get new magic number\n";
		cout<<"2.\t Play game\n";
		cout<<"3.\t Exit\n";
		do{
			cout<<"Enter your choise: ";
			cin>>option;
		}while(option<1||option>3);
		
		switch(option){
			case 1:
				magic = rand();
				break;
			case 2:
				play(magic);
				break;
			case 3:
				cout<<"Goodbye!\n";
				break;
		}
	}while(option!=3);

	return 0;
}

void play(int m){
	int t, x, nt;
	nt=0;
	for(t=0;t<100;t++){
		cout << "Guess magic number: ";
		cin >> x;
		nt++;
		if(x==m){
			cout<<"** True **\n";
			cout<<"You do it for "<<nt<<" tries\n";
			return;
		}
		else
			if(x<m) cout << "Not enough.\n";
			else cout << "Too much. \n";
	}
	cout<< "You used every chance to guess magic number. Try again\n";
}
	












