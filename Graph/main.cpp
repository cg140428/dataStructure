#include <iostream>
#include "graph.h"

#define VERTEX 6

int main() {

	graph graph1(VERTEX + 1);

	int wg[6][6] = {
		{ 100, 6,   1,   5,   100, 100 },
	{ 6,   100, 4,   100, 3,   100 },
	{ 1,   4,   100, 5,   6,   5 },
	{ 5,   100, 5,   100, 100, 2 },
	{ 100, 3,   6,   100, 100, 6 },
	{ 100, 100, 5,   2,   6,   100 },
	};


	std::cout << ") Weighted Graph 를 다음과 같이 출력할것" << std::endl;

	std::cout << "\t\t";
	for (int i = 0; i < VERTEX; i++) {
		std::cout << 'v' << i << "\t\t";
	}
	std::cout << std::endl;

	for (int i = 0; i < VERTEX; ++i) {
		for (int j = 0; j < VERTEX; ++j) {
			if (j == 0) {
				std::cout << 'v' << i << "\t\t";
			}
			std::cout << wg[i][j] << "\t\t";
		}
		std::cout << std::endl;
	}

	std::cout << "\n2) Minimal Spanning Tree (v1 에서 시작하면)" << std::endl;

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