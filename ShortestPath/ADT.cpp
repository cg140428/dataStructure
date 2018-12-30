#ifndef ADT_CPP
#define ADT_CPP
#include "Dijkstra.h"

Edge::Edge(int weight) {
	//this.ff = ff;
	this->weight = weight;
	//this.ll = ll;
}

Dijkstra::Dijkstra() {
	//cost 초기화
	for (int i = 0; i < MAX_VERTEX; i++) {
		for (int j = 0; j < MAX_VERTEX; j++) {
			//cost[i][j].ff = i;
			cost[i][j].weight = adjacencyMatrix[i][j];
			//cost[i][j].ll = j;
		}
	}
	//distance, visited 초기화
	for (int i = 0; i < MAX_VERTEX; i++) {
		distance[i] = 0;
		visited[i] = false;
	}
}

void Dijkstra::shortestPath(int v) {
	int u;
	for (int i = 0; i < MAX_VERTEX; i++) {
		distance[i] = cost[v][i].weight;
	}
	visited[v] = true;
	distance[v] = 0;
	for (int i = 0; i < MAX_VERTEX - 1; i++) {
		u = choose();
		visited[u] = true;
		cout << "Dist: ";
		Dijkstra::printDistance();
		cout << "(Selected Node: " << u << " )" << endl;
		for (int j = 0; j < MAX_VERTEX; j++) {
			if (visited[j] == false) {
				if (distance[u] + cost[u][j].weight < distance[j])
					distance[j] = distance[u] + cost[u][j].weight;
			}
		}
		
	}
}

int Dijkstra::choose() {
	int min = 1000;
	int minVertex = -1;
	for (int i = 0; i < MAX_VERTEX; i++) {
		if (distance[i] < min && !visited[i]) {
			min = distance[i];
			minVertex = i;
		}
	}
	return minVertex;
}

void Dijkstra::printDistance() {
	for (int i = 0; i < MAX_VERTEX; i++) {
		cout << distance[i] << "  ";
	}
}

void Dijkstra::printCostMatrix() {
	cout << "---------Cost matrix---------" << endl;
	for (int i = 0; i < MAX_VERTEX + 1; i++) {
		for (int j = 0; j < MAX_VERTEX + 1; j++) {
			if (i == 0 && j == 0)
				cout << "   ";
			else {
				if (i == 0)
					cout << j - 1 << "    ";
				else if (j == 0)
					cout << i - 1 << "  ";
				else
					cout << adjacencyMatrix[i - 1][j - 1] << "  ";
			}
		}
		cout << endl;
	}
	cout << endl;
}

#endif
