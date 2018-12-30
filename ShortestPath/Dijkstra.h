#ifndef DIJKSTRA_H
#define KIJKSTRA_H
#include <iostream>

using namespace std;

const int MAX_VERTEX = 6;

const int adjacencyMatrix[MAX_VERTEX][MAX_VERTEX] = {
	100, 20, 15, 100, 100, 100,
	100, 100, 100, 100, 10, 30,
	100, 4, 100, 100, 100, 10,
	100, 100, 100, 100, 100, 100,
	100, 100, 100, 15, 100, 100,
	100, 100, 100, 4, 10, 100
};

class Edge {
private:
	//int ff; 
	int weight; 
	//int ll; 
public:
	Edge() {};
	Edge(int weight);
	friend class Dijkstra;
};

class Dijkstra {
private:
	Edge cost[MAX_VERTEX][MAX_VERTEX];
	int distance[MAX_VERTEX];
	bool visited[MAX_VERTEX];
public:
	Dijkstra();
	void shortestPath(int v);
	int choose();
	void printDistance();
	void printCostMatrix();
};
#endif