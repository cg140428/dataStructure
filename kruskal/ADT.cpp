//������ ����� ������������ ������ �Ŀ� �����ش�
//����Ŭ�� �������� �ʴ� ��쿡�� ���տ� ���Խ�Ű��, ����Ŭ�� �����Ǹ� ���տ� ���Խ�Ű�� �ʴ´�
#ifndef ADT_CPP
#define ADT_CPP
#include "kruskal.h"

//Edge ������ - ����Ʈ parameter���� a, 100, a�� �Ҵ�
Edge::Edge(char ff = 'a', int weight = 100, char ll = 'a') {
	this->ff = ff; //�Ű����� ff�� ���� Edge Ŭ������ �Ӽ� ff�� ���� �Ҵ�
	this->weight = weight; //�Ű����� weight�� ���� Edge Ŭ������ �Ӽ� weight�� ���� �Ҵ�
	this->ll = ll; //�Ű����� ll�� ���� Edge Ŭ������ �Ӽ� ll�� ���� �Ҵ�
}

//KruskalMST ������
KruskalMST::KruskalMST() {
	//adjacencyList - ���� ����� ���� ����Ʈȭ (���� ����Ʈ ����)
	int listIndex = 0; //adjacencyList�� index
	for (int i = 0; i < MAX_VERTEX; i++) {
		//j�� �������� i�� �����Ͽ� �ߺ��� ������ ���� ������ ����
		for (int j = i; j < MAX_VERTEX; j++) {
			//���� ���� ��� i�� j���� ���� 100���� �۴ٸ� ������
			if (adjacencyMatrix[i][j] < 100) {
				//���� ����Ʈ�� ����1: A + i, ����ġ: ���� ��� i�� j���� ��, ����2: A + j �����Ҵ�
				adjacencyList[listIndex++] = new Edge('A' + i, adjacencyMatrix[i][j], 'A' + j);
			}
		}
	}

	//parent - �ֻ��� �θ� ��Ÿ���� �迭 �ʱ�ȭ
	//�ڱ� �ڽ��� �������� �ʱ�ȭ
	for (int i = 0; i < MAX_VERTEX; i++) {
		parent[i] = 'A' + i;
	}

	//costSum - ����ġ�� ��
	costSum = 0; //0���� �ʱ�ȭ
}

// ���� �� ���� ����Ʈ �����͸� ����ϴ� �Լ�
void KruskalMST::printOriginData() {
	cout << "Original Data: " << endl;
	for (int i = 0; i < MAX_EDGE; i++) {
		cout << adjacencyList[i]->ff << " " << adjacencyList[i]->weight << " " << adjacencyList[i]->ll;
		if (i < MAX_EDGE - 1)
			cout << ", ";
	}
	cout << endl;
	cout << endl;
}

// ����ġ�� ���� ���� �� ���� ����Ʈ �����͸� ��¶�� �Լ�
void KruskalMST::printSortedData() {
	sortByWeight(); // ���� ����Ʈ�� ����ġ�� �������� �������� �����ϴ� �Լ��� ȣ��

	cout << "Sorted Data: " << endl;
	for (int i = 0; i < MAX_EDGE; i++) {
		cout << adjacencyList[i]->ff << " " << adjacencyList[i]->weight << " " << adjacencyList[i]->ll;
		if (i < MAX_EDGE - 1)
			cout << ", ";
	}
	cout << endl;
	cout << endl;
}

//������ ����ġ�� �������� �������� �����ϴ� �Լ�
void KruskalMST::sortByWeight() {
	Edge* temp; //�ӽ����� �����͸� ����Ű�� Edge�� temp ������ ���� 
				//bubble sort�� ����Ͽ� ����ġ�� �������� �������� �����Ѵ�.
	for (int i = 0; i < MAX_EDGE; i++) {
		for (int j = 0; j < MAX_EDGE - (i + 1); j++) {
			//���� i�� ° ���� ����Ʈ�� ����ġ �� ���� i + 1�� ° ����ġ ���� ũ��
			if (adjacencyList[j]->weight > adjacencyList[j + 1]->weight) {
				//i�� ° ����Ʈ�� i + 1�� ° ����Ʈ�� �ڸ��� �ٲ�
				temp = adjacencyList[j];
				adjacencyList[j] = adjacencyList[j + 1];
				adjacencyList[j + 1] = temp;
			}
		}
	}
}

