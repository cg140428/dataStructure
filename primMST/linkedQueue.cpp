#ifndef LINKEDQUEUE_CPP
#define LINKEDQUEUE_CPP
#include "linkedQueue.h"

void linkedQueue::enqueue(int data) {
	Node *temp = new Node(data);

	if (this->front == nullptr) {
		this->front = temp;
		this->rear = temp;
	}
	else {
		this->rear->next = temp;
		this->rear = temp;
	}
}

int linkedQueue::dequeue() {
	Node *p;
	int num;

	num = this->front->data;
	p = this->front;

	if (this->front == rear) {
		this->front = nullptr;
		this->rear = nullptr;
	}
	else {
		this->front = this->front->next;
	}

	delete p;
	return num;
}

bool linkedQueue::isEmpty() {
	return this->front == nullptr;
}
#endif