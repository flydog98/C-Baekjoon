// 2239번 스도쿠

#include <iostream>

using namespace std;

void show(int map[][9]) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << map[i][j];
		}
		cout << '\n';
	}
}

void arr_copy(int to[][9], int from[][9]) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			to[i][j] = from[i][j];
		}
	}
}

int find_next(int map[][9], int* x, int* y) {
	int stack = 1;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (map[i][j] == 0 && stack == 1) {
				stack--;
			}
			else if (map[i][j] == 0 && stack == 0) {
				*x = j;
				*y = i;
				return 0; // 성공
			}
		}
	}
	return 1; // 실패 이 경우 이번 x, y가 마지막이다
}

int box_check(int map[][9], int x, int y, int val) {
	int startx = 0, starty = 0;
	if (x < 3) startx = 0;
	else if (x < 6) startx = 3;
	else startx = 6;
	if (y < 3) starty = 0;
	else if (y < 6) starty = 3;
	else starty = 6;

	for (int i = starty; i < starty + 3; i++) {
		for (int j = startx; j < startx + 3; j++) {
			if (map[i][j] == val) return 0;
		}
	}

	return 1;
}

int check(int map[][9], int x, int y, int val) {
	for (int i = 0; i < 9; i++) {
		if (map[i][x] == val) return 0;
	}
	for (int j = 0; j < 9; j++) {
		if (map[y][j] == val) return 0;
	}
	return box_check(map, x, y, val);
}

int dfs(int draw[][9], int nowx, int nowy) {
	int newdraw[9][9];
	int nextx = 0, nexty = 0;

	int islast = find_next(draw, &nextx, &nexty); // next가 없다면 마지막 좌표겠죠?
	int isSuccess = 0; // 미래의 dfs에서 성공하였는지

	arr_copy(newdraw, draw);
	for (int i = 1; i < 10; i++) {
		if (check(draw, nowx, nowy, i)) { // 만약 지정한 좌표가 안전한 경우
			newdraw[nowy][nowx] = i;
			if (islast) { // 문제풀이 성공
				draw[nowy][nowx] = i;
				show(draw);
				return 1;
			}
			else { // 다음 좌표로 dfs 이동
				isSuccess = dfs(newdraw, nextx, nexty);
				if (isSuccess == 1) { // 성공한 경우 성공 코드 리턴
					//draw[nowy][nowx] = i;
					//draw[nexty][nextx] = newdraw[nexty][nextx];
					return 1;
				} // 실패한 경우 draw를 건드리지 않았으므로 자연스럽게 넘어갈 수 있을 듯
			}
		}
	}

	return 0; // 모두 실패한 경우
}

int main(void) {
	int map[9][9];
	int draw[9][9];

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			char temp;
			scanf("%c", &temp);
			map[i][j] = temp - '0';
			draw[i][j] = temp - '0';
		}
		char tt;
		scanf("%c", &tt);
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (map[i][j] == 0) {
				dfs(draw, j, i);
				//show(draw);
				return 0;
			}
		}
	}


	return 0;
}