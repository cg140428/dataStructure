#ifndef QUEUE_CPP
#define QUEUE_CPP

#include "lab4.h"

int main(void) {

	Queue q;
	q.enQueue(1);
	q.enQueue(2);
	q.enQueue(3);
	q.enQueue(4);
	q.enQueue(5);
	q.enQueue(6);
	//q.print();
	q.deQueue();
	q.deQueue();
	q.deQueue();
	q.deQueue();
	q.deQueue();
	//q.deQueue();

	return 0;
}
#endif
