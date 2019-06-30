#ifndef ADT_CPP
#define ADT_CPP
#include "SingleLinkedList.h"

//Node ������ - ���� ���� ����ü�� ������� ���� 
//			  - Node�� �� ������� ���� ����
Node::Node(Student newStudent) {
	//����ü�� �޾ƿ� �л� �̸�(newStudent.name)�� Node�������� �л��̸�(name)�� ����
	name = newStudent.name; 
	//����ü�� �޾ƿ� �л� �й�(newStudent.ID)�� Node�������� �л��й�(ID)�� ����
	ID = newStudent.ID; 
	//����ü�� �޾ƿ� �л� ����(newStudent.major)�� Node�������� �л�����(major)�� ����
	strcpy(major, newStudent.major); 
	//����ü�� �޾ƿ� �л� ����(newStudent.grade)�� Node�������� �л�����(grade)�� ����
	grade = newStudent.grade;
	//Node�������� next�����Ϳ� NULL�� �ʱ�ȭ
	next = NULL;
}

//SingleLinkedList ������ - head �����͸� �ʱ�ȭ 
SingleLinkedList::SingleLinkedList(){
	//SIngleLinkedList������ head �����Ϳ� NULL�� �ʱ�ȭ
	head = NULL;
}

//isEmpty() - ���� ����Ʈ�� ������� �˻��ϴ� �Լ�
bool SingleLinkedList::isEmpty() {
	//list�� ����� ���
	if (head == NULL)
		return true; //��
	else
		return false; //����
}

//insert() - ���� ����Ʈ�� ��带 ������������ �����ϴ� �Լ�
void SingleLinkedList::insert(Student newStudent) {
	//�߰��� Node�� �ּҰ��� temp �����Ϳ� �Ҵ�
	Node* temp = new Node(newStudent);
	//Node�� ����Ű�� pre, now ������ ����
	Node* pre;
	Node* now;

	//list�� ����� ���
	if (isEmpty()) {
		//head �����Ϳ� �߰��� Node�� �ּҰ��� ����
		head = temp;
	}
	//�� Node�� ù��° Node �տ� ���ĵ� ���
	else if (temp->name < head->name) {
		//�߰��� Node�� next �����Ͱ� ù��° Node�� ����Ű�� ��
		temp->next = head;
		//head�����Ͱ� ���ο� Node�� ����Ű�� ��
		head = temp;
	}
	else {
		//now �����Ͱ� ù�� ° Node�� ����Ű�� ��
		now = head;
		//now �����Ͱ� NULL���� �ƴϰų�, now�� ����Ű�� Node�� name ����
		//�� Node�� namer �� ���� ������ �ݺ����� ����
		while (now != NULL && now->name < temp->name) {
			//now ���� ������ pre�� now�� ����
			pre = now;
			//now�� ���� Node�� ����Ű�� ��
			now = now->next;
		}
		//�� Node�� �߰��� ���ĵ� ���
		if (now != NULL) {
			//�߰��� Node�� next�����Ϳ� now�� ���� ����
			temp->next = now;
			//pre �����Ͱ� ����Ű�� Node�� next�����Ϳ� �� Node�� �ּҰ��� ����
			pre->next = temp;
		}
		//�� Node�� ���� �� �ʿ� ���ĵ� ���
		else {
			//pre�����Ͱ� ����Ű�� Node�� next�����Ϳ� �� Node�� �ּҰ��� ����
			pre->next = temp;
		}
	}
}

//display() - ���� ����Ʈ�� ��� �����͸� ���������� ����ϴ� �Լ�
void SingleLinkedList::display() {
	//���� Node�� ����Ű�� ������ p�� ����
	Node* p;
	//������ p�� ù�� ° Node�� ����Ű�� ��
	p = head;

	//list�� ������� ���� ���
	if (!isEmpty()) {
		//p �����Ͱ� NULL�� �ƴҰ�� �ݺ��� ����
		while (p) {
			//p�� ����Ű�� �ִ� Node�� �л� ������ ���
			cout << p->name << " " << p->ID << " " << p->major << " " << p->grade << endl;
			//p�� ���� Node�� ����Ű�� ��
			p = p->next;
		}
	}
	//list�� ������� ���
	else {
		//list�� ��������� �˸��� ��¹�
		cout << "List is empty!" << endl;
	}
}

//displayGradeA() - Ư�� ������ �����͸� ���� Node�� ����ϴ� �Լ�
void SingleLinkedList::displayGradeA() {
	//���� Node�� ����Ű�� ������ p�� ����
	Node* p;

	//list�� ������� ���� ���
	if (!isEmpty()) {
		//������ p�� ù�� ° Node�� ����Ű�� ��
		p = head;
		//������ p�� ���� NULL�� �ƴ� �� �ݺ��� ����
		while (p != NULL) {
			//p�� ����Ű�� Node�� grade ���� "A"�� ���� ���
			if (p->grade == 'A') {
				//p�� ����Ű�� �ִ� Node�� �л� ������ ���
				cout << p->name << " " << p->ID << " " << p->major << " " << p->grade << endl;
			}
			//p�� ���� Node�� ����Ű�� ��
			p = p->next;
		}
	}
	//list�� ������� ���
	else {
		//list�� ��������� �˸��� ��¹�
		cout << "List is empty!" << endl;
	}
}

//displayMajorCS() - Ư�� ������ �����͸� ���� Node�� ����ϴ� �Լ�
void SingleLinkedList::displayMajorCS() {
	//���� Node�� ����Ű�� ������ p�� ����
	Node* p;

	//list�� ������� ���� ���
	if (!isEmpty()) {
		//������ p�� ù�� ° Node�� ����Ű�� ��
		p = head;
		//������ p�� ���� NULL�� �ƴ� �� �ݺ��� ����
		while (p != NULL) {
			//p�� ����Ű�� Node�� major ���� "CS"�� ���� ���
			if(!strcmp(p->major,"CS")) {
				//p�� ����Ű�� �ִ� Node�� �л� ������ ���
				cout << p->name << " " << p->ID << " " << p->major << " " << p->grade << endl;
			}
			//p�� ���� Node�� ����Ű�� ��
			p = p->next;
		}
	}
	//list�� ������� ���
	else {
		//list�� ��������� �˸��� ��¹�
		cout << "List is empty!" << endl;
	}
}
#endif