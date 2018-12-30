
/*********************************************************
* Name: 이다은
* Student ID : 20171661
* Program ID : Hw#1
* Description: 갈 수 있는 길 0과 갈 수 없는 길 1으로 구성된 
			   미로에서 탈출하고 탈출 경로 나타내기
* Algorithm : maze배열은 주어진 문제대로 정의하고 mark는 maze와 같은 크기의
			  모든 원소가 0으로 초기화된 배열이다.
			  1.시작점인 maze[1][1]의 좌표와 동쪽(E)의 방향을 stack에 push
			  2. 출구좌표 지정
			  3. 'stack에 저장값이 있고 탈출을 성공하지 못했을때 실행한다'를 반복
			  4. 위 반복문을 나오면 "탈출경로가 없음" 출력
			  5. 방향이 0(북) 부터 시작하여 7번 이하까지, 탈출을 못했다면 실행한다'을 반복
			  6. 위 반복문을 나오면 stack에서 pop하여 현재위치로 지정
			  7. 현위치와 이동값을 이용하여 다음위치를 구함
			  8. 출구좌표에 도착하면 mark 배열 출력
			  9. 새로운 0인 길에 도착했다면 mark배열에서 그 좌표의 값을 1로 바꾸고 현재위치를 push
			  10.새로 이동한 위치를 현재 위치에 저장
			  11.새로 이동했다면 방향 0으로 재정의, 길이 없었다면 방향 1증가
*
* Variables :
* struct offset _ 좌표의 이동거리을 나타내는 구조체
* struct element _ 현, 이동할 좌표 위치를 나타내는 구조체
* class Stack _ 스택 클래스(push 저장, pop 삭제, isEmpty 비어있나 확인, isFull 꽉 찼나 확인, display 출력)
* ROW - 행의 크기를 상수화
* COL - 열의 크기를 상수화
* Offset moveTo[8] - 인덱스에 따라 가르치는 방향이 다르고 크기가 8인 좌표이동를 나타낸 구조체 offset 배열
* maze[ROW + 2][COL + 2] - 미로의 구조를 나타낸 배열
* mark[ROW + 2][COL + 2] - 지나간 경로를 기록해주는 배열
* findMaze()_경로를 찾아 미로를 탈출하는 함수
* found - 탈출 성공의 여부를 나타냄
* Exit_row - 탈출위치의 행을 나타냄
* Exit_col - 탈출위치의 열을 나타냄
* Stack s - 스택 생성자 s
* Element now - 현재위치의 좌표와 이동 방향을 나타냄
    now.row - maze, mark 2차원 배열에서 현위치의 행값
	now.col - maze, mark 2차원 배열에서 현위치의 열값
	now.dir - now 구조체의 방향을 정수화해서 나타냄
* Element next - 이동할 좌표와 이동 방향을 나타냄
**********************************************************/

#ifndef MAZE_CPP
#define MAZE_CPP

#include "hw1_maze.h" //hw1_maze 헤더파일을 불러온다

const int ROW = 12; //ROW - 행의 크기를 14로 상수화 한다
const int COL = 15; //COL - 열의 크기를 17로 상수화 한다

void findMaze(); //미로를 찾는 findMaze함수를 선언한다

Offset moveTo[8]; //좌표이동 구조체 offset을 크기가 8인 배열로 생성한다

//미로의 구조를 나타낸 maze 배열을 선언한다.
//0: 지나갈 수 있는 위치, 1: 지나갈 수 없는 위치
/*기존 maze데이터를 1로 padding 해주는 이유:
어느 위치에서나 8방향 모두를 인접하고있지 않고 있어 현재 위치가
가장자리에 있을 때의 경우를 따로 조건화 하지 않으려 하기 때문 */
int maze[ROW + 2][COL + 2] = {
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1 },
	{ 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1 },
	{ 1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1 },
	{ 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0 ,0, 1 },
	{ 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1 },
	{ 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1 },
	{ 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1 },
	{ 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1 },
	{ 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
};

//지나간 지점을 기록해주는 배열
//같은 경로를 중복에서 가지 않게 하는 배열이다 
int mark[ROW + 2][COL + 2] = {
	0,
};

//main 함수
int main(void) {

	findMaze();

	return 0;
}

