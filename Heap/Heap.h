//
// Created by Gihyeon Yang on 2018. 5. 16..
//

#ifndef UNTITLED3_HEAP_H
#define UNTITLED3_HEAP_H

#include <climits>

using namespace std;

// A class for Min Heap
class Heap {
    int *harr; // pointer to array of elements in heap
    int capacity; // maximum possible size of min heap
    int heap_size; // Current number of elements in min heap
public:
    // Constructor
    Heap(int capacity);

    // Deletes a key stored at index i
    void deleteKey(int i);

    // Inserts a new key 'k'
    void insertKey(int k);

    void output();

    bool isFull();

    bool isEmpty();

};


#endif //UNTITLED3_HEAP_H
