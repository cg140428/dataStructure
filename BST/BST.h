#ifndef BST_H
#define BST_H
#include <iostream>
#include <cstdio>

using namespace std;

// Node�� ��Ÿ���� Ŭ���� - ������ ���� ���� ����Ʈ��, ������ ����Ʈ���� ����Ű�� �����ͷ� ����
class Node {
private:
	int data; // ������ ��
	Node* left; // ���� ����Ʈ�� ����Ű�� ������
	Node* right; //������ ����Ʈ�� ����Ű�� ������
public:
	Node(int data); //Node ������
	friend class Tree; //Tree Ŭ������ ���ٰ���
};

//���� Ž�� Ʈ���� �����ϴ� Ŭ����
class Tree {
private:
	Node * root; // root�� ����Ű�� Node�� ������
public:
	Tree(); //Tree ������
	Node* insert(Node* p, int data); //������ ���� �Լ�
	Node* search(Node* p, int data); //������ Ž���ϴ� �Լ�
	Node* del(Node* p, int data); // ������ ���� �Լ�
	Node* find_min(Node* p); // ���� ������ ���� ����Ʈ���� Ž���ϴ� �Լ�
	void printBTS(); // ���� Ž�� Ʈ�� ��� �����ռ� - ����� ��
	void display(Node* p, int level); // ���� Ž�� Ʈ�� ��� ���� �Լ� - ��ü
	Node* getRoot(); // root�� ����Ű�� �����͸� ��ȯ�ϴ� �Լ�
	friend class Node; //NodeŬ������ ���� ����
};
#endif