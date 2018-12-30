#ifndef MAIN_CPP
#define MAIN_CPP
#include"Dijkstra.h"

int main(void) {
	Dijkstra d1;

	d1.printCostMatrix();
	d1.shortestPath(5);

	return 0;
}
#endif // !MAIN_CPP
