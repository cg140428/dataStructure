#ifndef MAIN_CPP
#define MAIN_CPP
#include "hashing.h"

int main(void) {
	HashTable h1;
	char menu;

	do {
		cout << "Enter command (i, f, d, q): ";
		cin >> menu;
		int inkey;
		

		switch (menu) {
		case 'i':
			cout << "Enter a data: ";
			cin >> inkey;
			h1.insertKey(inkey);
			break;
		case 'f':
			cout << "Enter a data: ";
			cin >> inkey;
			h1.findKey(inkey);
			break;
		case 'd':
			cout << "Enter a data: ";
			cin >> inkey;
			h1.deleteKey(inkey);
			break;
		case 'q':
			return 0;
		default:
			cout << "Bad Command" << endl;
		}

		h1.printTable();
	} while (true);

	return 0;
}
#endif // !MAIN_CPP
