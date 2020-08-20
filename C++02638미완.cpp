// 2638�� ġ��

#include <iostream>
#include <queue>

using namespace std;

void bfs(int map[][100], int startx, int starty, int to, int n, int m) {
	int target = map[starty][startx];
	queue<pair<int, int>> q;

	q.push(make_pair(startx, starty));

	while (!q.empty()) {
		int nowx = q.front().first;
		int nowy = q.front().second;
		q.pop();

		if (nowx > 0) {
			if (map[nowy][nowx - 1] == target) {
				map[nowy][nowx - 1] = to;
				q.push(make_pair(nowx - 1, nowy));
			}
		}
		if (nowx < m - 1) {
			if (map[nowy][nowx + 1] == target) {
				map[nowy][nowx + 1] = to;
				q.push(make_pair(nowx + 1, nowy));
			}
		}
		if (nowy > 0) {
			if (map[nowy - 1][nowx] == target) {
				map[nowy - 1][nowx] = to;
				q.push(make_pair(nowx, nowy - 1));
			}
		}
		if (nowy < n - 1) {
			if (map[nowy + 1][nowx] == target) {
				map[nowy + 1][nowx] = to;
				q.push(make_pair(nowx, nowy + 1));
			}
		}
	}
}

int del(int map[][100], int n, int m) {
	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 2) {
				ret = 1;
				map[i][j] = 3;
			}
		}
	}

	return ret;
}

void air(int map[][100], int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				bfs(map, j, i, 3, n, m);
			}
		}
	}
}

int check(int map[][100], int n, int m) {
	int temp = 0;
	int ret = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1) {
				ret = 1;
				temp = 0;
				if (map[i][j - 1] == 3) temp++;
				if (map[i][j + 1] == 3) temp++;
				if (map[i - 1][j] == 3) temp++;
				if (map[i + 1][j] == 3) temp++;
				if (temp > 1) map[i][j] = 2;
			}
		}
	}

	return ret;
}

int main(void) {
	int n = 0, m = 0;
	int count = 0, flag = 1;
	int map[100][100]; //  0: ���ʰ���, 1: ġ��, 2: ���� ġ��, 3: �ٱ�����
	queue<pair<int, int>> q1;
	queue<pair<int, int>> q2;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j]; // ó������ 0�� �ٱ������ӿ� ����
		}
	}

	bfs(map, 0, 0, 3, n, m);

	while (flag) {
		//ġ�� ����
		flag = del(map, n, m);
		if (flag) count++;
		//���� ���� �ܺ�ȭ
		air(map, n, m);
		//���ο� ���� ġ�� ����
		flag = check(map, n, m);
	}

	cout << count << '\n';

	return 0;
}