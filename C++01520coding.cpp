#include <iostream>

using namespace std;

int row = 0, column = 0;

int main(void) {
	int map[500][500];
	int route[500][500];
	int truefalse[500][500];
	cin >> row >> column;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			cin >> map[i][j];
			route[i][j] = 0;
			truefalse[i][j] = false;
		}
	}
	for (int i = 0; i < row; i++) {
		//각 칸별로 방문 가능 여부를 체크
		//사방의 높이 중 자신보다 낮은 곳이 있으면
		//일단 true가 된다
		for (int j = 0; j < column; j++) {
			if (i == 0 && j == 0) {
				truefalse[i][j] = true;//map[0][0]일 경우는 무조건 방문이 가능하다
				continue;
			}
				int temp = map[i][j];
			if (i != 0) {//맨 위일 때를 배제
				if (temp < map[i - 1][j]) {//만약 위쪽이 더 크면
					truefalse[i][j] = true;
					continue;
				}
			}
			if (j != 0) {//왼쪽 끝일 때를 배제
				if (temp < map[i][j - 1]) {//만약 왼쪽이 더 크면
					truefalse[i][j] = true;
					continue;
				}
			}
			if (i < row - 1) {//맨 아래쪽일 때를 배제
				if (temp < map[i + 1][j]) {//만약 아래쪽이 더 크면
					truefalse[i][j] = true;
					continue;
				}
			}
			if (j < column - 1) {//맨 오른쪽일 때를 배제
				if (temp < map[i][j + 1]) {//만약 오른쪽이 더 크면
					truefalse[i][j] = true;
					continue;
				}
			}
		}
	}
	//주변 칸과의 연계로 방문 가능 여부를 체크
	//관련 함수를 만들어 재귀적으로 해결?
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			if (truefalse[i][j]) continue;
			//방문 가능한 경우 일단 스킵
			


			//방문 불가능한 경우,
			//주변 4칸을 돌며 오직 방문 불가능한 칸만이
			//주변 4칸 각각보다 크다면,
			//그 칸도 불가능하게 만든다
		}
	}

	truefalse[0][0] = true;//혹시 몰라서 다시 한 번
	




	return 0;
}

bool checking(int* map[500][500], bool* truefalse[500][500], int i, int j) {
	//주변 4개와 비교해서 자신보다 높은 값을 가진 칸이 모두
	//false일 경우 false를 리턴하는 함수,
	//만약 자신의 truefalse가 false라면,
	//주변 4칸에 재귀적으로 작동한다.
	int temp = *map[i][j];
	//자신이 정말 true인지 검증하는 과정
	if (i != 0 && truefalse[i - 1][j]) {
		if (temp < *map[i - 1][j] && *truefalse[i - 1][j]) {
			return true;
		}
	}
	if (j != 0 && truefalse[i][j - 1]) {
		if (temp < *map[i][j - 1] && *truefalse[i][j - 1]) {
			return true;
		}
	}
	if (i != row - 1 && truefalse[i + 1][j]) {
		if (temp < *map[i + 1][j] && *truefalse[i + 1][j]) {
			return true;
		}
	}
	if (j != column - 1 && truefalse[i][j + 1]) {
		if (temp < *map[i][j + 1] && *truefalse[i][j + 1]) {
			return true;
		}
	}

	*truefalse[i][j] = false;
	if (!*truefalse[i][j]) {//재귀 발동
		if (i != 0) checking(map, truefalse, i - 1, j);
		if (j != 0) checking(map, truefalse, i, j - 1);
		if (i != row - 1) checking(map, truefalse, i + 1, j);
		if (j != column - 1) checking(map, truefalse, i, j + 1);
	}

	return false;
}