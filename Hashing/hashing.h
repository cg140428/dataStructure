#ifndef HASHING_H
#define HASHING_H
#include <iostream>
using namespace std;

const int MAX_SIZE = 7;

class Hash {
private:
	int key;
	int empty;
public:
	Hash();
	friend class HashTable;
};

class HashTable {
private:
	Hash hashTable[MAX_SIZE];
public:
	HashTable();
	int HASH(int inkey);
	bool findKey(int inkey);
	void insertKey(int inkey);
	void deleteKey(int inkey);
	void printTable();
};

#endif // !HASHING_H
