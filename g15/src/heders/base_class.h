#ifndef base_class
#define base_class
#include <cstring>
class my_base_class{
private:
	const char* myname = "base_class";
public:
	virtual const char* showname(){ return myname; }
};

class derived1:virtual public my_base_class{
private:
	const char* myname = "derived1";
public:
	virtual const char* showname(){ return myname; }
};

class derived2:virtual public my_base_class{
private:
	const char* myname = "derived2";
public:
	virtual const char* showname(){ return myname; }
};

class derived_1_2:public derived1, public derived2{
	private:
	const char* myname = "derived_1_2";
	char temp[80];
public:
	virtual const char* showname()
	{ 
		
		strcpy(temp, derived1::showname()); 
		strcat(temp, " + ");
		strcat(temp, derived2::showname()); 
		strcat(temp, " = ");
		strcat(temp, myname); 
		strcat(temp, "\n");
		return temp;
	}
};

#endif //base_class