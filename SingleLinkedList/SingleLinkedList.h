#ifndef SingleLINKEDLIST_H
#define SingleLINKEDLIST_H
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

//struct Student - �� �л��� ������ ������ ����ü
//				 - insert�Լ��� ���� ������ �� ���ȴ�
struct Student {
	char name;
	int ID;
	char major[3];
	char grade;
};

//class Node - �� �л��� ������ Node �����͸� ������ Ŭ����
class Node {
public:
	friend class SingleLinkedList; // SingleLinkedList class �� ���� ����
private:
	char name;
	int ID;
	char major[3];
	char grade;
	Node* next;
public:
	Node(Student newStudent); //������
};

class SingleLinkedList{
public:
	friend class Node; // Node class�� ���� ����
private:
	Node* head;
public:
	//SingleLinkedList class�� ��� �Լ���
	SingleLinkedList(); //������
	bool isEmpty(); //���� ����Ʈ�� ������� �˻��ϴ� �Լ�
	void insert(Student newStudent); // ���� ����Ʈ�� ��带 �̸� ������������ �����ϴ� �Լ�
	void display(); //���� ����Ʈ�� ��� �����͸� ���������� ����ϴ� �Լ�
	void displayGradeA(); //Ư�� ������ �����͸� ���� Node�� ����ϴ� �Լ�
	void displayMajorCS(); // Ư�� ������ �����͸� ���� Node�� ����ϴ� �Լ�
};
#endif
