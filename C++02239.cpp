// 2239�� ������

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
				return 0; // ����
			}
		}
	}
	return 1; // ���� �� ��� �̹� x, y�� �������̴�
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

	int islast = find_next(draw, &nextx, &nexty); // next�� ���ٸ� ������ ��ǥ����?
	int isSuccess = 0; // �̷��� dfs���� �����Ͽ�����

	arr_copy(newdraw, draw);
	for (int i = 1; i < 10; i++) {
		if (check(draw, nowx, nowy, i)) { // ���� ������ ��ǥ�� ������ ���
			newdraw[nowy][nowx] = i;
			if (islast) { // ����Ǯ�� ����
				draw[nowy][nowx] = i;
				show(draw);
				return 1;
			}
			else { // ���� ��ǥ�� dfs �̵�
				isSuccess = dfs(newdraw, nextx, nexty);
				if (isSuccess == 1) { // ������ ��� ���� �ڵ� ����
					//draw[nowy][nowx] = i;
					//draw[nexty][nextx] = newdraw[nexty][nextx];
					return 1;
				} // ������ ��� draw�� �ǵ帮�� �ʾ����Ƿ� �ڿ������� �Ѿ �� ���� ��
			}
		}
	}

	return 0; // ��� ������ ���
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