#ifndef BST_H
#define BST_H
#include <iostream>
#include <cstdio>

using namespace std;

// Node를 나타내는 클래스 - 데이터 값과 왼쪽 서브트리, 오른쪽 서브트리를 가리키는 포인터로 구성
class Node {
private:
	int data; // 데이터 값
	Node* left; // 왼쪽 서브트리 가리키는 포인터
	Node* right; //오른쪽 서브트리 가리키는 포인터
public:
	Node(int data); //Node 생성자
	friend class Tree; //Tree 클래스에 접근가능
};

//이진 탐색 트리를 구성하는 클래스
class Tree {
private:
	Node * root; // root를 가리키는 Node형 포인터
public:
	Tree(); //Tree 생성자
	Node* insert(Node* p, int data); //데이터 삽입 함수
	Node* search(Node* p, int data); //데이터 탐색하는 함수
	Node* del(Node* p, int data); // 데이터 삭제 함수
	Node* find_min(Node* p); // 가장 마지막 왼쪽 서브트리를 탐색하는 함수
	void printBTS(); // 이진 탐색 트리 출력 실행합수 - 사용자 용
	void display(Node* p, int level); // 이진 탐색 트리 출력 실행 함수 - 실체
	Node* getRoot(); // root를 가리키는 포인터를 반환하는 함수
	friend class Node; //Node클래스에 접근 가능
};
#endif