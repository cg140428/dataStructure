#ifndef KRUSKAL_H
#define KRUSKAL_H
#include <iostream>

using namespace std;

const int MAX_VERTEX = 6; // 정점 최대값
const int MAX_EDGE = 10; // 간선 최대값

						 // 각 정점의 인접 관계를 인접 행렬로 표현: 
						 // 정점 i에서 정점 j로 가는 간선이 있으면 행렬의 원소를 1, 없다면 0으로 표기
const int adjacencyMatrix[MAX_VERTEX][MAX_VERTEX] = {
	100, 6, 1, 5, 100, 100,
	6, 100, 7, 100, 3, 100,
	1, 7, 100, 5, 8, 4,
	5, 100, 5, 100, 100, 2,
	100, 3, 8, 100, 100, 9,
	100, 100, 4, 2, 9, 100
};

//간선을 의미하는 클래스 - 양 옆의 정점과 간선의 가중치
class Edge {
private:
	char ff; // 정점1의 값
	int weight; // 간선의 가중치 값
	char ll; //정점2의 값
public:
	Edge(char ff, int weight, char ll); //Edge 생성자
	friend class KruskalMST;
};

//Kruskal 알고리즘에 대한 클래스 - 인접 리스트, 최상위 부모(연결된 정점 중 오름차순으로 제일 순서가 낮은 정점), 가중치의 합
class KruskalMST {
private:
	Edge * adjacencyList[MAX_EDGE]; //인접 리스트
	char parent[MAX_VERTEX]; // 각 정점의 연결된 최상위 부모를 나타내는 배열
	int costSum; //가중치의 합
public:
	KruskalMST(); //KruskalMST 생성자
	void printOriginData(); // 정렬 전 인접 리스트 데이터를 출력하는 함수
	void printSortedData(); // 가중치에 대해 정렬 후 인접 리스트 데이터를 출력라는 함수
	void sortByWeight();//간선의 가중치를 기준으로 오름차순 정렬하는 함수
	char getParent(char index); // 재귀 함수를 사용하여 연결된 정점 중 최상위 부모 정점을 가져오는 함수
	void unionParent(char index1, char index2); // 재귀 함수를 사용하여 최상위 부모를 재설정하는 함수
	bool whetherSameParent(char index1, char index2); //같은 최상위 부모를 가지는지 확인하는 함수
	void kruskal(); // Kruskal Algorithm을 사용한 spanning 과정 및 총 가중치 값의 합을 출력
	friend class Node;
};
#endif
