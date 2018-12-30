#ifndef LAB4_H
#define LAB4_H
#include <iostream>

using namespace std;

const int sizeQueue = 5;

class Queue {
private:
	int front, rear;
	bool flag;
	int queue[sizeQueue];
public:
	Queue();
//	virtual ~Queue();
	void enQueue(int val);
	int deQueue();
	bool isFull();
	bool isEmpty();
	void print();
};
#endif