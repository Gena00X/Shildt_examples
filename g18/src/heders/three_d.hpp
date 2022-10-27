#ifndef THREE_D_H
#define THREE_D_H
#include <iostream>
using namespace std;
class three_d{
	int x, y, z;
public:
	three_d()
	{
		x = y = z = 0;
		cout<<"three_d конструктор по умолчанию\n";
	}
	three_d(int i, int j, int k)
	{
		x = i; y = j; z = k;
		cout<<"three_d конструктор с параметрами: i = "<<i<<", j = "<<j<<", k = "<<k<<"\n";
	}
	~three_d()
	{
		cout<<"Разрушение объекта three_d\n";
	}
	
	void *operator new(size_t size);
	void *operator new[](size_t size);
	void operator delete(void *p);
	void operator delete[](void *p);
	void show();
	friend ostream &operator<<(ostream &os, three_d &obj);
	friend istream &operator>>(istream &is, three_d &obj);

};
#endif //THREE_D_H