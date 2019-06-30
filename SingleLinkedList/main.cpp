/************************************************************************
*Name: 이다은
*Student ID: 20171661
*Program ID: HW2_SinglyLinkedList
*Description: 단순 연결 리스트를 사용하여 데이터를 저장
			  -특정 데이터(학생의 이름)의 오름차순으로 리스트에 생성
			  -특정 데이터(학생의 성적)의 값을 선별하여 리스트에서 출력
			  -각각 파일의 데이터를 한 리스트에 저장하고 
			   특정 데이터(학생의 전공)의 값을 선별하여 리스트에서 출력

*Algorithm: -data1.txt과 data2.txt 파일에는 각각 다른 학생 이름, 학번, 전공, 성적이 저장되어있다.
			-문제1) data1 파일을 읽어서 학생 이름(name)의 알파벳 오름차순으로 리스트를 만들어서 출력
			-리스트 저장(insert())과 동시에 학생 이름의 오름차순으로 정렬한다.
			  -현재 Node를 가리키는 포인터 now와 그의 선행 포인터 pre를 생성한다.
			  -현재 now포인터가 가리키고있는 Node의 name 값 보다 새 Node의 name 값이 크면 (now->name < temp->data) pre포인터와 now포인터 사이에 새 Node를 정렬한다  
			  -insert 경우 1(리스트가 비었을 경우): head 포인터에 추가할 Node의 주소를 저장한다.
			  -insert 경우 2(새 Node가 첫번째 Node 앞에 정렬될 경우): 추가할 Node의 next포인터 첫번째 Node의 주소를 저장하고 head포인터가 새로운 Node를 가리키게 한다.
			  -insert 경우 3(새 Node가 중간에 정렬될 경우): pre포인터와 now포인터 사이에 새 Node를 정렬한다 추가할 Node의 next포인터에 now의 값을 저장하고, now 선행 포인터인 pre가 가리키는 Node의 next포인터에 추가할 Node의 주소값을 저장한다.
			  -intset 경우 4(새 Node가 제일 끝 쪽에 정렬될 경우): 추가할 Node의 next포인터에 NULL을 저장한다. pre포인터가 가리키는 Node의 next포인터에 새 Node의 주소값을 저장한다.
			-리스트를 순차적으로 출력한다.
			  -현재 Node를 가리키는 포인터 p를 생성한다.
			  -포인터p가 가리키는 Node의 데이터들을 출력하고 p에 현재 Node의 다음 Node 주소값을 저장한다
			  -위 내용을 포인터 p가 NULL을 가리킬 때 까지 반복한다.
			-문제2) 1)에서 만든 list에서 Grade "A" 성적을 받은 사람만 출력
			-list를 순차적으로 가리키는 포인터를 사용하여 Node의 grade 값이 "A"인지 비교하고, 같으면 출력한다
			  -현재 Node를 가리키는 포인터 p를 생성한다.
			  -포인터 p가 가리키는 Node의 grade 값이 'A'와 같은지 비교한다.
			  -"A"와 같으면 현재 Node의 데이터를 출력한다.
			  -"A"와 다르면 다음 Node로 넘어간다(p = p->next)
			-문제3) "data2"파일과 "data1"을 합쳐서 하나의 리스트로 만들고, 그 중 CS전공 학생들만 출력
			-앞서 만든 list에 "data2" 파일의 정보를 insert함수를 사용하여 추가시켜준다.
			-list를 순차적으로 가리키는 포인터를 사용하여 Node의 major 값이 "CS"인지 비교하고, 같으면 출력한다
			  -현재 Node를 가리키는 포인터 p를 생성한다.
			  -포인터 p가 가리키는 Node의 major 값이 "CS"와 같은지 비교한다.
			  -"CS"와 같으면 현재 Node의 데이터를 출려한다.
			  -"CS"와 다르면 현재 다음 Node로 넘어간다(p = p->next)
*Variables: 
*alphabetSortList: SingleLinkedList class의 객체
*newStudent: Student의 구조체
 -newStudent.name: 파일에서 받은 학생 이름
 -newStudent.ID: 파일에서 받은 학생 학번
 -newStudent.major: 파일에서 받은 학생 전공
 -newStudent.grade: 파일에서 받은 학생 성적
*head: 첫번 째 Node를 가리키는 포인터
*next: 다음 Node를 가리키는 포인터
*temp: 새 Node를 가리키는 포인터
*now: 현재 Node를 가리키는 포인터
*pre: now의 선행 Node를 가리키는 포인터

*Function:
*isEmpty(): 연결 리스트가 비었는지 검사하는 함수
*insert(Student newStudent): 연결 리스트에 노드를 이름 오름차순으로 삽입하는 함수
*display(): 연결 리스트의 노드 데이터를 순차적으로 출력하는 함수
*displayGradeA(): 특정 성적의 데이터를 가진 Node만 출력하는 함수
*displayMajorCS():  특정 전공의 데이터를 가진 Node만 출력하는 함수

*/

#ifndef MAIN_CPP
#define MAIN_CPP
#include "SingleLinkedList.h"

int main(void) {
	FILE* f;
	f = fopen("data1.txt", "r");

	//SingleLinkedList class의 alphabetSortList객체 생성
	SingleLinkedList alphabetSortList;
	//newStudent 구조체 생성
	struct Student newStudent;

	//파일이 끝날 때 까지 반복문 실행
	while (!feof(f)) {
		//파일에서 학생 이름, 학번, 전공, 성적을 받아 구조체 멤버변수에 저장
		fscanf(f, "%c %d %s %c\n", &newStudent.name, &newStudent.ID, newStudent.major, &newStudent.grade);

		//alphabetSortList 리스트에 추가, 동시에 이름 오름차순 정렬
		alphabetSortList.insert(newStudent);
	}
	
	cout << "문제 1)" << endl;
	//alphabetSortList 리스트의 모든 정보를 순차적 출력
	alphabetSortList.display();

	fclose(f);

	cout << "문제 2)" << endl;
	//alphabetSortList 리스트에서 grade가 A인 학생의 정보만 출력
	alphabetSortList.displayGradeA();

	

	FILE* f2;
	f2 = fopen("data2.txt", "r");

	while (!feof(f2)) {
		//파일에서 학생 이름, 학번, 전공, 성적을 받아 구조체 멤버변수에 저장
		fscanf(f2, "%c %d %s %c\n", &newStudent.name, &newStudent.ID, newStudent.major, &newStudent.grade);

		//alphabetSortList 리스트에 추가, 동시에 이름 오름차순 정렬
		alphabetSortList.insert(newStudent);
	}
	
	cout << "문제 3)" << endl;
	//alphabetSortList 리스트에서 major가 CS인 학생의 정보만 출력
	alphabetSortList.displayMajorCS();

	return 0;
}
#endif