/************************************************************************
*Name: 이다은
*Student ID: 20171661
*Program ID: HW5_Kruskal's Algorithm
*Description:
-Kruskal Algorithm을 사용한 Minimum Spanning Tree
-주어진 인접행렬(Adjacent matrix)을 이용하여 인접리스트(Adjacent list)를 작성
-인접리스트를 간선의 가중치 값을 기준으로 오름차순 정렬
-사이클이 형성되지 않는 경우에만 경로에 추가하고, 사이클이 형성되면 추가하지 않는다

*Algorithm:
- main 함수에는 Kruskal 클래스의 객체인 k1을 생성한다.
- 정렬되지 않은 인접리스트 출력 함수와 정렬된 인접 리스트 출력함수를 호출한다.
- Kruskal Algorithm을 사용한 spanning 과정 및 총 가중치 값의 합을 출력하는 함수를 호출한다.
- 생성자 Kruskal에서 정의해야 할 속성은 인접 리스트와 각 정점의 연결된 최상위 부모를 나타내는 배열,
그리고 가중치 값의 합이고 정의 내용은 다음과 같다.
- adjacencyList 배열 포인터는 인접행렬의 인접 리스트화 한 배열이다.
- 이중 for문의 안쪽 for문 변수 j의 시작점을 바깥쪽 for문 변수인 i로 설정하여 중복된 데이터 값의 저장을 피한다.
- 만약 인접 행렬 i행 j열의 값이 100보다 작아서 인접하다면 인접 리스트에 정점1: A + i, 가중치: 인접 행렬 i행 j열의 값, 정점2: A + j의 값을 동적할당한다.
-- Kruskal --
- 인접 리스트를 가중치를 기준으로 오름차순 정렬한다.
- 만약 최상위 부모가 다르다면 (사이클이 형성되지 않으면) costSum에 현재 가중치 값을 더하고 현재 간선의 정점1과 정점2를 이어준 후 이 둘의 최상의 부모를 재설정한다.
-- getParent(int) --
- 만약 정점의 parent값이 자기 자신 이라면 자기 자신dmf 반환한다.
- 그렇지 않다면 재귀 함수를 사용하여 부모의 부모 정점을 반환한다.
-- unionParent(int, int) --
- 만약 index1 정점의 최상위 부모가 index2 정점의 최상위 부모의 순서보다 낮고 ndex2의 최상위 부모가 본인이라면(아직 연결된 선이 없다면) index1 최상위 부모를 index2의 최상위 부모로 설정한다.
- 하지만 index2 정점이 최상위 부모가 본인이 아니라면(연결된 선이 있었다면 재귀 함수를 사용하여 intdex2과 연결되어있던 정점들에 index1의 최상위 부모로 설정한다.
- 만약 index1 정점의 최상위 부모가 index2 정점의 최상위 부모의 순서보다 높고 만약 index1의 최상위 부모가 본인이라면(아직 연결된 선이 없다면) index2 최상위 부모를 index1의 최상위 부모로 설정한다.
- 하지만 index1 정점이 최상위 부모가 본인이 아니라면(연결된 선이 있었다면) 재귀 함수를 사용하여 intdex1과 연결되어있던 정점들에 index2의 최상위 부모로 설정한다.
-- whetherSameParent --
- 만약 index1 정점과 index2 정점의 최상위 부모가 같다면 true / flase 반환
*Variables:
-const MAX_VERTEX = 6; 정점 최대값
-const MAX_EDGE = 10; 간선 최대값
-ff: 정점1의 값
-weight: 간선의 가중치 값
-ll: 정점2의 값
-adjacencyList[MAX_EDGE]; //인접 리스트
-parent[MAX_VERTEX]; // 각 정점의 연결된 최상위 부모를 나타내는 배열
-costSum; //가중치의 합

*Function:
- printOriginData(): 정렬 전 인접 리스트 데이터를 출력하는 함수
-printSortedData(): 가중치에 대해 정렬 후 인접 리스트 데이터를 출력라는 함수
-sortByWeight(): 간선의 가중치를 기준으로 오름차순 정렬하는 함수
-getParent(char):  재귀 함수를 사용하여 연결된 정점 중 최상위 부모 정점을 가져오는 함수
-unionParent(cha, char): 재귀 함수를 사용하여 최상위 부모를 재설정하는 함수
-whetherSameParent(char, char): 같은 최상위 부모를 가지는지 확인하는 함수
-kruskal():  Kruskal Algorithm을 사용한 spanning 과정 및 총 가중치 값의 합을 출력

*/
#ifndef MAIN_CPP
#define MAIN_CPP
#include "kruskal.h"

int main(void) {
	KruskalMST k1;
	k1.printOriginData();
	k1.printSortedData();
	k1.kruskal();
	return 0;
}

#endif
