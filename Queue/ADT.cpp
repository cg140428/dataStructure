#ifndef ADT_CPP
#define ADT_CPP
#include "lab4.h"

Queue::Queue() {
	front = -1;
	rear = -1;
	flag = false;
}
void Queue::enQueue(int val) {
	if (isFull()) {
		cout << "Queue Full" << endl;
	}
	else {
		flag = true;
		queue[++rear] = val;
		rear %= sizeQueue;
	}
}
int Queue::deQueue() {
	if (isEmpty())
		return isEmpty();
	else {
		flag = false;
		return queue[++front];
	}
}
bool Queue::isFull() {
	if (rear == front && flag == true)
		return true;
	else
		return false;
}
bool Queue::isEmpty() {
	if (front == rear && flag == false)
		return true;
	else
		return false;
}
void Queue::print() {
	int i;
	if (isEmpty())
		cout << "Queue is Empty!" << endl;
	else {
		cout << "--Print Queue--" << endl;
		bool circular = false;
		for (i = front; i != rear || !circular; i = ++i % sizeQueue, circular = true)
			cout << queue[i+1] << endl;
	}
}
#endif