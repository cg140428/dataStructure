//간선의 비용을 오름차순으로 정렬한 후에 비교해준다
//사이클이 형성되지 않는 경우에만 집합에 포함시키고, 사이클이 형성되면 집합에 포함시키지 않는다
#ifndef ADT_CPP
#define ADT_CPP
#include "kruskal.h"

//Edge 생성자 - 디폴트 parameter값을 a, 100, a로 할당
Edge::Edge(char ff = 'a', int weight = 100, char ll = 'a') {
	this->ff = ff; //매개변수 ff의 값을 Edge 클래스의 속성 ff의 값에 할당
	this->weight = weight; //매개변수 weight의 값을 Edge 클래스의 속성 weight의 값에 할당
	this->ll = ll; //매개변수 ll의 값을 Edge 클래스의 속성 ll의 값에 할당
}

//KruskalMST 생성자
KruskalMST::KruskalMST() {
	//adjacencyList - 인접 행렬의 인접 리스트화 (인접 리스트 생성)
	int listIndex = 0; //adjacencyList의 index
	for (int i = 0; i < MAX_VERTEX; i++) {
		//j의 시작점을 i로 설정하여 중복된 데이터 값의 저장을 피함
		for (int j = i; j < MAX_VERTEX; j++) {
			//만약 인접 행렬 i행 j열의 값이 100보다 작다면 인접함
			if (adjacencyMatrix[i][j] < 100) {
				//인접 리스트에 정점1: A + i, 가중치: 인접 행렬 i행 j열의 값, 정점2: A + j 동적할당
				adjacencyList[listIndex++] = new Edge('A' + i, adjacencyMatrix[i][j], 'A' + j);
			}
		}
	}

	//parent - 최상위 부모를 나타내는 배열 초기화
	//자기 자신의 정점으로 초기화
	for (int i = 0; i < MAX_VERTEX; i++) {
		parent[i] = 'A' + i;
	}

	//costSum - 가중치의 합
	costSum = 0; //0으로 초기화
}

// 정렬 전 인접 리스트 데이터를 출력하는 함수
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

// 가중치에 대해 정렬 후 인접 리스트 데이터를 출력라는 함수
void KruskalMST::printSortedData() {
	sortByWeight(); // 인접 리스트를 가중치를 기준으로 오름차순 정렬하는 함수를 호출

	cout << "Sorted Data: " << endl;
	for (int i = 0; i < MAX_EDGE; i++) {
		cout << adjacencyList[i]->ff << " " << adjacencyList[i]->weight << " " << adjacencyList[i]->ll;
		if (i < MAX_EDGE - 1)
			cout << ", ";
	}
	cout << endl;
	cout << endl;
}

//간선의 가중치를 기준으로 오름차순 정렬하는 함수
void KruskalMST::sortByWeight() {
	Edge* temp; //임시적인 데이터를 가리키는 Edge형 temp 포인터 생성 
				//bubble sort를 사용하여 가중치를 기준으로 오름차순 정렬한다.
	for (int i = 0; i < MAX_EDGE; i++) {
		for (int j = 0; j < MAX_EDGE - (i + 1); j++) {
			//만약 i번 째 인접 리스트의 가중치 값 보다 i + 1번 째 가중치 값이 크면
			if (adjacencyList[j]->weight > adjacencyList[j + 1]->weight) {
				//i번 째 리스트와 i + 1번 째 리스트의 자리를 바꿈
				temp = adjacencyList[j];
				adjacencyList[j] = adjacencyList[j + 1];
				adjacencyList[j + 1] = temp;
			}
		}
	}
}

// 재귀함수를 사용하여 연결된 정점 중 최상위 부모 정점을 가져오는 함수
char KruskalMST::getParent(char index) {
	int pIndex = index - 65; // parameter로 받은 정점에 대한 parent 배열의 index를 구함
							 //만약 정점의 parent값이 자기 자신 이라면
	if (parent[index - 65] == 'A' + pIndex)
		return 'A' + pIndex; //자기 자신 반환
							 //그렇지 않다면
	else
		//재귀 함수를 사용하여 부모의 부모 정점을 반환
		return parent[index - 65] = getParent(parent[index - 65]);
}

// 재귀함수를 사용하여 최상위 부모를 재설정하는 함수
void KruskalMST::unionParent(char index1, char index2) {
	//만약 index1 정점의 최상위 부모가 index2 정점의 최상위 부모의 순서보다 낮으면
	if (getParent(index1) < getParent(index2)) {
		//만약 index2의 최상위 부모가 본인이라면(아직 연결된 선이 없다면)
		if (parent[index2 - 65] == 'A' + (index2 - 65))
			//index1 최상위 부모를 index2의 최상위 부모로 설정
			parent[index2 - 65] = getParent(index1);
		//index2 정점이 최상위 부모가 본인이 아니라면(연결된 선이 있었다면)
		else
			//재귀 함수를 사용하여 intdex2과 연결되어있던 정점들에 index1의 최상위 부모로 설정
			unionParent(index1, parent[index2 - 65]);
	}
	//만약 index1 정점의 최상위 부모가 index2 정점의 최상위 부모의 순서보다 높으면
	else {
		//만약 index1의 최상위 부모가 본인이라면(아직 연결된 선이 없다면)
		if (parent[index1 - 65] == 'A' + (index1 - 65))
			//index2 최상위 부모를 index1의 최상위 부모로 설정
			parent[index1 - 65] = getParent(index2);
		//index1 정점이 최상위 부모가 본인이 아니라면(연결된 선이 있었다면)
		else
			//재귀 함수를 사용하여 intdex1과 연결되어있던 정점들에 index2의 최상위 부모로 설정
			unionParent(parent[index1 - 65], index2);
	}
}

//같은 최상위 부모를 가지는지 확인하는 함수
bool KruskalMST::whetherSameParent(char index1, char index2) {
	//만약 index1 정점과 index2 정점의 최상위 부모가 같다면
	if (getParent(index1) == getParent(index2))
		return true; //true 반환
	else
		return false; //flase 반환
}

// Kruskal Algorithm을 사용한 spanning 과정 출력
void KruskalMST::kruskal() {
	sortByWeight(); // 인접 리스트를 가중치를 기준으로 오름차순 정렬하는 함수를 호출

					//Minimum Spanning Tree 과정 도출 및 출력
	cout << "Kruskal's MST: " << endl;
	for (int i = 0; i < MAX_EDGE; i++) {
		//만약 최상위 부모가 다르다면 (사이클이 형성되지 않으면)
		if (!whetherSameParent(adjacencyList[i]->ff, adjacencyList[i]->ll)) {
			//costSum에 현재 가중치 값을 더함
			costSum += adjacencyList[i]->weight;
			//현재 간선의 정점1과 정점2를 이어주고 이 둘의 최상의 부모를 재설정
			unionParent(adjacencyList[i]->ff, adjacencyList[i]->ll);

			//현재 정점1 가중치 정점2를 출력
			cout << "Edge" << i + 1 << ": " << adjacencyList[i]->ff << " " << adjacencyList[i]->weight << " ";
			cout << adjacencyList[i]->ll << endl;
		}
	}
	cout << endl; //개행
				  //총 간선의 가중치의 합 출력
	cout << "Total Cost:   " << costSum << endl;
}

#endif
