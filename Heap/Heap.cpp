//
// Created by Gihyeon Yang on 2018. 5. 16..
//

#include "Heap.h"
#include "iostream"

Heap::Heap(int cap) {
    heap_size = 0;
    capacity = cap;
    harr = new int[cap];
    for (int i = 0; i < cap; i++) {
        harr[i] = 0;
    }
}

// Inserts a new key 'k'
void Heap::insertKey(int k) {
    int i = ++(this->heap_size);

    while ((i != 1) && (k > this->harr[i / 2])) {
        this->harr[i] = this->harr[i / 2];
        i /= 2;
    }

    this->harr[i] = k;
}


// This function deletes key at index i. It first reduced value to minus
// infinite, then calls extractMin()
void Heap::deleteKey(int i) {
    int parent, child;
    int item, temp;

    item = this->harr[1];
    temp = this->harr[(this->heap_size)--];
    parent = 1;
    child = 2;

    while (child <= this->heap_size) {
        if ((child < this->heap_size) && (this->harr[child] < this->harr[child + 1])) {
            child++;
        }
        if (temp >= this->harr[child]) {
            break;
        }
        this->harr[parent] = this->harr[child];
        parent = child;
        child *= 2;
    }

    this->harr[parent] = temp;
}

void Heap::output() {
    for (int i = 0; i < this->capacity; i++) {
        if (harr[i] == 0) { continue; }
        cout << harr[i] << "\t";
    }

    cout << endl;
}

bool Heap::isFull() {
    bool result = this->heap_size == this->capacity;
    std::cout << ((result) ? "Heap is Full" : "Heap is not Full");
    return result;
}

bool Heap::isEmpty() {
    bool result = this->heap_size == 0;
    std::cout << ((result) ? "Heap is Empty" : "Heap is not Empty");
    return result;
}


