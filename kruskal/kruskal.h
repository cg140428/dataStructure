#ifndef KRUSKAL_H
#define KRUSKAL_H
#include <iostream>

using namespace std;

const int MAX_VERTEX = 6; // ���� �ִ밪
const int MAX_EDGE = 10; // ���� �ִ밪

						 // �� ������ ���� ���踦 ���� ��ķ� ǥ��: 
						 // ���� i���� ���� j�� ���� ������ ������ ����� ���Ҹ� 1, ���ٸ� 0���� ǥ��
const int adjacencyMatrix[MAX_VERTEX][MAX_VERTEX] = {
	100, 6, 1, 5, 100, 100,
	6, 100, 7, 100, 3, 100,
	1, 7, 100, 5, 8, 4,
	5, 100, 5, 100, 100, 2,
	100, 3, 8, 100, 100, 9,
	100, 100, 4, 2, 9, 100
};

//������ �ǹ��ϴ� Ŭ���� - �� ���� ������ ������ ����ġ
class Edge {
private:
	char ff; // ����1�� ��
	int weight; // ������ ����ġ ��
	char ll; //����2�� ��
public:
	Edge(char ff, int weight, char ll); //Edge ������
	friend class KruskalMST;
};

//Kruskal �˰��� ���� Ŭ���� - ���� ����Ʈ, �ֻ��� �θ�(����� ���� �� ������������ ���� ������ ���� ����), ����ġ�� ��
class KruskalMST {
private:
	Edge * adjacencyList[MAX_EDGE]; //���� ����Ʈ
	char parent[MAX_VERTEX]; // �� ������ ����� �ֻ��� �θ� ��Ÿ���� �迭
	int costSum; //����ġ�� ��
public:
	KruskalMST(); //KruskalMST ������
	void printOriginData(); // ���� �� ���� ����Ʈ �����͸� ����ϴ� �Լ�
	void printSortedData(); // ����ġ�� ���� ���� �� ���� ����Ʈ �����͸� ��¶�� �Լ�
	void sortByWeight();//������ ����ġ�� �������� �������� �����ϴ� �Լ�
	char getParent(char index); // ��� �Լ��� ����Ͽ� ����� ���� �� �ֻ��� �θ� ������ �������� �Լ�
	void unionParent(char index1, char index2); // ��� �Լ��� ����Ͽ� �ֻ��� �θ� �缳���ϴ� �Լ�
	bool whetherSameParent(char index1, char index2); //���� �ֻ��� �θ� �������� Ȯ���ϴ� �Լ�
	void kruskal(); // Kruskal Algorithm�� ����� spanning ���� �� �� ����ġ ���� ���� ���
	friend class Node;
};
#endif
