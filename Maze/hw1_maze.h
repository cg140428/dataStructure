#ifndef HW1_MAZE
#define HW1_MAZE
#include <iostream>

using namespace std;

const int Stack_size = 200; //������ ����� �������ش�

//struct offset _ ��ǥ�� �̵��Ÿ��� ��Ÿ���� ����ü
//(-1 <= vert, horiz <= 1)
typedef struct {
	int vert; //vert - �̵� ��ǥ�� �������踦 ��Ÿ����
	int horiz; //horiz - �̵� ��ǥ�� ������踦 ��Ÿ����
} Offset;

//struct element _ ��, �̵��� ��ǥ ��ġ�� ��Ÿ���� ����ü
typedef struct {
	int row; //row - ���� ��Ÿ����
	int col; //col - ���� ��Ÿ����
	int dir; //dir - 8���� �� �� ���� ��Ÿ���� 
} Element;

//class Stack _ ���� Ŭ���� ����
class Stack {
private:
	Element stack[Stack_size]; //���ÿ� ���Ǵ� �迭
	int top; //top - ���� ������ ����Ű�� ��ġ

public:
	Stack(); //���� ��ü
	void push(Element val); //���ÿ� �����͸� �����ϴ� �Լ�
	Element pop(); //���ÿ��� �����͸� �����ϴ� �Լ�
	int isEmpty(); //������ ��������� ����ִ��� Ȯ���ϴ� �Լ� 
	int isFull(); //������ ��������� �� ���ִ��� Ȯ���ϴ� �Լ�
	void display(); //���ÿ� ����Ǿ��ִ� �����͸� ����ϴ� �Լ� 
};

#endif