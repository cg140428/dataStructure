#ifndef PRIM_H
#define PRIM_H
#include <iostream>

using namespace std;
const int MAX_NODE = 6;
const int adjacencyMatrix[MAX_NODE][MAX_NODE] = {
	100, 6, 1, 5, 100, 100,
	6, 100, 4, 100, 3, 100,
	1, 4, 100, 5, 6, 5,
	5, 100, 5, 100, 100, 2,
	100, 3, 6, 100, 100, 6,
	100, 100, 5, 2, 6, 100
};

class Node {
private:
	int ff;
	int weight;
	int ll;
public:
	Node(int ff, int weight, int ll); 
	friend class primMST;
};

class primMST {
private:
	//bool visited[8];
	Node* cost[MAX_NODE][MAX_NODE];
	Node* lowerCost[MAX_NODE];
	Node* MST[MAX_NODE - 1];
	bool visited[MAX_NODE];
	int weight;
public:
	primMST(); 
	void printWeightedGraph(); //Ãâ·Â
	void prim(int vertex); 
	void prim2(int vertex);
	friend class Node;
};
#endif // !PRIM_H
