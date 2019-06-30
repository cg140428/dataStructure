#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

class Node {
private:
	int data;
	Node *next;

	Node(int data) {
		this->data = data;
		this->next = nullptr;
	}

	friend class linkedQueue;
};

class linkedQueue {
private:
	Node * front;
	Node *rear;

public:
	linkedQueue() {
		this->front = nullptr;
		this->rear = nullptr;
	}

	void createQueue();

	void enqueue(int);

	int dequeue();

	bool isEmpty();

};


#endif
