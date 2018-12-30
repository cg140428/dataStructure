#ifndef ADT_CPP
#define ADT_CPP
#include "BST.h"

//Node 생성자
Node::Node(int data)
	//왼쪽 서브트리와 오른쪽 서브트리를 가리키는 포인터의 값은 NULL로 초기화
	:left(NULL), right(NULL) {
	this->data = data; //애개변수로 받은 data값을 클래스의 멤버변수 data에 할당
}

//Tree 생성자
Tree::Tree() {
	root = NULL; //root를 가리키는 포인터 값을 NULL로 초기화
}

//데이터 삽입 함수 - recursive
//recursive 함수 구현을 위해 반환형을 Node형 포인터로 지정
Node* Tree::insert(Node* p, int data) {
	//비어있는 이진 탐색 트리라면 Node를 생성
	if (p == NULL) {
		p = new Node(data);
		//root 포인터가 아무것도 가리키고 있지 않다면 새로 생성한 Node를 포인터 root가 가리키게 함
		if (root == NULL)
			root = p;
	}
	//삽입할 데이터 값이 현재의 값 보다 작으면 왼쪽 서브트리로 이동
	else if(data < p->data){
		p->left = Tree::insert(p->left, data);
	}
	//삽입할 데이터 값이 현재의 값 보다 크면 오른쪽 서브트리로 이동
	else if (data > p->data) {
		p->right = Tree::insert(p->right, data);
	}
	//현재 위치하고 있는 Node형 포인터 반환
	return p;
}

//데이터 탐색하는 함수
//recursive 함수 구현을 위해 반환형을 Node형 포인터로 지정
Node* Tree::search(Node* p, int data) {
	//비어있는 이진 탐색 트리라면 데이터 값을 찾을 수 없음을 출력
	if (p == NULL) {
		cout << data << " is not found" << endl;
		return NULL; //NULL를 반환
	}
	else {
		//타겟 데이터 값이 현재의 값과 같을 경우 찾음을 출력
		if (data == p->data) {
			cout << p->data << " is found" << endl;
			//현재 위치하고 있는 Node형 포인터 반환
			return p;
		}
		//타겟 데이터 값이 현재의 값 보다 작으면 왼쪽 서브트리로 이동
		else if (data < p->data)
			p = search(p->left, data);
		//타겟 데이터 값이 현재의 값 보다 크면 오른쪽 서브트리로 이동
		else if (data > p->data)
			p = search(p->right, data);
	}
	//현재 위치하고 있는 Node형 포인터 반환
	return p;
}

// 데이터 삭제 함수
//recursive 함수 구현을 위해 반환형을 Node형 포인터로 지정
Node* Tree::del(Node* p, int data) {
	//비어있는 이진 탐색 트리가 아니라면 조건문 수행
	if (p != NULL) {
		//삭제할 데이터 값이 현재의 값 보다 작으면 왼쪽 서브트리로 이동
		if (data < p->data)
			p->left = del(p->left, data);
		//삭제할 데이터 값이 현재의 값 보다 크면 오른쪽 서브트리로 이동
		else if (data > p->data)
			p->right = del(p->right, data);
		//1) 자식이 없는 경우 (leaf)
		else if ((p->left == NULL) && (p->right == NULL))
			//현재 값을 NULL로 만들어 연결을 끊어준다.
			p = NULL;
		//2) 자식이 하나만 있는 경우 (single)
		//오른쪽 자식만 있는 경우 대상 Node의 오른쪽자식Node를 삭제할 Node에 대입해주고, 대상Node는 삭제
		else if (p->left == NULL) {
			Node* q;
			q = p;
			p = p->right;
			if (q == root)
				root = p;
			delete(q);
		}
		//왼쪽 자식만 있는 경우 대상 Node의 왼쪽자식Node를 삭제할 Node에 대입해주고, 대상Node는 삭제
		else if (p->right == NULL) {
			Node* q;
			q = p;
			p = p->left;
			if (q == root)
				root = p;
			delete(q);
		}
		//3) 좌측, 우측 자식을 모두 가진 경우
		else {
			//삭제할 Node의 양 자식 데이터 값 사이의 값을 후계자로 지정하여 삭제할 Node의 위치로 옮김
			//후계자의 자식 Node들을 한 단계씩 위로 이동시켜 트리를 재구성
			Node* temp;
			temp = Tree::find_min(p->right);
			p->data = temp->data;
			p->right = del(p->right, p->data);
		}
	}
	//비어있는 이진 탐색 트리이거나, 해당 값을 찾지 못하면 찾을 수 없을을 출력
	else
		cout << "Not found" << endl;
	//현재 위치하고 있는 Node형 포인터 반환
	return p;
}

// 가장 마지막 왼쪽 서브트리를 탐색하는 함수
//우측 서브트리에서 가장 작은 값의 Node형 포인터를 반환
Node* Tree::find_min(Node* p) {
	//왼쪽 서브트리가 NULL이면 포인터 p 반환
	if (p->left == NULL) {
		return p;
	}
	//왼족 서브트리가 NULL이 아니라면 그 다음 왼쪽 서브트리로 이동
	else {
		find_min(p->left);
	}
}

//이진 탐색 트리 출력 실행합수 - 사용자 용
//고정된 매개변수로 이진 탐색 트리의 실체 함수를 호출
void Tree::printBTS() {
	Tree::display(Tree::getRoot(), 1);
}

// 이진 탐색 트리 출력 실행 함수 - 실체 - recursive
//왼쪽이 root이고 오른쪽이 leaf인 형태의 트리
void Tree::display(Node* p, int level) {
	//비어있는 이진 탐색 트리가 아니거나 높이가 7이하라면
	if (p != 0 && level <= 7) {
		//오른쪽 서브트리로 내려가고 높이 1 추가
		display(p->right, level + 1);
		//높이만큼 공백을 추가하여 트리 형태 구현
		for (int i = 0; i <= level - 1; i++)
			cout << "     ";
		//데이터 값 출력
		cout << p->data;
		//두개의 자식을 가지면 '<' 가지 사용
		if (p->left != 0 && p->right != 0)
			cout << "<" << endl;
		//오른쪽 자식만을 가지면  '/'가지 사용
		else if (p->right != 0)
			cout << " /" << endl;
		//왼쪽 자식만을 가지면  '\'가지 사용
		else if (p->left != 0)
			cout << " \\" << endl;
		else
			cout << endl;
		//왼쪽 서브트리로 내려가고 높이 1 추가
		display(p->left, level + 1);
	}
}

//root를 가리키는 포인터를 반환하는 함수
Node* Tree::getRoot() {
	return root; // 함수를 호출하면 root를 가리키는 포인터를 반환
}

#endif