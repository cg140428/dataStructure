#include "DFS.h"

Node::Node(int data) {
	this->data = data;
	link = NULL;
}

Graph::Graph() {

	Node* p;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (adjacencyMatrix[i][j] == 1) {
				if (!vertex[i])
				{
					vertex[i] = new Node(j);
					p = vertex[i];
				}
				else
				{
					p->link = new Node(j);
					p = p->link;
				}
			}
		}
	}
}

void Graph::displayData() {
	Node* p;
	for (int i = 0; i < 6; i++) {
		cout << "V" << i << ": ";
		p = vertex[i];
		while (p != NULL) {
			cout << p->data;
			p = p->link;
			if (p != NULL)
				cout << " -> ";
		}
		cout << endl;
	}
}

void Graph::dfs(int v) {
	Node* w;
	visited[v] = 1;
	cout << "V" << v << " ";
	for (w = vertex[v]; w != NULL; w = w->link){
		if (!visited[w->data]) {
			cout << " -> ";
			dfs(w->data);
		}
	}
}
