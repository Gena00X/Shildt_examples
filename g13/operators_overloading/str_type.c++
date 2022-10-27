#include "str_type.h"

int str_type::search(
					const char* string /*строка*/, 
					const char* part /*образец*/
					)
{
    int N = strlen(string);
    int M =  strlen(part);
    int i=0, j=0;
    while((i<=N-M)&&(j<M)){
        if(string[i+j]==part[j]){
                j++;
                continue;
        }
        if(string[i+j]!=part[j]){
                j=0;
                i++;
                continue;
        }
    }
    return (j==M) ? i : -1;
}

str_type::str_type(const char *str)
{
	strcpy(string, str);
}

str_type str_type::operator+(str_type str)
{
	str_type temp;
	
	strcpy(temp.string, string);
	strcat(temp.string, str.string);
	return temp;
}

str_type str_type::operator+(const char *str)
{
	str_type temp;
	
	strcpy(temp.string, string);
	strcat(temp.string, str);
	
	return temp;
}

str_type str_type::operator-(str_type str){
	str_type temp, temp2;
	strcpy(temp.string, string);
	strcpy(temp2.string, string);
	
	int len = strlen(str.string);
	int i = 0;
	while(true){
	i = search(temp.string, str.string);
	if(i==-1)break;
	temp.string[i]='\0';
	strcat(temp.string, &temp2.string[i+len]);
	std::cout<<"in operator-(): "<<temp.string<<'\n';
	strcpy(temp2.string, temp.string);
	}
	return temp;
}


str_type str_type::operator=(str_type str)
{
	strcpy(string, str.string);
	return *this;
}	

str_type str_type::operator=(const char *str)
{
	str_type temp;
	
	strcpy(string, str);
	strcpy(temp.string, string);
	
	return temp;
}

void str_type::show()
{
	std::cout << string<<'\n';
}