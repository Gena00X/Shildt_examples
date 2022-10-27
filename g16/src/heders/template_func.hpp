#ifndef TEMPLATE_FUNC_H
#define TEMPLATE_FUNC_H
#include <cstring>
template<class X> void swapargs(X &a, X &b){
	X temp = a;
	a = b;
	b = temp;
}

template<> void swapargs<long long>(
			long long &a,//specialisation of template  
			long long &b)//for long long in new stile			 
			{
	long long temp = a;
	a = b;
	b = temp;
}


void swapargs(char* a, char* b) //special version of function for char*
{
	char* temp = new char[80]; 
	strcpy(temp,a);
	strcpy(a,b);
	strcpy(b, temp);
	delete temp;
	
}

#endif