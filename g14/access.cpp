#include <iostream> 

using namespace std;

class base
{
private:
	int i, j;
public:
	void set(int a, int b){ i = a; j = b; }
	void show(){ cout<<"base: "<<"i: "<< i <<" j: "<< j <<'\n'; }
};

class derived : public base
{
private:
	int k;
public:
	derived(int x){ k = x;}
	void showk(){ cout<<"derived: public: base: k:" << k << '\n'; }
};

class derived2 : private base
{
private:
	int k;
public:
	derived2(int x){ k = x;}
	void showk(){ cout<<"derived 2: k = "<< k << '\n'; }
};

class base_protected
{
protected:
	int j, k;
public:
	void set(int a, int b){ j = a, k = b; }
	void show(){ cout << j << " " << k << '\n';}
};

class derived_protected : public base_protected
{
	int k;
public:
	void setk(){ k = i*j;}
	void showk(){ cout << k <<'\n'; }
};
int main(int argv, char* argc[])
{
	derived ob(3);
	
	ob.set(1, 2);
	ob.show();
	
	ob.showk();
	
	derived2 ob2(3);
	
	//ob2.set(1, 2);//error
	//ob2.show();//error
	
	ob2.showk();
	
	//derived_protected
	derived_protected ob_dp;
	
	ob_dp.set(2, 3);
	ob_dp.show();
	
	ob_dp.setk();
	ob_dp.showk();
	
	
	return 0;
}