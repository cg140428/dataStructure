#ifndef MAIN_CPP
#define MAIN_CPP
#include "graph.h"

using namespace std;

#define VERTEX 6

int main(void) {

	graph graph1(VERTEX + 1);

	int wg[6][6] = {
	{ 100, 6,   1,   5,   100, 100 },
	{ 6,   100, 4,   100, 3,   100 },
	{ 1,   4,   100, 5,   6,   5 },
	{ 5,   100, 5,   100, 100, 2 },
	{ 100, 3,   6,   100, 100, 6 },
	{ 100, 100, 5,   2,   6,   100 },
	};


	cout << "***** Weighted Graph *****" << endl;
	for (int i = 0; i < VERTEX + 1; i++) {
		for (int j = 0; j < VERTEX + 1; j++) {
			if (i == 0 && j == 0)
				cout << "   ";
			else if (i == 0 && j != 0)
				cout << "v" << j << "  ";
			else if (i != 0 && j == 0)
				cout << "v" << i << "  ";
			else
				cout << wg[i - 1][j - 1] << "  ";
		}
		cout << endl;
	}

	cout << "2) Minimal Spanning Tree (v1 에서 시작)" << endl;

	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 6; ++j) {
			if (wg[i][j] != 100) {
				graph1.addEdge(i + 1, j + 1, wg[i][j]);
			}
		}
	}

	graph1.primmst(3);

	return 0;
}
#endif