#ifndef ADT_CPP
#define ADT_CPP
#include "hashing.h"

Hash::Hash() {
	key = 0;
	empty = 1;
}

HashTable::HashTable() {

}

int HashTable::HASH(int inkey) {
	int M = 7;
	return inkey % M;
}

bool HashTable::findKey(int inkey) {
	int index = HASH(inkey);
	while (hashTable[index].empty != 1) {
		if (hashTable[index].key == inkey) {
			cout << "Found " << inkey << " -> ";
			return true;
		}
		else {

			index++;
			index %= MAX_SIZE;
		}
	}
	cout << "Not found" << " -> ";
	return false;
}

void HashTable::insertKey(int inkey) {
	int index = HASH(inkey);
	if (hashTable[index].empty == 1) {
		hashTable[index].key = inkey;
		hashTable[index].empty = 0;
	}
	else {
		while (hashTable[index].empty != 1) {
			index++;
			index %= MAX_SIZE;
		}
		hashTable[index].key = inkey;
		hashTable[index].empty = 0;
	}
}
	
void HashTable::deleteKey(int inkey) {
	int index = HASH(inkey);
	while (hashTable[index].empty != 1) {
		if (hashTable[index].key == inkey) {
			hashTable[index].empty = 1;
		}
		else {
			index++;
			index %= MAX_SIZE;
		}
	}
	cout << "can't find" << endl;
}

void HashTable::printTable() {
	cout << "( ";
	for (int i = 0; i < MAX_SIZE; i++) {
		if (hashTable[i].empty == 1)
			cout << "_";
		else
			cout << hashTable[i].key;

		if (i < MAX_SIZE - 1) {
			cout << " , ";
		}
	}
	cout << " )";
	cout << endl;
}
#endif