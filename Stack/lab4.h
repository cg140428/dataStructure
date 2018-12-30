#ifndef LAB4_H
#define LAB4_H

#include <iostream>

using namespace std;

const int Stack_size = 32;

class Stack {
private:
	int stack[Stack_size];
	int top;

public:
	Stack();
	void push(int val);
	char pop();
	int isEmpty();
	int isFull();
	void display();
};

#endif