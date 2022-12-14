#include <iostream>
#include <string>
#include <map> //for storing_strings_in_other_containers() function
#include "rusinconsole.h"
using namespace std;

void working_with_string(){
	string str1("class 'string' allows effectively ");
	string str2("process strings");
	string str3;
	
	//concatenation of two string objects
	str3 = str1 + str2;
	cout << "str3: " << str3 << "\n"; 
	
	//comparison of two string objects
	cout << (str3 > str1 ? "str3 > str1" : "str3 <= str1") << "\n";
	cout << ((str3==str1+str2) ? "str3==str1+str2" : "str3!=str1+str2") << "\n";
	
	//assignment c-string to string 
	str1 = "this is null-terminated string";
	cout << "str1: " << str1 << "\n";
	
	//creating string object using another string object
	string str4(str1);
	cout << "str4: " << str4 << "\n";
	
	//inputting string
	cout << "enter string: ";
	cin >> str4;
	cout << "\nYou entered: " << str4 << endl;
}

void insert_erase_replace_demonstration(){
	string str1("it is simple test.");
	string str2("ABCDEFG");
	
	cout << "initial strings:\n";
	cout << "str1: " << str1 << endl;
	cout << "str2: " << str2 << endl;
	
	//insert() demonstration
	cout << "inserting str2 in 5-th position in str1:\n";
	str1.insert(5, str2);
	cout << "str1 now: " << str1 << "\n\n";
	
	//erase() demonstration
	cout << "deliting 7 simbols beginning from 5-th position in str1:\n";
	str1.erase(5, 7);
	cout << "str1 now: " << str1 << "\n\n";
	
	//replace() demonstration
	cout << "replacing 2 simbols in str1 beginning from 4-th by 5 simbols from str2 beginning from 3-th:\n";
	str1.replace(4, 2, str2, 3, 5);
	cout << "str1 now: " << str1 << "\n\n";
}

void find_demonstration(){
	int i;
	string s1 = "String class makes string processing easier";
	string s2;
	
	i = s1.find("string");
	if(i!=string::npos){
		cout << "Match found at position " << i <<endl;
		cout << "The rest of the line is: ";
		s2.assign(s1, i, s1.size());
		cout << s2.c_str() << endl;
	}else{
		cout << "Match not found" << endl;
	}
}
	
void storing_strings_in_other_containers(){
	map<string, string> dictionary;
	
	dictionary.insert(pair<string, string>(
										string("House"),
										string("Place for living")
										)
					);
	
	dictionary.insert(pair<string, string>(
										string("Keyboard"),
										string("Data inputing device")
										)
					);
	
	dictionary.insert(pair<string, string>(
										string("Programming"),
										string("Program creation process")
										)
					);
	
	dictionary.insert(pair<string, string>(
										string("STL"),
										string("Standard Template Library")
										)
					);
					
	string s;
	
	map<string, string>::iterator p;
	for( ; ; ){
		cout << "Enter word: ";
		cin >> s;
		if(s==string("END")) break;
		p = dictionary.find(s);
		if(p != dictionary.end()){
			cout << "Meaning: " << p->second << "\n";
		}else{
			cout << "Not found.\n";
		}
	}
	
}
	
int main(int argc, char* argv[]){
	if(argc==2) cout << "Hello "<<argv[1]<<"\n???????????? "<<argv[1]<<endl;
	else cout << "Hello World!\n???????????? ??????!\n";
	//working_with_string();
	//insert_erase_replace_demonstration();
	//find_demonstration();
	//storing_strings_in_other_containers();
	
	return 0;
}
