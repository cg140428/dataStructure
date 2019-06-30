#ifndef GRAPH_CPP
#define GRAPH_CPP
#include "graph.h"

struct adjListNode *adjListNode::createAdjListNode(int dest, int weight) {
	this->dest = dest;
	this->weight = weight;
	this->next = nullptr;
	this->visited = false;
	return this;
}

graph::graph(int V) {
	this->V = V;
	this->array = new adjList[V]();
	this->visited = new bool[V]();

	for (int i = 0; i < V; ++i)
		this->array[i].head = nullptr;
}

void graph::addEdge(int src, int dest, int weight) {
	struct adjListNode *newNode = (new adjListNode())->createAdjListNode(dest, weight);
	newNode->next = this->array[src].head;
	this->array[src].head = newNode;

	newNode = (new adjListNode())->createAdjListNode(src, weight);
	newNode->next = this->array[dest].head;
	this->array[dest].head = newNode;
}

// Prints shortest paths from src to all other vertices
void graph::primmst(int start) {
	this->visited = new bool[this->V]();

	// Create a queue for BFS

	linkedQueue queue;

	this->visited[start] = true;
	queue.enqueue(start);

	int t = start;
	while (!queue.isEmpty()) {
		start = queue.dequeue();
		int weight = this->array[start].head->weight;

		std::cout << t << " " << start << "\t->\t";
		t = start;
		int u = -1;
		for (adjListNode *p = this->array[start].head; p; p = p->next) {
			if (!this->visited[p->dest] && weight >= p->weight) {
				weight = p->weight;
				u = p->dest;
			}
		}

		if (u != -1) {
			this->visited[u] = true;
			queue.enqueue(u);
		}
	}

}
#endif