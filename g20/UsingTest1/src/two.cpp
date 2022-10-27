
#include <iostream>

using std::cout;

namespace{
	int CN_upper_bound = 100;
	int CN_lower_bound = 0;
	int test_var_1 = 100;
}

void two_show(){
	cout << "in two.cpp CN_upper_bound = "<<CN_upper_bound<<"\n";
	cout << "in two.cpp CN_lower_bound = "<<CN_lower_bound<<"\n";
	cout << "in two.cpp test_var_1 = "<<test_var_1<<"\n";
}