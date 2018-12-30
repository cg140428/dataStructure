#ifndef DFS_H
#define DFS_H
#include <iostream>

using namespace std;

class Node {
private:
	int data;
	Node* link;
public:
	Node(int data);
	friend class Graph;
};

class Graph {
private:
	int visited[6] = {0,}; //이것도
	Node* vertex[6] = { 0, }; //vertex 배열크기는 봐서 바꾸기
	int adjacencyMatrix[6][6] = {
		0, 1, 1, 0, 0, 0,
		1, 0, 1, 1, 0, 0,
		1, 1, 0, 0, 0, 1, 
		0, 1, 0, 0, 1, 1,
		0, 0, 0, 1, 0, 1,
		0, 0, 1, 1, 1, 0
	};
public:
	Graph();
	void displayData();
	void dfs(int v);
	friend class Node;
};

#endif