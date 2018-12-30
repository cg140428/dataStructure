#include "lab4.h"

Stack::Stack() {
	top = -1;
}

void Stack::push(int val) {
	if (isFull())
		cout << "Stack is Full!" << endl;
	else
		stack[++top] = val;
}

char Stack::pop() {
	if (isEmpty)
		cout << "Stack is Empty!" << endl;
	else
		return stack[top--];
}

int Stack::isEmpty() {
	if (top == -1)
		return 1;
	else
		return 0;
}

int Stack::isFull() {
	if (top >= Stack_size)
		return 1;
	else
		return 0;
}

void Stack::display() {
	int sp;
	sp = top;
	while (sp != -1) {
		cout << stack[sp--];
	}
	cout << endl;
}