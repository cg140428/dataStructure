#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <cstdio>
#define MAX_ELEMENTS 8 + 1

using namespace std;

class Heap {
private:
	int data;
	int heap[MAX_ELEMENTS];
	int n;
public:
	Heap();
	void buildHeap(int arr[]);
	bool heapFull();
	bool heapEmpty();
	void heapFullTest();
	void heapEmptyTest();
	void maxHeap_insert(int data);
	int maxHeap_del();
	int heapLevel();
	//void minHeap_insert(int data);
	//void minHeap_del();
	void display();

};
#endif