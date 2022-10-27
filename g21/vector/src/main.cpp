#include <iostream>
#include <vector>
#include "rusinconsole.h"
using namespace std;

void base_vector_functionality(){
	//демонстрация базового поведения вектора
	vector<int> v;
	unsigned int i;
	
	cout << "Initial vector v size. v.size() = " << v.size() << endl;
	
	for(i = 0; i<10; i++) v.push_back(i);
	
	cout << "vector v size now is. v.size() = " << v.size() << endl;
	
	cout << "vector v:" << endl;
	for(i = 0; i<v.size(); i++) cout << "v[" << i << "] = " << v[i] << endl;
	
	cout << "add some new values to vector v" << endl;
	
	for(i = 0; i<10; i++) v.push_back(i+10);
	
	cout << "new vector v size is. v.size() = " << v.size() << endl;
	
	cout << "updated vector v:" << endl;
	for(i = 0; i<v.size(); i++) cout << "v[" << i << "] = " << v[i] << endl;
	
	cout << "modifing vector v values" << endl;
	vector<int> v2(v.size());
	for(i = 0; i<v.size(); i++){
		
		//cout<< "v[" << i << "] = " << v[i] << endl;
		//cout<< "v[" << (v.size()-1)-i << "] = " << v[(v.size()-1)-i] << endl;
		
		v2[i] = v[i]+v[(v.size()-1)-i];
	}
	v=v2;
	cout << "updated vector v:" << endl;
	for(i = 0; i<v.size(); i++) cout << "v[" << i << "] = " << v[i] << endl;
	
}

void iterator_for_vector(){
	//доступ к вектору с помощью итератора
	vector<char> v;
	int i;
	
	for(i = 0; i<10; i++) v.push_back('A'+i);
	
	for(i = 0; i<v.size(); i++) cout << "v[" << i << "] = " << v[i] << endl;
	
	vector<char>::iterator p = v.begin();
	cout << "v = {";
	while(p != v.end()){
		cout << *p;
		if(p != v.end()-1) cout << ", ";
		p++;
	}
	cout<<"}"<<endl;
}

void adding_and_deleting_elements_in_vector(){
	//вставка и удаление элементов вектора
	
	vector<char> v;
	unsigned int i;
	
	
	for(i=0; i<10; i++) v.push_back('A' + i);
	
	cout << "v.size() = " << v.size() << endl;
	cout << "vector v initial values:\nv = {";
	for(i=0; i<v.size(); i++){ 
		cout << v[i]; 
		if(i!=v.size()-1) cout<<", "; 
	}
	cout << "}\n";
	cout << endl;
	
	vector<char>::iterator p = v.begin();
	p += 2;
	
	cout << "inserting 10 \'X\' simbols in position 3\n";
	v.insert(p, 10, 'X');
	
	cout << "new vector size. v.size() = " << v.size() << endl;
	cout << "vector v new values:\nv = {";
	for(i=0; i<v.size(); i++){ 
		cout << v[i]; 
		if(i!=v.size()-1) cout<<", "; 
	}
	cout << "}\n";
	cout << endl;
	
	cout<<"deliting inserted elements\n";
	p = v.begin();
	p +=2;
	v.erase(p, p+10);
	
	cout << "new vector size after erase(p, p+10); operation.\n(p points to the third element) \nv.size() = " << v.size() << endl;
	cout << "vector v new values after erase operation:\nv = {";
	for(i=0; i<v.size(); i++){ 
		cout << v[i]; 
		if(i!=v.size()-1) cout<<", "; 
	}
	cout << "}\n";
	cout << endl;
}

class three_d{
	int x, y, z;
public:
	three_d(){ x = y = z = 0; }
	three_d(int a, int b, int c) { x = a; y = b; z = c; }
	three_d &operator+(int a) {
		x += a;
		y += a;
		z += a;
		return *this;
	}
	
	friend ostream &operator<<(ostream &stream, three_d &obj);
	friend bool operator<(three_d &a, three_d &b);
	friend bool operator==(three_d &a, three_d &b);
};

ostream &operator<<(ostream &stream, three_d &obj){
	stream << "three_d: { ";
	stream << obj.x <<", ";
	stream << obj.y <<", ";
	stream << obj.z <<" }\n";
	return stream;
}

bool operator<(three_d &a, three_d &b){
	return (a.x + a.y + a.z) < (b.x + b.y + b.z);
}

bool operator==(three_d &a, three_d &b){
	return (a.x + a.y + a.z) == (b.x + b.y + b.z);
}

void objects_in_vector(){
	//хранение в векторе объектов класса
	vector<three_d> v;
	unsigned int i;
	
	cout<<"adding objects to vector\n";
	for(i=0; i<10; i++) v.push_back(three_d(i, i+2, i-3));
	
	cout << "showing vector:\n";
	for(i=0; i<v.size(); i++)
		cout << v[i];
	cout<<endl;
	
	cout << "Modifing objects in vector\n";
	for(i=0; i<v.size(); i++)
		v[i] = v[i] + 10;
	
	cout << "showing modifed vector:\n";
	for(i=0; i<v.size(); i++)
		cout << v[i];
	cout<<endl;
}

void using_iterators_for_operation_with_two_vectors(){
	//использование итераторов для работы одновременно с двумя векторами
	//вставляем один вектор в другой
	vector<char> v1, v2;
	unsigned int i;
	
	for(i=0; i<10; i++) v1.push_back('A'+i);
	
	cout << "vector v1 values:\nv1 = {";
	for(i=0; i<v1.size(); i++){ 
		cout << v1[i]; 
		if(i!=v1.size()-1) cout<<", "; 
	}
	cout << "}\n";
	
	char str[] = "- STL -- it is power! -";
	for(i=0; str[i]; i++) v2.push_back(str[i]);
	
	cout << "vector v2 values:\nv1 = {";
	for(i=0; i<v2.size(); i++){ 
		cout << v2[i]; 
		if(i!=v1.size()-1) cout<<", ";
	}
	cout << "}\n";
	
	//creating iterators for two vectors
	vector<char>::iterator p1 = v1.begin()+5;
	vector<char>::iterator p2start = v2.begin();
 	vector<char>::iterator p2end = v2.end();
	
	//inserting vector v2 in vector v1
	v1.insert(p1, p2start, p2end);
	
	cout << "vector v1 values after insertion v2:\nv1 = {";
	for(i=0; i<v1.size(); i++){ 
		cout << v1[i]; 
		if(i!=v1.size()-1) cout<<", ";
	}
	cout << "}\n";
}

int main(int argc, char* argv[]){
	if(argc==2) cout << "Hello "<<argv[1]<<"\nПривет "<<argv[1]<<endl;
	else cout << "Hello World!\nПривет Мир!\n";
	base_vector_functionality();
	iterator_for_vector();
	adding_and_deleting_elements_in_vector();
	objects_in_vector();
	using_iterators_for_operation_with_two_vectors();
	return 0;
}