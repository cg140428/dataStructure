#ifndef GRAPH_H
#define GRAPH_H

#include "linkedQueue.h"
#include <iostream>


struct adjListNode {
	int dest;
	int weight;
	bool visited;
	struct adjListNode *next;

	struct adjListNode *createAdjListNode(int dest, int weight);
};

struct adjList {
	struct adjListNode *head;
};

class graph {
private:
	int V;
	struct adjList *array;
	bool *visited;

public:
	explicit graph(int V);

	void addEdge(int, int, int);

	void primmst(int);
};

#endif
