/************************************************************************
*Name: �̴���
*Student ID: 20171661
*Program ID: HW2_SinglyLinkedList
*Description: �ܼ� ���� ����Ʈ�� ����Ͽ� �����͸� ����
			  -Ư�� ������(�л��� �̸�)�� ������������ ����Ʈ�� ����
			  -Ư�� ������(�л��� ����)�� ���� �����Ͽ� ����Ʈ���� ���
			  -���� ������ �����͸� �� ����Ʈ�� �����ϰ� 
			   Ư�� ������(�л��� ����)�� ���� �����Ͽ� ����Ʈ���� ���

*Algorithm: -data1.txt�� data2.txt ���Ͽ��� ���� �ٸ� �л� �̸�, �й�, ����, ������ ����Ǿ��ִ�.
			-����1) data1 ������ �о �л� �̸�(name)�� ���ĺ� ������������ ����Ʈ�� ���� ���
			-����Ʈ ����(insert())�� ���ÿ� �л� �̸��� ������������ �����Ѵ�.
			  -���� Node�� ����Ű�� ������ now�� ���� ���� ������ pre�� �����Ѵ�.
			  -���� now�����Ͱ� ����Ű���ִ� Node�� name �� ���� �� Node�� name ���� ũ�� (now->name < temp->data) pre�����Ϳ� now������ ���̿� �� Node�� �����Ѵ�  
			  -insert ��� 1(����Ʈ�� ����� ���): head �����Ϳ� �߰��� Node�� �ּҸ� �����Ѵ�.
			  -insert ��� 2(�� Node�� ù��° Node �տ� ���ĵ� ���): �߰��� Node�� next������ ù��° Node�� �ּҸ� �����ϰ� head�����Ͱ� ���ο� Node�� ����Ű�� �Ѵ�.
			  -insert ��� 3(�� Node�� �߰��� ���ĵ� ���): pre�����Ϳ� now������ ���̿� �� Node�� �����Ѵ� �߰��� Node�� next�����Ϳ� now�� ���� �����ϰ�, now ���� �������� pre�� ����Ű�� Node�� next�����Ϳ� �߰��� Node�� �ּҰ��� �����Ѵ�.
			  -intset ��� 4(�� Node�� ���� �� �ʿ� ���ĵ� ���): �߰��� Node�� next�����Ϳ� NULL�� �����Ѵ�. pre�����Ͱ� ����Ű�� Node�� next�����Ϳ� �� Node�� �ּҰ��� �����Ѵ�.
			-����Ʈ�� ���������� ����Ѵ�.
			  -���� Node�� ����Ű�� ������ p�� �����Ѵ�.
			  -������p�� ����Ű�� Node�� �����͵��� ����ϰ� p�� ���� Node�� ���� Node �ּҰ��� �����Ѵ�
			  -�� ������ ������ p�� NULL�� ����ų �� ���� �ݺ��Ѵ�.
			-����2) 1)���� ���� list���� Grade "A" ������ ���� ����� ���
			-list�� ���������� ����Ű�� �����͸� ����Ͽ� Node�� grade ���� "A"���� ���ϰ�, ������ ����Ѵ�
			  -���� Node�� ����Ű�� ������ p�� �����Ѵ�.
			  -������ p�� ����Ű�� Node�� grade ���� 'A'�� ������ ���Ѵ�.
			  -"A"�� ������ ���� Node�� �����͸� ����Ѵ�.
			  -"A"�� �ٸ��� ���� Node�� �Ѿ��(p = p->next)
			-����3) "data2"���ϰ� "data1"�� ���ļ� �ϳ��� ����Ʈ�� �����, �� �� CS���� �л��鸸 ���
			-�ռ� ���� list�� "data2" ������ ������ insert�Լ��� ����Ͽ� �߰������ش�.
			-list�� ���������� ����Ű�� �����͸� ����Ͽ� Node�� major ���� "CS"���� ���ϰ�, ������ ����Ѵ�
			  -���� Node�� ����Ű�� ������ p�� �����Ѵ�.
			  -������ p�� ����Ű�� Node�� major ���� "CS"�� ������ ���Ѵ�.
			  -"CS"�� ������ ���� Node�� �����͸� ����Ѵ�.
			  -"CS"�� �ٸ��� ���� ���� Node�� �Ѿ��(p = p->next)
*Variables: 
*alphabetSortList: SingleLinkedList class�� ��ü
*newStudent: Student�� ����ü
 -newStudent.name: ���Ͽ��� ���� �л� �̸�
 -newStudent.ID: ���Ͽ��� ���� �л� �й�
 -newStudent.major: ���Ͽ��� ���� �л� ����
 -newStudent.grade: ���Ͽ��� ���� �л� ����
*head: ù�� ° Node�� ����Ű�� ������
*next: ���� Node�� ����Ű�� ������
*temp: �� Node�� ����Ű�� ������
*now: ���� Node�� ����Ű�� ������
*pre: now�� ���� Node�� ����Ű�� ������

*Function:
*isEmpty(): ���� ����Ʈ�� ������� �˻��ϴ� �Լ�
*insert(Student newStudent): ���� ����Ʈ�� ��带 �̸� ������������ �����ϴ� �Լ�
*display(): ���� ����Ʈ�� ��� �����͸� ���������� ����ϴ� �Լ�
*displayGradeA(): Ư�� ������ �����͸� ���� Node�� ����ϴ� �Լ�
*displayMajorCS():  Ư�� ������ �����͸� ���� Node�� ����ϴ� �Լ�

*/

#ifndef MAIN_CPP
#define MAIN_CPP
#include "SingleLinkedList.h"

int main(void) {
	FILE* f;
	f = fopen("data1.txt", "r");

	//SingleLinkedList class�� alphabetSortList��ü ����
	SingleLinkedList alphabetSortList;
	//newStudent ����ü ����
	struct Student newStudent;

	//������ ���� �� ���� �ݺ��� ����
	while (!feof(f)) {
		//���Ͽ��� �л� �̸�, �й�, ����, ������ �޾� ����ü ��������� ����
		fscanf(f, "%c %d %s %c\n", &newStudent.name, &newStudent.ID, newStudent.major, &newStudent.grade);

		//alphabetSortList ����Ʈ�� �߰�, ���ÿ� �̸� �������� ����
		alphabetSortList.insert(newStudent);
	}
	
	cout << "���� 1)" << endl;
	//alphabetSortList ����Ʈ�� ��� ������ ������ ���
	alphabetSortList.display();

	fclose(f);

	cout << "���� 2)" << endl;
	//alphabetSortList ����Ʈ���� grade�� A�� �л��� ������ ���
	alphabetSortList.displayGradeA();

	

	FILE* f2;
	f2 = fopen("data2.txt", "r");

	while (!feof(f2)) {
		//���Ͽ��� �л� �̸�, �й�, ����, ������ �޾� ����ü ��������� ����
		fscanf(f2, "%c %d %s %c\n", &newStudent.name, &newStudent.ID, newStudent.major, &newStudent.grade);

		//alphabetSortList ����Ʈ�� �߰�, ���ÿ� �̸� �������� ����
		alphabetSortList.insert(newStudent);
	}
	
	cout << "���� 3)" << endl;
	//alphabetSortList ����Ʈ���� major�� CS�� �л��� ������ ���
	alphabetSortList.displayMajorCS();

	return 0;
}
#endif