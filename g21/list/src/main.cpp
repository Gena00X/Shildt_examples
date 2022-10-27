#include <iostream>
#include <list>
#include <cstdlib>//for sorting_list()
#include <cstring>//for store_class_objects_in_list()
#include "rusinconsole.h"
using namespace std;
//1
void list_base_operations(){
	//базовые операции для списка (list)
	
	list<char> lst; //creating empty list
	int i;
	
	for(i=0; i<63; i++) lst.push_back('A'+i);
	
	cout << "list size now is " << lst.size() << endl;
	
	cout << "listed values: ";
	list<char>::iterator p = lst.begin();
	while(p != lst.end()){
		cout << *p;
		p++;
	}
	cout << endl;
}
//2
void list_reverse(){
	//обавление элементов в начало и конец списка
	list<char> lst;
	list<char> revlst;
	int i;
	
	for(i=0; i<10; i++) lst.push_back('A'+i);
	
	cout << "lst size iz " << lst.size() << endl;
	cout << "listed values: ";
	list<char>::iterator p = lst.begin();

	while(!lst.empty()){
		p = lst.begin();
		cout << *p;
		revlst.push_front(*p);
		lst.pop_front();
	}
	cout << endl << endl;
	
	cout << "revlst size is " << revlst.size() << endl;
	
	cout << "revlst values: ";
	p = revlst.begin();
	while(p != revlst.end()){
		cout << *p;
		p++;
	}
	cout << endl;
	
}
//3
void sorting_list(){
	list<int> lst;
	int i;
	
	for(i=0; i<10; i++){
		lst.push_back(rand());
	}
	
	cout << "lst initial values: ";
	list<int>::iterator p = lst.begin();
	while(p != lst.end()){
		cout << *p << " ";
		p++;
	}
	cout << endl << endl;
	
	cout << "list sorting\n";
	lst.sort();
	
	cout << "sorted lst values: ";
	p = lst.begin();
	while(p != lst.end()){
		cout << *p << " ";
		p++;
	}
	cout << endl;
	
}
//4
void merge_lists(){
	list<char> lsta, lstb;
	int i;
	
	for(i=0; i<10; i+=2) lsta.push_back('A'+i);
	for(i=1; i<11; i+=2) lstb.push_back('A'+i);
	
	cout << "lsta: ";
	list<char>::iterator p = lsta.begin();
	while(p != lsta.end()){
		cout << *p << " ";
		p++;
	}
	cout << endl << endl;
	cout << "lstb: ";
	p = lstb.begin();
	while(p != lstb.end()){
		cout << *p << " ";
		p++;
	}
	cout << endl << endl;
	
	cout << "merge lsta and lstb\n";
	
	lsta.merge(lstb);
	
	if(lstb.empty()){
		cout << "lstb is empty\n";
	}
	
	cout << "lsta: ";
	p = lsta.begin();
	while(p != lsta.end()){
		cout << *p << " ";
		p++;
	}
	cout << endl << endl;
}

class myclass{
	int a, b;
	int sum;
public:
	myclass(){a = b = sum = 0;}
	myclass(int i, int j){
		a = i;
		b = j;
		sum = a + b;
	}
	int getsum(){return sum;}
	
	friend bool operator<(const myclass &o1, 
						  const myclass &o2);
	
	friend bool operator>(const myclass &o1, 
						  const myclass &o2);
	
	friend bool operator==(const myclass &o1, 
						   const myclass &o2);
	
	friend bool operator!=(const myclass &o1, 
						   const myclass &o2);
	
};

bool operator<(const myclass &o1, const myclass &o2){
	return o1.sum < o2.sum;
}

bool operator>(const myclass &o1, const myclass &o2){
	return o1.sum > o2.sum;
}

bool operator==(const myclass &o1, const myclass &o2){
	return o1.sum == o2.sum;
}

bool operator!=(const myclass &o1, const myclass &o2){
	return o1.sum != o2.sum;
}
//5
void store_class_objects_in_list(){
	//Хранение в списке объектов класса
	int i;
	
	list<myclass> lst_1;
	
	for(i = 0; i < 10; i++){
		lst_1.push_back(myclass(i, i));
	}
	
	list<myclass>::iterator p = lst_1.begin();
	cout << "lst_1: ";
	while(p != lst_1.end()){
		cout << p->getsum() << " ";
		p++;
	}
	cout << endl;
	
	list<myclass> lst_2;
	for(i=0; i<10; i++){
		lst_2.push_back(myclass(i*2, i*3));
	}
	
	cout << "lst_2: ";
	p = lst_2.begin();
	while(p != lst_2.end()){
		cout << p->getsum() << " ";
		p++;
	}
	cout << endl;
	
	cout << "merge lst_1 and lst_2\n";
	lst_1.merge(lst_2);
	
	if(lst_2.empty()) cout << "lst_2 empty\n";
	
	cout << "merged list: ";
	p = lst_1.begin();
	while(p != lst_1.end()){
		cout << p->getsum() << " ";
		p++;
	}
	cout << endl << endl;
}

int main(int argc, char* argv[]){
	if(argc==2) cout << "Hello "<<argv[1]<<"\nПривет "<<argv[1]<<endl;
	else cout << "Hello World!\nПривет Мир!\n";
	list_base_operations();
	list_reverse();
	sorting_list();
	merge_lists();
	store_class_objects_in_list();
	return 0;
}
