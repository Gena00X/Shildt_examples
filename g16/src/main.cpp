#include "heder1.hpp"
#include "template_func.hpp"
#include "template_queue.hpp"
void template_func_test()
{
	cout<<"приветики\n";
	int a = 1, b = 2;
	cout<<"int a = "<<a<<" int b = "<<b<<endl;
	cout<<"swapargs(int&, int&)"<<endl;
	swapargs(a,b);
	cout<<"a = "<<a<<" b = "<<b<<endl;
	
	char ca = 'a', cb = 'b';
	cout<<"char ca = "<<ca<<" cb = "<<cb<<endl;
	cout<<"swapargs(char&, char&)"<<endl;
	swapargs(ca,cb);
	cout<<"ca = "<<ca<<" cb = "<<cb<<endl;
	
	const char *str1 = "str1", *str2="str2";
	cout<<"str1 = \""<<str1<<"\" str2 = \""<<str2<<"\""<<endl;
	cout<<"swapargs(char*, char*)"<<endl;
	swapargs(str1, str2);
	cout<<"str1 = \""<<str1<<"\" str2 = \""<<str2<<"\""<<endl;
	
	long long lla = 1, llb = 2;
	cout<<"long long lla = "<<lla<<" llb = "<<llb<<endl;
	cout<<"swapargs(long long&, long long&)"<<endl;
	swapargs(lla,llb);
	cout<<"lla = "<<lla<<" llb = "<<llb<<endl;
}

int main(int argv, char* argc[]){
	char a = 'a', b = 'b', c = 'c';
	queue<char,3> cq;
	cout<<"queue<char,2> cq;"<<endl;
	cout<<"cq.qput(a):";
	cq.qput(a);
	cout<<endl<<"cq.qput(b);";
	cq.qput(b);
	cout<<endl<<"cq.qput(c);";
	cq.qput(c);
	
	cout<<endl<<cq.qget()<<" ";
	cout<<cq.qget()<<" ";
	cout<<cq.qget()<<endl;
	return 0;
}