#ifndef MAIN_CPP
#define MAIN_CPP
#include "prim.h"

int main(void) {
	primMST p1;
	p1.printWeightedGraph();
	p1.prim(1);
	p1.prim2(1);
	return 0;
}
#endif // !MAIN_CPP
