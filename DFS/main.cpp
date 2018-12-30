#include "DFS.h"

int main(void) {
	Graph g1;

	//1)
	g1.displayData();

	//2) 0부터 시작
	g1.dfs(0);
	return 0;
}