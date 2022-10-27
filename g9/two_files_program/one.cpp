#include <iostream>
using namespace std;

int r_avg(int i);
void reset();


int main(int argv, char* argc[]){
	
	int num;
	do{
		cout<<"enter numbers(-1 to exit, -2 to reset): ";
		cin>>num;
		if(num == -2){
			reset();
			continue;
			}
		if(num != -1){
			cout<<"average value is: "<<r_avg(num);
		cout<<'\n';
		}
	}while(num != -1);
	return 0;
}