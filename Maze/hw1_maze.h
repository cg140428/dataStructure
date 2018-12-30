#ifndef HW1_MAZE
#define HW1_MAZE
#include <iostream>

using namespace std;

const int Stack_size = 200; //스택의 사이즈를 지정해준다

//struct offset _ 좌표의 이동거리을 나타내는 구조체
//(-1 <= vert, horiz <= 1)
typedef struct {
	int vert; //vert - 이동 좌표의 수직관계를 나타낸다
	int horiz; //horiz - 이동 좌표의 수평관계를 나타낸다
} Offset;

//struct element _ 현, 이동할 좌표 위치를 나타내는 구조체
typedef struct {
	int row; //row - 행을 나타낸다
	int col; //col - 열을 나타낸다
	int dir; //dir - 8방향 중 한 곳을 나타낸다 
} Element;

//class Stack _ 스택 클래스 선언
class Stack {
private:
	Element stack[Stack_size]; //스택에 사용되는 배열
	int top; //top - 현재 스택이 가리키는 위치

public:
	Stack(); //스택 객체
	void push(Element val); //스택에 데이터를 저장하는 함수
	Element pop(); //스택에서 데이터를 삭제하는 함수
	int isEmpty(); //스택의 저장공간이 비어있는지 확인하는 함수 
	int isFull(); //스택의 저장공간이 꽉 차있는지 확인하는 함수
	void display(); //스택에 저장되어있는 데이터를 출력하는 함수 
};

#endif