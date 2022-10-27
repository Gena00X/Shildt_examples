#ifndef STR_TYPE_H
#define STR_TYPE_H
#include <iostream>
#include <cstring>
#include "C:\Users\User\Desktop\QtPrpjects\ProjectsCPP\rusinconsole.h"
class str_type
{
	char string[1000];
	int search(
			   const char* string /*строка*/, 
			   const char* part /*образец*/
			   );
public:
	str_type(const char *str ="");
	
	str_type operator+(str_type str);
	str_type operator+(const char *str);
	
	str_type operator-(str_type str);
	
	str_type operator=(str_type str);
	str_type operator=(const char *str);
	
	void show();
	
};
#endif //STR_TYPE_H