// ����Լ��� ����Ͽ� ����� ���� �� �ֻ��� �θ� ������ �������� �Լ�
char KruskalMST::getParent(char index) {
	int pIndex = index - 65; // parameter�� ���� ������ ���� parent �迭�� index�� ����
							 //���� ������ parent���� �ڱ� �ڽ� �̶��
	if (parent[index - 65] == 'A' + pIndex)
		return 'A' + pIndex; //�ڱ� �ڽ� ��ȯ
							 //�׷��� �ʴٸ�
	else
		//��� �Լ��� ����Ͽ� �θ��� �θ� ������ ��ȯ
		return parent[index - 65] = getParent(parent[index - 65]);
}

// ����Լ��� ����Ͽ� �ֻ��� �θ� �缳���ϴ� �Լ�
void KruskalMST::unionParent(char index1, char index2) {
	//���� index1 ������ �ֻ��� �θ� index2 ������ �ֻ��� �θ��� �������� ������
	if (getParent(index1) < getParent(index2)) {
		//���� index2�� �ֻ��� �θ� �����̶��(���� ����� ���� ���ٸ�)
		if (parent[index2 - 65] == 'A' + (index2 - 65))
			//index1 �ֻ��� �θ� index2�� �ֻ��� �θ�� ����
			parent[index2 - 65] = getParent(index1);
		//index2 ������ �ֻ��� �θ� ������ �ƴ϶��(����� ���� �־��ٸ�)
		else
			//��� �Լ��� ����Ͽ� intdex2�� ����Ǿ��ִ� �����鿡 index1�� �ֻ��� �θ�� ����
			unionParent(index1, parent[index2 - 65]);
	}
	//���� index1 ������ �ֻ��� �θ� index2 ������ �ֻ��� �θ��� �������� ������
	else {
		//���� index1�� �ֻ��� �θ� �����̶��(���� ����� ���� ���ٸ�)
		if (parent[index1 - 65] == 'A' + (index1 - 65))
			//index2 �ֻ��� �θ� index1�� �ֻ��� �θ�� ����
			parent[index1 - 65] = getParent(index2);
		//index1 ������ �ֻ��� �θ� ������ �ƴ϶��(����� ���� �־��ٸ�)
		else
			//��� �Լ��� ����Ͽ� intdex1�� ����Ǿ��ִ� �����鿡 index2�� �ֻ��� �θ�� ����
			unionParent(parent[index1 - 65], index2);
	}
}

//���� �ֻ��� �θ� �������� Ȯ���ϴ� �Լ�
bool KruskalMST::whetherSameParent(char index1, char index2) {
	//���� index1 ������ index2 ������ �ֻ��� �θ� ���ٸ�
	if (getParent(index1) == getParent(index2))
		return true; //true ��ȯ
	else
		return false; //flase ��ȯ
}

// Kruskal Algorithm�� ����� spanning ���� ���
void KruskalMST::kruskal() {
	sortByWeight(); // ���� ����Ʈ�� ����ġ�� �������� �������� �����ϴ� �Լ��� ȣ��

					//Minimum Spanning Tree ���� ���� �� ���
	cout << "Kruskal's MST: " << endl;
	for (int i = 0; i < MAX_EDGE; i++) {
		//���� �ֻ��� �θ� �ٸ��ٸ� (����Ŭ�� �������� ������)
		if (!whetherSameParent(adjacencyList[i]->ff, adjacencyList[i]->ll)) {
			//costSum�� ���� ����ġ ���� ����
			costSum += adjacencyList[i]->weight;
			//���� ������ ����1�� ����2�� �̾��ְ� �� ���� �ֻ��� �θ� �缳��
			unionParent(adjacencyList[i]->ff, adjacencyList[i]->ll);

			//���� ����1 ����ġ ����2�� ���
			cout << "Edge" << i + 1 << ": " << adjacencyList[i]->ff << " " << adjacencyList[i]->weight << " ";
			cout << adjacencyList[i]->ll << endl;
		}
	}
	cout << endl; //����
				  //�� ������ ����ġ�� �� ���
	cout << "Total Cost:   " << costSum << endl;
}

#endif
