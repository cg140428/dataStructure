#ifndef MAIN_CPP
#define MAIN_CPP

#include "heap.h"

int main(void) {
	Heap h1;

	cout << "Menu (1.Insert, 2.Delete, 3.Empty-test, 4.Full-test, 5.Level-test 6. Print )" << endl;
	cout << endl;

	cout << "1) Empty test:  ";
	h1.heapEmptyTest();
	cout << endl;

	cout << "2) Create Heap with (8 6 4 2 5 3):  ";
	int initArray[8] = { 8, 6, 4, 2, 5, 3 };
	h1.buildHeap(initArray);
	h1.display();
	cout << endl;

	cout << "3) Insert 9:  ";
	h1.maxHeap_insert(9);
	h1.display();
	cout << endl;

	cout << "4) Insert 7:  ";
	h1.maxHeap_insert(7);
	h1.display();
	cout << endl;

	cout << "5) Full test:  ";
	h1.heapFullTest();
	cout << endl;

	cout << "6) Level Test:  ";
	cout << "Heap Level " << h1.heapLevel() << endl;
	cout << endl;

	cout << "7) Delete:  ";
	h1.maxHeap_del();
	h1.display();
	cout << endl;

	return 0;
}
#endif