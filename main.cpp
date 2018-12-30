/************************************************************************
*Name: 이다은
*Student ID: 20171661
*Program ID: HW3_BinarySearchTree
*Description: 
-이진 탐색 트리를 사용하여 데이터 저장, 탐색, 찾기 및 출력
-이진 탐색 트리의 속성
  - 각 노드에 값이 존재
  -값이 중복된 노드가 없음
  -노드의 왼쪽 서브트리에는 해당 노드의 값보다 작은 값들을 지닌 노드로 구성
  -노드의 오른쪽 서브트리에는 해당 노드의 값보다 큰 값들을 지닌 노드로 구성
  -좌우의 서브트리는 각각 이진 탐색 트리여야 함

*Algorithm: 
-main 함수에 (1. Insert, 2. Delete, 3.Search, 4.Print 5. Quit) 메뉴를 구현한다.
-데이터 삽입 함수는 recursive로 구현한다. 또한, recursive 함수 구현을 위해 반환형을 Node형 포인터로 지정한다.
  -(p == NULL)로 leaf에 다다르면 삽입 할 데이터를 저장한다. 만약, 비어있는 이진 트리라면, 데이터를 저장하고 root 포인터로 지정해준다.
  -recursive를 사용해 삽입할 데이터 값이 현재의 값 보다 작으면 왼쪽 서브트리로 이동한다.
  -recursive를 사용해 삽입할 데이터 값이 현재의 값 보다 크면 오른쪽 서브트리로 이동한다.
-데이터 탐색 함수는 recursive로 구현한다. 또한, recursive 함수 구현을 위해 반환형을 Node형 포인터로 지정한다.
  -(p == NULL)로 비어있는 이진 탐색 트리라면 데이터 값을 찾을 수 없음을 출력한다.
  -(data == p->data)로 //타겟 데이터 값이 현재의 값과 같을 경우 찾음을 출력한다.
  -recursive를 사용해 삽입할 데이터 값이 현재의 값 보다 작으면 왼쪽 서브트리로 이동한다.
  -recursive를 사용해 삽입할 데이터 값이 현재의 값 보다 크면 오른쪽 서브트리로 이동한다.
-데이터 삭제 함수는 recursive로 구현한다. 또한, recursive 함수 구현을 위해 반환형을 Node형 포인터로 지정한다.
  -경우의 수는 자식이 없는 경우, 자식이 하나만 있는 경우, 자식이 둘 다 있는 경우로 나눈다.
  -1)자식이 없는 경우 현재 위치하고 있는 포인터 값을 NULL로 만들어 부모와의 연결을 끊어준다.
  -2)자식이 하나만 있는 경우 오른쪽 자식이 있는 경우와 왼쪽 자식이 있는 경우, root를 삭제하는 경우로 나뉜다. 알고리즘은 같다.
  -오른쪽 자식만 있는 경우 대상 Node의 오른쪽자식 Node를 삭제할 Node에 대입해주고, 대상Node는 삭제한다.
  -왼쪽 자식만 있는 경우 대상 Node의 왼쪽 자식Node를 삭제할 Node에 대입해주고, 대상Node는 삭제한다.
  -삭제할 대상이 root Node일 경우 자식 Npde를 root로 재정의 해준다.
  -3)자식이 둘 다 있는 경우 삭제할 Node의 양 자식 데이터 값 사이의 값을 후계자로 지정하여 삭제할 Node의 위치로 옮긴다. 후계자는 우측 서브트리에서 가장 작은 값의 데이터로 지정한다.
  -그 후 후계자의 자식 Node들을 한 단계씩 위로 이동시켜 트리를 재구성한다.
-트리 출력 함수는 recursive로 구현한다.
  -높이에 따른 공백으로 트리 형태를 구현한다.
  -두개의 자식을 가지면 '<' 가지 사용하고 오른쪽 자식만을 가지면  '/'가지 사용, 왼쪽 자식만을 가지면  '\'가지를 사용한다.
*Variables:
-int data: 데이터 값
-Node* left: 왼쪽 서브트리 가리키는 포인터
-Node* right: 오른쪽 서브트리 가리키는 포인터
-Node * root: root를 가리키는 Node형 포인터
-*p: 이진 탐색 트리에서 현재 위치를 가리키는 포인터
-*temp: 삭제 함수에서 삭제할 Node가 두 개의 자식을 갖는 경우 후계자를 가리키는 포인터

*Function:
-Node* insert(Node* p, int data): 데이터 삽입 함수
-Node* search(Node* p, int data): 데이터 탐색하는 함수
-Node* del(Node* p, int data): 데이터 삭제 함수
-Node* find_min(Node* p): 가장 마지막 왼쪽 서브트리를 탐색하는 함수
-void printBTS(): 이진 탐색 트리 출력 실행합수 - 사용자 용
-void display(Node* p, int level): 이진 탐색 트리 출력 실행 함수 - 실체
-Node* getRoot(): root를 가리키는 포인터를 반환하는 함수

*/

#ifndef MAIN_CPP
#define MAIN_CPP
#include "BST.h"

int main(void) {
	int menu;
	Tree t1;
	do {
		//메뉴 구성
		cout << "1. Insert, 2. Delete, 3.Search, 4.Print 5. Quit" << endl;
		cin >> menu;

		int num;
		//메뉴 1을 선택하면 삽입할 데이터 값을 입력받고 삽입 함수 호출
		if (menu == 1) {
			cout << "Enter a number for insert: ";
			cin >> num;
			t1.insert(t1.getRoot(), num);
		}
		//메뉴 2을 선택하면 삭제할 데이터 값을 입력받고 삭제 함수 호출
		else if (menu == 2) {
			cout << "Enter a number for delete: ";
			cin >> num;
			t1.del(t1.getRoot(), num);
		}
		//메뉴 3을 선택하면 탐색할 데이터 값을 입력받고 탐색 함수 호출
		else if (menu == 3) {
			cout << "Enter a number for search: ";
			cin >> num;
			t1.search(t1.getRoot(), num);
		}
		//메뉴 4을 선택하면 현재 이진 탐색 트리 상황 출력
		else if(menu == 4) {
			t1.printBTS();
		}
	} while (menu != 5); // 메뉴 5를 선택하면 while문이 종료되면서 프로그램 종료

	return 0;
}

#endif