#ifndef QUEUE_H
#define QUEUE_H

#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif //IOSTREAM

//простая очередь: первым пришел первыи обработан
class queue{
	int q[100];
	int sloc, rloc;
	int who;
public:
	queue(int i);
	~queue();
	void qput(int i);
	int qget();
};

#endif //QUEUE_H
