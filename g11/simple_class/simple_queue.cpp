#include "simple_queue.h"

queue::queue(int id)
{
	sloc=rloc=0;
	who=id;
	std::cout<<"очередь "<< who << " иницализирована\n";
}

queue::~queue()
{
	std::cout<<"очередь "<< who << " разрушена\n";
}

void queue::qput(int i)
{
	if(sloc==100){
		std::cout<<"очередь "<< who << " заполнена\n";
		return;
	}
	std::cout<<"добавили "<<i<<" в очередь "<< who << "\n";
	sloc++;
	q[sloc]=i;
}

int queue::qget()
{
	if(sloc==rloc){
		std::cout<<"очередь "<< who << " пуста\n";
		return 0;
	}
	rloc++;
	return q[rloc];
}