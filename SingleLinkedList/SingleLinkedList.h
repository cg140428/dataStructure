#ifndef SingleLINKEDLIST_H
#define SingleLINKEDLIST_H
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

//struct Student - 한 학생의 정보를 저장한 구조체
//				 - insert함수로 값을 전달할 때 사용된다
struct Student {
	char name;
	int ID;
	char major[3];
	char grade;
};

//class Node - 한 학생의 정보와 Node 포인터를 저장한 클래스
class Node {
public:
	friend class SingleLinkedList; // SingleLinkedList class 에 접근 가능
private:
	char name;
	int ID;
	char major[3];
	char grade;
	Node* next;
public:
	Node(Student newStudent); //생성자
};

class SingleLinkedList{
public:
	friend class Node; // Node class에 접근 가능
private:
	Node* head;
public:
	//SingleLinkedList class의 멤버 함수들
	SingleLinkedList(); //생성자
	bool isEmpty(); //연결 리스트가 비었는지 검사하는 함수
	void insert(Student newStudent); // 연결 리스트에 노드를 이름 오름차순으로 삽입하는 함수
	void display(); //연결 리스트의 노드 데이터를 순차적으로 출력하는 함수
	void displayGradeA(); //특정 성적의 데이터를 가진 Node만 출력하는 함수
	void displayMajorCS(); // 특정 전공의 데이터를 가진 Node만 출력하는 함수
};
#endif
