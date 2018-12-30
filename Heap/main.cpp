// A C++ program to demonstrate common Binary Heap Operations
#include<iostream>
#include "Heap.h"

// Driver program to test above functions
int main() {
    Heap h(8);

    std::cout << "1) Empty Test:\n";
    h.isEmpty();
    std::cout << "\n\n";

    int initData[] = {
            8, 6, 4, 2, 5, 3
    };

    std::cout << "2) Initial Heap with (8 6 4 2 5 3):\n";

    for (int i = 0; i < 6; ++i) {
        std::cout << initData[i] << "\t";
        h.insertKey(initData[i]);
    }
    std::cout << "\n\n";

    std::cout << "3) Insert 9:\n";
    h.insertKey(9);
    h.output();
    std::cout << "\n\n";

    std::cout << "4) Insert 7:\n";
    h.insertKey(7);
    h.output();
    std::cout << "\n\n";

    std::cout << "5) Full Test:\n";
    h.isFull();
    std::cout << "\n\n";


    std::cout << "6) Delete:\n";
    h.deleteKey(8);
    h.output();
    std::cout << "\n\n";


    return 0;
}
