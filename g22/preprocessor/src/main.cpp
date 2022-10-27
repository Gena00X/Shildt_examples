#include <iostream>
#include "rusinconsole.h"
using namespace std;
//simple macros
#define MYMACRO_STR "very long string"
#define MYMACRO_NUM 100 
//function-like macros
#define MY_USED_LIKE_FUNCTION_MACRO(a, b) (((a)<(b)) ? a : b )  
#define INVALID_FUNCTION_LIKE_MACRO_EVEN(a) a%2==0 ? 1 : 0 //должен возвращать 1 если число чётное 
#define VALID_FUNCTION_LIKE_MACRO_EVEN(a) (a)%2==0 ? 1 : 0 //должен возвращать 1 если число чётное 



void simple_macros(){
	cout << "macros with string: " << MYMACRO_STR << endl;
	cout << "macros with num: " << MYMACRO_NUM << endl;
	cout << "using macros with num: " << MYMACRO_NUM+20 << endl;
}

void used_like_function_macros(){
	int a, b;
	a = 10;
	b = 20;
	
	cout << "min is " << MY_USED_LIKE_FUNCTION_MACRO(a+b, b);
}

void common_error_in_used_like_function_macro_demonstration(){
	cout << "using macro \n\"INVALID_FUNCTION_LIKE_MACRO_EVEN(a) a%2==0 ? 1 : 0\"\n"
"without parentheses around variable with argument \"9+1\"\n (there will be an error):\n";
	if(INVALID_FUNCTION_LIKE_MACRO_EVEN(9+1)) cout << 9+1 << " is even value\n";
	else cout << 9+1 << " is not even value\n";
	
	cout << "using macro \n\"VALID_FUNCTION_LIKE_MACRO_EVEN(a) (a)%2==0 ? 1 : 0\"\n"
"with parentheses around variable with argument \"9+1\"\n (there will be correct answer):\n";
	if(VALID_FUNCTION_LIKE_MACRO_EVEN(9+1)) cout << 9+1 << " is even value\n";
	else cout << 9+1 << " is not even value\n";
	
}

//conditional compilation directives
#define MAX 100

void CCD_if(){
	#if MAX>10
	cout << "MAX > 10\n";
	#endif
	#if MAX>200
	cout << "MAX > 200\n"; //it will not be compiled
	#endif
	cout << "MAX = " << MAX << endl;
}

void CCD_if_else(){
	#if MAX>200
	cout << "MAX > 200\n"; //it will not be compiled
	#elif 10<MAX<200
	cout << "MAX between 10 and 200\n";
	#else 
	cout << "MAX < 10";//it will not be compiled
	#endif
	
	#if MAX>300
	cout << "MAX > 300\n"; //it will not be compiled
	#elif MAX>200
	cout << "MAX > 200\n"; //it will not be compiled
	#else 
	cout << "MAX <= 200\n";
	#endif
	
	cout << "MAX = " << MAX << endl;
}

#define TOM

void CCD_ifdef_and_ifndef_test(){
	#ifdef TOM
		cout << "Name Tom defined.\n";//it will be compiled
	#else 
		cout << "Name Tom undefined.\n";//it will NOT be compiled
	#endif
	
	#if defined TOM
		cout << "Name Tom defined.\n";//it will be compiled
	#else 
		cout << "Name Tom undefined.\n";//it will NOT be compiled
	#endif
	
	#ifndef RALPH
		cout << "Name Ralph undefined.\n"; //it will be compiled
	#endif
	
	#if !defined RALPH
		cout << "Name Ralph undefined.\n"; //it will be compiled
	#endif
	
	#ifndef TOM
		cout << "Name Tom undefined.\n"; //it will NOT be compiled
	#endif
	
	#if !defined TOM
		cout << "Name Tom undefined.\n"; //it will NOT be compiled
	#endif
	
	#undef TOM //undefuine macro TOM 
	
	#ifndef TOM
		cout << "Now name Tom undefined.\n"; //it will be compiled
	#endif
	
	#if !defined TOM
		cout << "Now name Tom undefined.\n"; //it will be compiled
	#endif
}
void CCD_line(){
	cout << "__LINE__: " << __LINE__ << " __FILE__: " << __FILE__ << "\n";
	cout << "#line 0 \"GENA\"\n"; 
	#line 0 "GENA" //меняет значение переменных __LINE__ и __FILE__ на новые
	cout << "__LINE__: " << __LINE__ << " __FILE__: " << __FILE__;
}

struct s1{
	char  a;
	long  b;
	int   c;
	float d;
};

#pragma pack(1)
struct s2{
	char  a;
	long  b;
	int   c;
	float d;
};
#pragma pack()

void CCD_pragma(){
	cout << "size s1: " << sizeof(s1) << "\n";
	cout << "size s2: " << sizeof(s2) << "\n";
}

// операторы # и ## используются совместно с #define 
// # преобразует следующий за ним аргумент в строку
// ## объединяет свои аргументы

#define mkstr(s) # s

#define concat(a, b) a ## b

void CCD_sharp(){
	cout << "mkstr: " << mkstr(Mama mila ramu);
	cout << endl;
	int xy = 100;
	int x, y;
	
	cout << "concat(x, y): " << concat(x, y);
	cout << endl;
}



void CCD_vars(){
	
	#ifdef __LINE__
		cout << "Name __LINE__ defined.\n";
		cout << "__LINE__ = " << __LINE__ << endl;
	#else 
		cout << "Name __LINE__ undefined.\n";
	#endif
	
	#ifdef __FILE__
		cout << "Name __FILE__ defined.\n";
		cout << "__FILE__ = " << __FILE__ << endl;
	#else 
		cout << "Name __FILE__ undefined.\n";
	#endif
	
	#ifdef __DATE__
		cout << "Name __DATE__ defined.\n";
		cout << "__DATE__ = " << __DATE__ << endl;
	#else 
		cout << "Name __DATE__ undefined.\n";
	#endif

	#ifdef __TIME__
		cout << "Name __TIME__ defined.\n";
		cout << "__TIME__ = " << __TIME__ << endl;
	#else 
		cout << "Name __TIME__ undefined.\n";
	#endif
	
	#ifdef __STDC__
		cout << "Name __STDC__ defined.\n";
		cout << "__STDC__ = " << __STDC__ << endl;
	#else 
		cout << "Name __STDC__ undefined.\n";
	#endif
	
	#ifdef __cplusplus
		cout << "Name __cplusplus defined.\n";
		cout << "__cplusplus = " << __cplusplus << endl;
	#else 
		cout << "Name __cplusplus undefined.\n";
	#endif
	
}

int main(int argc, char* argv[]){
	if(argc==2) cout << "Hello "<<argv[1]<<"\nПривет "<<argv[1]<<endl;
	else cout << "Hello World!\nПривет Мир!\n";
	
	
	return 0;
}