/**********************************************************
* function: findMaze()의 사용목적은 경로를 찾아 미로를 탈출하는 함수
* variables :
* found - 탈출 성공의 여부를 나타냄
* Exit_row - 탈출위치의 행을 나타냄
* Exit_col - 탈출위치의 열을 나타냄
* Stack s - 스택 생성자 s
* Element now - 현재위치의 좌표와 이동 방향을 나타냄
  now.row - maze, mark 2차원 배열에서 현위치의 행값
  now.col - maze, mark 2차원 배열에서 현위치의 열값
  now.dir - now 구조체의 방향을 정수화해서 나타냄
* Element next - 이동할 좌표와 이동 방향을 나타냄
**********************************************************/
void findMaze() {
	bool found = false; //found - 탈출 성공의 여부를 나타낸다
	int Exit_row = 12; // Exit_row - 탈출위치의 행을 나타낸다
	int Exit_col = 15; // Exit_col - 탈출위치의 열을 나타낸다
	Stack s; //스택 생성자 s 생성
	Stack s2;
	Element now; //현재위치의 좌표와 이동 방향을 나타내는 Element의 구조체 now
	Element next; //이동할 좌표와 이동 방향을 나타내는 Element의 구조체 next
	Element temp;

	//인덱스에 따라 이동값이 다르게 설정 된 Offset형 moveTo배열 정의
	moveTo[0].vert = -1; moveTo[0].horiz = 0; //N(북)
	moveTo[1].vert = -1; moveTo[1].horiz = 1; //NE(북동)
	moveTo[2].vert = 0;  moveTo[2].horiz = 1; //E(동)
	moveTo[3].vert = 1;  moveTo[3].horiz = 1; //SE(남동)
	moveTo[4].vert = 1;  moveTo[4].horiz = 0; //S(남)
	moveTo[5].vert = 1;  moveTo[5].horiz = -1; //SW(남서)
	moveTo[6].vert = 0;  moveTo[6].horiz = -1; //W(서)
	moveTo[7].vert = -1; moveTo[7].horiz = -1; //NW(북서)

	mark[1][1] = 1; //시작점을 알린다
	now.row = 1; //now.row - maze, mark 2차원 배열에서 현위치의 행값 초기화
	now.col = 1; //now.col - maze, mark 2차원 배열에서 현위치의 열값 초기화
	now.dir = 2; //now.dir - now 구조체의 방향을 정수화해서 나타낸다

	//첫번째 위치를 stack에 저장
	s.push(now);
	//'stack에 저장값이 있고 탈출을 성공하지 못했을때 실행한다'를 반복
	while (!s.isEmpty() && !found) {
		//stack에서 되돌아갈 위치를 pop한다
		//stack의 top에는 항상 직전위치가 들어가있다
		now = s.pop();  
		//'방향이 0(북) 부터 시작하여 7번 이하까지, 탈출을 못했다면 실행한다'을 반복
		while (now.dir < 8 && !found) {
			//현위치 + 이동값으로 다음 위치를 저장한다
			next.row = now.row + moveTo[now.dir].vert;
			next.col = now.col + moveTo[now.dir].horiz;

			//현재 위치가 출구라면
			if ((next.row == Exit_row) && (next.col == Exit_col)) {
				found = true; //탈출 성공
				//현재 위치를 방문했다고 marking 한다
				mark[next.row][next.col] = 1;
				
				//미로 탈출 경로를 출력한다
				cout << "<row><col> <dir>" << endl;
				s2.display();
				cout << "<MARK>" << endl;
				for (int i = 0; i < ROW; i++) {
					for (int j = 0; j < COL; j++) {
						cout << mark[i][j] << " ";
					}
					cout << endl;
				}
				return;
			}
			//다음 이동 위치에 도착했고, 처음와본 경로일 때 
			if ((!maze[next.row][next.col]) && (!mark[next.row][next.col])) {
				//현재 위치를 방문했다고 marking 한다
				mark[next.row][next.col] = 1;
				
				temp.row = now.row;
				temp.col = now.col;
				temp.dir = now.dir;
				s2.push(temp);
				/*이 위치로 다시 돌아올 시, 시도했던 방향의 연속된 다음방향으로 
				경로를 확인하기 위함이다 */
				now.dir += 1;
				s.push(now); //현재위치를 stack에 push한다
				//이동한 위치를 현재 위치라고 재정의한다
				now.row = next.row;
				now.col = next.col;
				now.dir = 0; 
			}
			else
				//탈출지점에 도착하지 않았거나, 가리키는 방향이 1인 지역이면 다음방향 지정
				now.dir++;
		}
	}
	//stack에 저장값이 없거나 탈출을 성공하지 못했을때 실행한다
	//갈 수 있는 경로가 없어 자신이 온 길로 끝까지 되돌아 간 상태
	cout << "no path in maze" << endl;
	return;
}


#endif