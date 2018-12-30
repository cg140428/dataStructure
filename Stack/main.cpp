#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(void) {
	FILE* f;
	f = fopen("input.txt", "r");

	int turn;
	fscanf(f, "%d", &turn);

	while (turn--) {
		int element;
		int remainder;
		int oneCount = 0;
		fscanf(f, "%d", &element);
		while(element == 0){
			if (element % 2)
				oneCount++;
			element /= 2;
		}

		double parityBitNum = 0;
		if (oneCount % 2) {
			//1�� ������ Ȧ���� ��
			element += pow(2, 32);
			cout << element << endl;
		}
		//1�� ������ ¦���� ��
		else {
			cout << element << endl;
		}
	}
	return 0;
}