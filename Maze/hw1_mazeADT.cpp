#ifndef HW1_MAZEADT
#define HW1_MAZEADT

#include "hw1_maze.h" //hw1_maze ��� ������ �ҷ��´�

//Stack��ü ����
Stack::Stack() {
	top = -1; //���ÿ����� ���� ��ġ�� top�� -1�� �ʱ�ȭ��Ų��
}
//push() ����_���ÿ� �����͸� �����ϴ� �Լ�
void Stack::push(Element val) { //Element �ڷ����� val�� �Ű�������
	stack[++top] = val; //������ ����ġ�� 1 ������Ű�� ���� �����Ѵ�
}

//pop()_���ÿ��� �����͸� �����ϴ� �Լ�
Element Stack::pop() {
	return stack[top--]; //����ġ�� �����͸� ��ȯ�ϰ� �� ��ġ�� 1 ���ҽ�Ų��
}
//isEmpty()_������ ��������� ����ִ��� Ȯ���ϴ� �Լ� 
int Stack::isEmpty() {
	if (top == -1) //������ ��������� ���������
		return 1; //1 ��ȯ
	else
		return 0; //�ƴ� �� 0 ��ȯ
}

//isFUll()_������ ��������� �� ���ִ��� Ȯ���ϴ� �Լ�
int Stack::isFull() {
	if (top >= Stack_size) //������ ����Ű�� �ִ� ��ġ�� ���� �迭�� ������ ���� ũ��
		return 1; //1 ��ȯ
	else
		return 0; //�ƴ� �� 0 ��ȯ
}

//display()_���ÿ� ����Ǿ��ִ� �����͸� ����ϴ� �Լ� 
void Stack::display() {
	int sp; //sp - ������ ���� ��ġ�� �����ϱ� ���� ����
	sp = top; 
	// sp ������ �����Ͽ� top�� �����ϴ� ����:
	//���ð����� �����͵��� ��½�Ű�� ���Ͽ� top��ġ�� ������Ű��
	//������ Ư¡�� LIFO�� ħ�ص� �� �ֱ� ����
	while (sp != -1) { //���ÿ� ����Ǿ��ִ� ��� ��, ���� ���� ����Ѵ�
		cout << "(" << stack[sp].row << ",  " << stack[sp].col << ")    " << stack[sp].dir << endl;
		sp--;
	}
	cout << endl;
}

#endif