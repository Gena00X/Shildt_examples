#include <iostream>
#include <map>
#include <cstring>
#include "rusinconsole.h"
using namespace std;

void simple_map_usage(){
	//Демонстрация использования простого отображения (map)
	map<char, int> m;
	int i;
	
	cout << "adding key-value pairs into map\n";
	for(i=0; i<10; i++){
		m.insert(pair<char, int>('A'+i, i));
	}
	char ch;
	ch = 'A';
	while('A'<=ch&&ch<='Z'){
		cout << "enter key: ";
		cin >> ch;
		map<char, int>::iterator p;
		
		cout<<"serching key...\n";
		p = m.find(ch);
		if(p != m.end()){
			cout << p->first <<": " << p->second <<'\n'; 
		}else{
			cout << "key " << ch << " not found\n";
		}
	}
}

class word{
	char str[20];
public:
	word () { strcpy(str, ""); }
	word (const char *s){ strcpy(str, s); }
	const char *get() const { return str; }
	friend bool operator<(const word &a, const word &b);
};

bool operator<(const word &a, const word &b){
	return strcmp(a.get(), b.get())<0;
}

class meaning{
	char str[80];
public:
	meaning(){ strcpy(str, ""); }
	meaning(const char *s){ strcpy(str, s); }
	const char *get() const { return str; }
};

void simple_dictionary(){
	//Использование  отображения для создания словаря
	map<word, meaning> dictionary;
	
	dictionary.insert(pair<word, meaning>(
										word("House"),
										meaning("Place for living")
										)
					);
	
	dictionary.insert(pair<word, meaning>(
										word("Keyboard"),
										meaning("Data inputing device")
										)
					);
	
	dictionary.insert(pair<word, meaning>(
										word("Programming"),
										meaning("Program creation process")
										)
					);
	
	dictionary.insert(pair<word, meaning>(
										word("STL"),
										meaning("Standard Template Library")
										)
					);
	
	//find the word definition for the word
	
	char str[80];
	map<word, meaning>::iterator p;
	for( ; ; ){
		cout << "Enter word: ";
		cin >> str;
		if(!strcmp(str, "END")) break;
		p = dictionary.find(word(str));
		if(p != dictionary.end()){
			cout << "Meaning: " << p->second.get() << "\n";
		}else{
			cout << "Not found.\n";
		}
	}
}

int main(int argc, char* argv[]){
	if(argc==2) cout << "Hello "<<argv[1]<<"\nПривет "<<argv[1]<<endl;
	else cout << "Hello World!\nПривет Мир!\n";
	simple_map_usage();
	simple_dictionary();
	return 0;
}
