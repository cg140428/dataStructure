#ifndef ADT_CPP
#define ADT_CPP

#include "heap.h"

Heap::Heap() {
	n = 0;
}
void Heap::buildHeap(int arr[]) {
	int i = 0;
	while (arr[i] != NULL) {
		n++;
		heap[i + 1] = arr[i];
		i++;
	}
}

bool Heap::heapFull() {
	if (n == MAX_ELEMENTS - 1)
		return true;
	else
		return false;
}

bool Heap::heapEmpty() {
	if (n == 0)
		return true;
	else
		return false;
}

void Heap::heapFullTest() {
	if (Heap::heapFull())
		cout << "Heap is Full" << endl;
}
void Heap::heapEmptyTest() {
	if (Heap::heapEmpty())
		cout << "Heap is Empty" << endl;
}

void Heap::maxHeap_insert(int data) {
	if (Heap::heapFull())
		cout << "Heap is full" << endl;
	else {
		int i;
		i = ++n;

		while ((i != 1) && (data > heap[i / 2])) {
			heap[i] = heap[i / 2];
			i /= 2;
		}
		heap[i] = data;
	}
}

int Heap::maxHeap_del() {
	int parent, child;
	int item, temp;

	item = heap[1];
	temp = heap[n--];
	parent = 1;
	child = 2;

	while (child <= n) {
		if ((child < n) && (heap[child] < heap[child + 1]))
			child++;
		if (temp >= heap[child])
			break;
		heap[parent] = heap[child];
		parent = child;
		child = child * 2;
	}
	heap[parent] = temp;
	return item;
}

int Heap::heapLevel() {
	int i = 1;
	int level = 0;
	while (i <= n) {
		i *= 2;
		level++;
	}
	
	return level;
}

//void minHeap_insert(int data);
//void minHeap_del();

void Heap::display() {
	int i = n;
	for (i = 0; i < n; i++) {
		cout << heap[i + 1] << " ";
	}
	cout << endl;
}
#endif