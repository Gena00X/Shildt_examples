#ifndef TEMPLATE_QUEUE_H
#define TEMPLATE_QUEUE_H
#include <iostream>

template<class QType, int SIZE =100> class queue{
	QType q[SIZE];
	int sloc, rloc;
public:
	queue(){sloc = 0; rloc = 0;}
	void  qput(QType i);
	QType qget();
};

template<class QType, int SIZE> 
void queue<QType, SIZE>::qput(QType i)
{
	if(sloc==SIZE)
	{
		std::cout<<"Очередь заполнена"<<std::endl;
		return;
	}
	sloc++;
	q[sloc] = i;
}

template<class QType, int SIZE> 
QType queue<QType, SIZE>::qget()
{
	if(rloc == sloc)
	{
		std::cout<<"Очередь пуста"<<std::endl;
		return 0;
	}
	rloc++;
	return q[rloc];
}

#endif //TEMPLATE_QUEUE_H