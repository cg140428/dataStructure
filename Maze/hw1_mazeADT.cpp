#ifndef HW1_MAZEADT
#define HW1_MAZEADT

#include "hw1_maze.h" //hw1_maze 헤더 파일을 불러온다

//Stack객체 선언
Stack::Stack() {
	top = -1; //스택에서의 현재 위치인 top을 -1롤 초기화시킨다
}
//push() 선언_스택에 데이터를 저장하는 함수
void Stack::push(Element val) { //Element 자료형의 val를 매개변수로
	stack[++top] = val; //스택의 현위치를 1 증가시키고 값을 저장한다
}

//pop()_스택에서 데이터를 삭제하는 함수
Element Stack::pop() {
	return stack[top--]; //현위치의 데이터를 반환하고 그 위치를 1 감소시킨다
}
//isEmpty()_스택의 저장공간이 비어있는지 확인하는 함수 
int Stack::isEmpty() {
	if (top == -1) //스택의 저장공간이 비어있으면
		return 1; //1 반환
	else
		return 0; //아닐 시 0 반환
}

//isFUll()_스택의 저장공간이 꽉 차있는지 확인하는 함수
int Stack::isFull() {
	if (top >= Stack_size) //스택의 가리키고 있는 위치가 스택 배열의 사이즈 보다 크면
		return 1; //1 반환
	else
		return 0; //아닐 시 0 반환
}

//display()_스택에 저장되어있는 데이터를 출력하는 함수 
void Stack::display() {
	int sp; //sp - 스택의 현재 위치를 복사하기 위한 변수
	sp = top; 
	// sp 변수를 생성하여 top을 복사하는 이유:
	//스택공간의 데이터들을 출력시키기 위하여 top위치를 변형시키면
	//스택의 특징인 LIFO가 침해될 수 있기 때문
	while (sp != -1) { //스택에 저장되어있는 모든 행, 열의 값을 출력한다
		cout << "(" << stack[sp].row << ",  " << stack[sp].col << ")    " << stack[sp].dir << endl;
		sp--;
	}
	cout << endl;
}

#endif