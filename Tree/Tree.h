#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <cstdio>

using namespace std;

class Node {
private:
	char data;
	int prio;
	Node* left;
	Node* right;
public:
	Node(char data);
	friend class Tree;
};

class Tree {
private:
	Node * root;
	char prec[4][2] = { { '*', 2 },
	{ '/', 2 },
	{ '+', 1 },
	{ '-', 1 },
	};
public:
	Tree();
	void bulidTree(char modify[]);
	void Operand(Node* temp);
	void Operator(Node* temp);
	int evalTree(Node* p);
	void inOrder(Node* p);
	void postOrder(Node* p);
	void preOrder(Node* p);
	Node* getRoot();
	friend class Node;
};
#endif