#ifndef ADT_CPP
#define ADT_CPP
#include "SingleLinkedList.h"

//Node 생성자 - 전달 받은 구조체의 멤버변수 값을 
//			  - Node의 각 멤버변수 값에 저장
Node::Node(Student newStudent) {
	//구조체로 받아온 학생 이름(newStudent.name)을 Node생성자의 학생이름(name)에 저장
	name = newStudent.name; 
	//구조체로 받아온 학생 학번(newStudent.ID)을 Node생성자의 학생학번(ID)에 저장
	ID = newStudent.ID; 
	//구조체로 받아온 학생 전공(newStudent.major)을 Node생성자의 학생전공(major)에 저장
	strcpy(major, newStudent.major); 
	//구조체로 받아온 학생 성적(newStudent.grade)을 Node생성자의 학생성적(grade)에 저장
	grade = newStudent.grade;
	//Node생성자의 next포인터에 NULL값 초기화
	next = NULL;
}

//SingleLinkedList 생성자 - head 포인터를 초기화 
SingleLinkedList::SingleLinkedList(){
	//SIngleLinkedList생성자 head 포인터에 NULL값 초기화
	head = NULL;
}

//isEmpty() - 연결 리스트가 비었는지 검사하는 함수
bool SingleLinkedList::isEmpty() {
	//list가 비었을 경우
	if (head == NULL)
		return true; //참
	else
		return false; //거짓
}

//insert() - 연결 리스트에 노드를 오름차순으로 삽입하는 함수
void SingleLinkedList::insert(Student newStudent) {
	//추가할 Node의 주소값을 temp 포인터에 할당
	Node* temp = new Node(newStudent);
	//Node를 가리키는 pre, now 포인터 생성
	Node* pre;
	Node* now;

	//list가 비었을 경우
	if (isEmpty()) {
		//head 포인터에 추가할 Node의 주소값을 저장
		head = temp;
	}
	//새 Node가 첫번째 Node 앞에 정렬될 경우
	else if (temp->name < head->name) {
		//추가할 Node의 next 포인터가 첫번째 Node를 가리키게 함
		temp->next = head;
		//head포인터가 새로운 Node를 가리키게 함
		head = temp;
	}
	else {
		//now 포인터가 첫번 째 Node를 가리키게 함
		now = head;
		//now 포인터가 NULL값이 아니거나, now가 가리키는 Node의 name 값이
		//새 Node의 namer 값 보다 작으면 반복문을 실행
		while (now != NULL && now->name < temp->name) {
			//now 선행 포인터 pre에 now값 저장
			pre = now;
			//now가 다음 Node를 가리키게 함
			now = now->next;
		}
		//새 Node가 중간에 정렬될 경우
		if (now != NULL) {
			//추가할 Node의 next포인터에 now의 값을 저장
			temp->next = now;
			//pre 포인터가 가리키는 Node의 next포인터에 새 Node의 주소값을 저장
			pre->next = temp;
		}
		//새 Node가 제일 끝 쪽에 정렬될 경우
		else {
			//pre포인터가 가리키는 Node의 next포인터에 새 Node의 주소값을 저장
			pre->next = temp;
		}
	}
}

//display() - 연결 리스트의 노드 데이터를 순차적으로 출력하는 함수
void SingleLinkedList::display() {
	//현재 Node를 가리키는 포인터 p를 생성
	Node* p;
	//포인터 p가 첫번 째 Node를 가리키게 함
	p = head;

	//list가 비어있지 않을 경우
	if (!isEmpty()) {
		//p 포인터가 NULL이 아닐경우 반복문 실행
		while (p) {
			//p가 가리키고 있는 Node의 학생 정보를 출력
			cout << p->name << " " << p->ID << " " << p->major << " " << p->grade << endl;
			//p가 다음 Node를 가리키게 함
			p = p->next;
		}
	}
	//list가 비어있을 경우
	else {
		//list가 비어있음을 알리는 출력문
		cout << "List is empty!" << endl;
	}
}

//displayGradeA() - 특정 성적의 데이터를 가진 Node만 출력하는 함수
void SingleLinkedList::displayGradeA() {
	//현재 Node를 가리키는 포인터 p를 생성
	Node* p;

	//list가 비어있지 않을 경우
	if (!isEmpty()) {
		//포인터 p가 첫번 째 Node를 가리키게 함
		p = head;
		//포인터 p의 값이 NULL이 아닐 때 반복문 실행
		while (p != NULL) {
			//p가 가리키는 Node의 grade 값이 "A"와 같을 경우
			if (p->grade == 'A') {
				//p가 가리키고 있는 Node의 학생 정보를 출력
				cout << p->name << " " << p->ID << " " << p->major << " " << p->grade << endl;
			}
			//p가 다음 Node를 가리키게 함
			p = p->next;
		}
	}
	//list가 비어있을 경우
	else {
		//list가 비어있음을 알리는 출력문
		cout << "List is empty!" << endl;
	}
}

//displayMajorCS() - 특정 전공의 데이터를 가진 Node만 출력하는 함수
void SingleLinkedList::displayMajorCS() {
	//현재 Node를 가리키는 포인터 p를 생성
	Node* p;

	//list가 비어있지 않을 경우
	if (!isEmpty()) {
		//포인터 p가 첫번 째 Node를 가리키게 함
		p = head;
		//포인터 p의 값이 NULL이 아닐 때 반복문 실행
		while (p != NULL) {
			//p가 가리키는 Node의 major 값이 "CS"와 같을 경우
			if(!strcmp(p->major,"CS")) {
				//p가 가리키고 있는 Node의 학생 정보를 출력
				cout << p->name << " " << p->ID << " " << p->major << " " << p->grade << endl;
			}
			//p가 다음 Node를 가리키게 함
			p = p->next;
		}
	}
	//list가 비어있을 경우
	else {
		//list가 비어있음을 알리는 출력문
		cout << "List is empty!" << endl;
	}
}
#endif