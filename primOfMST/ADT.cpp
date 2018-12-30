#ifndef ADT_CPP
#define ADT_CPP
#include"prim.h"

Node::Node(int ff, int weight, int ll) {
	this->ff = ff;
	this->weight = weight;
	this->ll = ll;
}

primMST::primMST() {
	//cost
	for (int i = 0; i < MAX_NODE; i++) {
		for (int j = 0; j < MAX_NODE; j++) {
			cost[i][j] = new Node(i + 1, adjacencyMatrix[i][j], j + 1);
		}
	}

	//lowerCost[i] --> vertex [i + 1]
	for (int i = 0; i < MAX_NODE; i++) {
		Node* lowest = cost[i][0];
		for (int j = 1; j < MAX_NODE; j++) {
			if (lowest->weight > cost[i][j]->weight)
				lowest = cost[i][j];
		}
		lowerCost[i] = lowest;
	}

	//MST
	for (int i = 0; i < MAX_NODE - 1; i++) {
		Node* MST = NULL;
	}

	//visited
	for (int i = 0; i < MAX_NODE; i++) {
		visited[i] = false;
	}

	//weight
	weight = 0;
}
void primMST::printWeightedGraph() {
	cout << "***** Weighted Graph *****" << endl;
	for (int i = 0; i < MAX_NODE + 1; i++) {
		for (int j = 0; j < MAX_NODE + 1; j++) {
			if (i == 0 && j == 0)
				cout << "   ";
			else if (i == 0 && j != 0)
				cout << "v" << j << "  ";
			else if (i != 0 && j == 0)
				cout << "v" << i << "  ";
			else
				cout << adjacencyMatrix[i - 1][j - 1] << "  ";
		}
		cout << endl;
	}
}

void primMST::prim(int vertex) {
	cout << "***** Minimal Spamming Tree(v1���� ����) *****" << endl;
	int indexMST = 0;
	visited[vertex - 1] = true;
	Node* lowest = cost[vertex - 1][0];
	for (int i = 1; i < MAX_NODE; i++) {
		if (lowest->weight > cost[vertex - 1][i]->weight)
			lowest = cost[vertex - 1][i];
	}
	MST[indexMST] = lowest;
	indexMST++;
	weight += lowest->weight;
	cout << lowest->ff << ", " << lowest->ll << " -> ";

	while (indexMST != MAX_NODE - 1) {
		lowest = cost[0][0];
		for (int i = 0; i < MAX_NODE; i++) {
			if(cost[i][0]->ff == MST[indexMST - 1]->ll)
				for (int k = 0; k < MAX_NODE; k++) {
					//������ ���� wieght�� �۰� ������ �ڱ� �ڽ��� �ƴ� ��� weight �ּҰ����� �ֱ�
					if (lowest->weight > cost[i][k]->weight  && visited[cost[i][k]->ll - 1] == false) {
						lowest = cost[i][k];
					}
				}
		}
		MST[indexMST] = lowest;
		visited[lowest->ff - 1] = true; //�湮���
		weight += lowest->weight;
		indexMST++;
		cout << lowest->ff << ", " << lowest->ll;
		if (indexMST != MAX_NODE - 1)
			cout << " -> ";

		/*
		for (int i = 0; i < indexMST; i++) {
			for (int j = 0; j < MAX_NODE; j++) {
				
				//MST�� ������ ������ && MST�� ����� ��
				if (cost[j][0]->ff == MST[i]->ff) {
					for (int k = 0; k < MAX_NODE; k++) {
						if ((cost[j][k]->ll != MST[i]->ll) && (lowest->weight > cost[j][k]->weight))
							lowest = cost[j][k];
					}
					
				}
				else(cost[j][0]->ff == MST[indexMST - 1]->ll)
			}
			
		}
		MST[indexMST++] = lowest;
		cout << lowest->ff << ", " << lowest->ll << " -> ";
		*/
	}
	cout << endl;
	cout << "weight: " << weight << endl;
}

void primMST::prim2(int vertex) {
	cout << "***** Minimal Spamming Tree(v1���� ����) *****" << endl;
	int indexMST = 0;
	visited[vertex - 1] = true;
	Node* lowest = cost[vertex - 1][0];
	for (int i = 1; i < MAX_NODE; i++) {
		if (lowest->weight > cost[vertex - 1][i]->weight)
			lowest = cost[vertex - 1][i];
	}
	MST[indexMST] = lowest;
	indexMST++;
	visited[lowest->ll - 1] = true;
	weight += lowest->weight;
	cout << lowest->ff << ", " << lowest->ll << " -> ";

	while (indexMST != MAX_NODE - 1) {
		lowest = cost[0][0];
		for (int i = 0; i < MAX_NODE; i++) {
			if (visited[cost[i][0]->ff - 1] == true)
				for (int k = 0; k < MAX_NODE; k++) {
					//������ ���� wieght�� �۰� ������ �ڱ� �ڽ��� �ƴ� ��� weight �ּҰ����� �ֱ�
					if (lowest->weight > cost[i][k]->weight  && visited[cost[i][k]->ll - 1] == false) {
						lowest = cost[i][k];
					}
				}
		}
		MST[indexMST] = lowest;
		visited[lowest->ff - 1] = true; //�湮���
		weight += lowest->weight;
		indexMST++;
		cout << lowest->ff << ", " << lowest->ll;
		if (indexMST != MAX_NODE - 1)
			cout << " -> ";

		/*
		for (int i = 0; i < indexMST; i++) {
		for (int j = 0; j < MAX_NODE; j++) {

		//MST�� ������ ������ && MST�� ����� ��
		if (cost[j][0]->ff == MST[i]->ff) {
		for (int k = 0; k < MAX_NODE; k++) {
		if ((cost[j][k]->ll != MST[i]->ll) && (lowest->weight > cost[j][k]->weight))
		lowest = cost[j][k];
		}

		}
		else(cost[j][0]->ff == MST[indexMST - 1]->ll)
		}

		}
		MST[indexMST++] = lowest;
		cout << lowest->ff << ", " << lowest->ll << " -> ";
		*/
	}
	cout << endl;
	cout << "weight: " << weight << endl;
}
#endif