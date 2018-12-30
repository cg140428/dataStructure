#ifndef ADT_CPP
#define ADT_CPP
#include "Tree.h"

Node::Node(char data) 
	:prio(4), left(NULL), right(NULL){
	this->data = data;
}

Tree::Tree() {
	root = NULL;
}

void Tree::bulidTree(char modify[]) {
	int index = 0;
	while (modify[index] != NULL) {
		char temp_data = modify[index];
		Node* temp = new Node(temp_data);

		for (int i = 0; i < 4; i++) {
			if (temp->data == prec[i][0]) {
				temp->prio = prec[i][1];
				break;
			}
		}
		if (temp->prio == 4)
			Operand(temp);
		else
			Operator(temp);
		index++;
	}
}

void Tree::Operand(Node* temp) {
	Node* p;
	if (root == NULL) {
		root = temp;
		return;
	}
	p = root;
	while (p->right != NULL) {
		p = p->right;
	}
	p->right = temp;
}

void Tree::Operator(Node* temp) {
	if (root->prio >= temp->prio) {
		temp->left = root;
		root = temp;
	}
	else {
		temp->left = root->right;
		root->right = temp;
	}
}

int Tree::evalTree(Node* p) {
	int value;
	int leftVal, rightVal;

	if (p != NULL) {
		if (p->prio == 4){
			value = p->data - '0'; // 
		}
		else {
			leftVal = Tree::evalTree(p->left);
			rightVal = Tree::evalTree(p->right);
			switch (p->data) {
			case'+': value = leftVal + rightVal; break;
			case'-': value = leftVal - rightVal; break;
			case'*': value = leftVal * rightVal; break;
			case'/': value = leftVal / rightVal; break;
			}
		}
	}
	else
		cout << "Empty tree" << endl;
	return value;
}

void Tree::inOrder(Node* p) {
	if (p != NULL) {
		Tree::inOrder(p->left);
		cout << p->data;
		Tree::inOrder(p->right);
	}
	return;
}

void Tree::postOrder(Node* p) {
	if (p != NULL) {
		Tree::postOrder(p->left);
		Tree::postOrder(p->right);
		cout << p->data;
	}
	return;
}

void Tree::preOrder(Node* p) {
	if (p != NULL) {
		cout << p->data;
		Tree::preOrder(p->left);
		Tree::preOrder(p->right);
	}
	return;
}

/*
				
					   -
                +			*
			8		9   2		3


*/




Node* Tree::getRoot() {
	return root;
}
#endif