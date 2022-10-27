#include <iostream>
#include <vector>
#include <list> //для функции transform_sequence()
#include <algorithm>
#include <cctype> //Для функции isvowel()
#include "rusinconsole.h"
using namespace std;
//подсчёт элементов
/*это унарный предикат который определяет, 
представляет ли данный символ гласный звук*/
bool isvowel(char ch){
	ch = tolower(ch);
	if(ch=='a'||ch=='e'||ch=='i'
		||ch=='o'||ch=='u') return true;
	return false;
}

void element_counting(){
	char str[] = "STL-programming -- it is power";
	vector<char> v;
	unsigned int i;
	
	for(i=0; str[i]; i++) v.push_back(str[i]);
	
	cout  << "Vector: ";
	for(i=0; i<v.size(); i++) cout << v[i];
	cout << endl;
	
	int n;
	
	n = count(v.begin(), v.end(), 'm');
	cout << n << " символов m\n";
	
	n = count_if(v.begin(), v.end(), isvowel);
	cout << n << " символов представляющих гласные звуки\n";
}

//Удаление и замена элементов
void remove_copy_and_replace_copy(){
	char str[] = "It is very simple test.";
	vector<char> v, v2(30);
	unsigned int i;
	
	for(i = 0; str[i]; i++) v.push_back(str[i]);
	
	//remove_copy algorithm demonstration
	
	cout << "enitial sequence: ";
	for(i = 0; i < v.size(); i++) cout << v[i];
	cout << endl;
	cout << endl;
	//remove "e" chars
	
	remove_copy(v.begin(), v.end(), v2.begin(), 'e');
	
	cout << "after \"e\" removing: ";
	for(i = 0; i < v2.size(); i++) cout << v2[i];
	cout << endl;
	cout << endl;
	//replace_copy algorithm demonstration
	
	//cout << "enitial vector: ";
	//for(i = 0; i < v.size(); i++) cout << v[i];
	//cout << endl;
	
	//replace "e" by "X"
	
	replace_copy(v.begin(), v.end(), v2.begin(), 'e', 'X');
	cout << "after \"e\" replacing by \"X\": ";
	for(i = 0; i < v2.size(); i++) cout << v2[i];
	cout << endl;
	
}
//Реверсирование последовательности
void reverse_sequence(){
	vector<int> v;
	vector<int>::iterator p;
	unsigned int i;
	for(i=0; i<10; i++) v.push_back(i);
	cout.width(33-14);
	cout << "initial sequence: ";
	
	for(p = v.begin(); p!=v.end(); p++) cout << *p;
	cout << endl;
	
	reverse(v.begin(), v.end());
	
	cout << "reversed sequence: ";
	for(p = v.begin(); p!=v.end(); p++) cout << *p;
	cout << endl;
	
}

//element transformation function
int xform(int i){
	return i*i;
}

template<class T> void list_print(const char* promt, list<T> &lst){
	cout.width(20);
	cout << promt;
	typename list<T>::iterator p;
	p = lst.begin();
	while(p != lst.end()){
		cout.width(3);
		cout << *p <<" ";
		p++;
	}
	cout << endl;
}

void transform_sequence(){
	list<int> xl;
	list<int>::iterator p;
	int i;
	
	//insert values into list
	for(i=0; i<10; i++) xl.push_back(i);
	
	/*cout << "initial list: ";
	p = xl.begin();
	while(p != xl.end()){
		cout << *p <<" ";
		p++;
	}
	cout << endl;*/
	list_print("initial list: ", xl);
	
	//list transform
	
	p = transform(xl.begin(), xl.end(), xl.begin(), xform);
	
	/*cout << "transformed list: ";
	p = xl.begin();
	while(p != xl.end()){
		cout << *p <<" ";
		p++;
	}
	cout << endl;*/
	list_print("transformed list: ", xl);
	
}

int main(int argc, char* argv[]){
	if(argc==2) cout << "Hello "<<argv[1]<<"\nПривет "<<argv[1]<<endl;
	else cout << "Hello World!\nПривет Мир!\n";
	cout << "element counting:" <<endl;
	element_counting();
	cout << "\nremove_copy and replace_copy:" << endl;
	remove_copy_and_replace_copy();
	cout << "\nreverse:" << endl;
	reverse_sequence();
	cout << "\ntransform:" << endl;
	transform_sequence();
	return 0;
}
