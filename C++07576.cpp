// 7576번 토마토

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main(void) {
	bool flag = false;
	int x = 0, y = 0; // 가로길이 x, 세로길이 y
	int temp = 0, tempx = 0, tempy = 0;
	int ans = 0;
	static int map[1000][1000];
	queue<pair<int, int>> que;
	pair<int, int> pairtemp;

	cin >> x >> y;

	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			cin >> temp;
			map[i][j] = temp; // map[y][x]
			if (temp == 1) que.push(make_pair(i, j));
		}
	}

	//*
	while (!que.empty()) {
		pairtemp = que.front();
		tempy = pairtemp.first;
		tempx = pairtemp.second;
		temp = map[tempy][tempx];

		if (tempy > 0 && !map[tempy - 1][tempx]) {
			map[tempy - 1][tempx] = temp + 1;
			pairtemp = make_pair(tempy - 1, tempx);
			que.push(pairtemp);
		}

		if (tempy < y - 1 && !map[tempy + 1][tempx]) {
			map[tempy + 1][tempx] = temp + 1;
			pairtemp = make_pair(tempy + 1, tempx);
			que.push(pairtemp);
		}

		if (tempx > 0 && !map[tempy][tempx - 1]) {
			map[tempy][tempx - 1] = temp + 1;
			pairtemp = make_pair(tempy, tempx - 1);
			que.push(pairtemp);
		}

		if (tempx < x - 1 && !map[tempy][tempx + 1]) {
			map[tempy][tempx + 1] = temp + 1;
			pairtemp = make_pair(tempy, tempx + 1);
			que.push(pairtemp);
		}

		que.pop();
	}
	//*/

	/*
	while (!que.empty()) {
		pairtemp = que.front();
		tempx = pairtemp.first;
		tempy = pairtemp.second;

		if (tempx > 0 && !map[tempy][tempx - 1]) {
			map[tempy][tempx - 1] = map[tempy][tempx] + 1;
			pairtemp = make_pair(tempy - 1, tempx);
			que.push(pairtemp);
		}
		if (tempx < x - 1 && !map[tempy][tempx + 1]) {
			map[tempy][tempx + 1] = map[tempy][tempx] + 1;
			pairtemp = make_pair(tempy, tempx + 1);
			que.push(pairtemp);
		}
		if (tempy > 0 && !map[tempy - 1][tempx]) {
			map[tempy - 1][tempx] = map[tempy][tempx] + 1;
			pairtemp = make_pair(tempy - 1, tempx);
			que.push(pairtemp);
		}
		if (tempy< y - 1 && !map[tempy + 1][tempx]) {
			map[tempy + 1][tempx] = map[tempy][tempx] + 1;
			pairtemp = make_pair(tempy + 1, tempx);
			que.push(pairtemp);
		}

		que.pop();
	}
	//*/

	for (int i = 0; i < y; i++) {
		if (flag) break;
		for (int j = 0; j < x; j++) {
			if (flag) break;
			temp = map[i][j];
			if (temp == 0) flag = true;
			ans = max(temp, ans);
		}
	}

	if (flag) cout << -1 << endl;
	else cout << ans - 1 << endl;

	return 0;
}