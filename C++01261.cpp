// 1261번 알고스팟

#include <iostream>
#include <string>
#include <cstring>
#include <deque>
#include <utility>

using namespace std;

int main(void) {
	int row = 0, col = 0;
	int map[100][100]; // 0과 1을 저장하는 지도
	int move[100][100]; // 지도의 해당 좌표의 이동횟수를 저장하는 곳
	char check[100][100]; // 방문 여부를 저장하는 배열
	memset(move, 2, sizeof(move));
	memset(check, 0, sizeof(check));
	deque<pair<int, int>> dq;

	cin >> col >> row;
	for (int i = 0; i < row; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < col; j++) {
			map[i][j] = temp[j] - '0';
		}
	}

	move[0][0] = 0;
	check[0][0] = true;
	pair<int, int> temp = make_pair(0, 0);
	dq.push_back(temp);

	while (!dq.empty() && !check[row - 1][col - 1]) {
		//deque를 이용해, 빈 공간일 경우 앞쪽에 push, 벽일 경우 뒤쪽에 push한다
		//다른 BFS처럼 처리되는 좌표의 이동 횟수를 순서대로 나열하면 000...0 111...1 222...2
		//이런식으로 증가하는 방향으로 처리된다.
		pair<int, int> now = dq.front();
		dq.pop_front();
		int nowmove = move[now.first][now.second];
		int x[4] = { now.first - 1, now.first + 1, now.first, now.first};
		int y[4] = { now.second, now.second, now.second + 1, now.second - 1 };

		int i = 0;

		if (x[i] >= 0) { // 왼쪽 이동하는 경우
			if (!check[x[i]][y[i]]) { // 이전 방문 여부 체크
				check[x[i]][y[i]] = true;
				pair<int, int> ttemp = make_pair(x[i], y[i]);
				if (map[x[i]][y[i]]) { // 벽이 있는 경우
					move[x[i]][y[i]] = nowmove + 1;
					dq.push_back(ttemp);
				}
				else { // 벽이 없는 경우
					move[x[i]][y[i]] = nowmove;
					dq.push_front(ttemp);
				}
			}
		}

		i++;
		if (x[i] < row) { // 오른쪽 이동하는 경우
			if (!check[x[i]][y[i]]) { // 이전 방문 여부 체크
				check[x[i]][y[i]] = true;
				pair<int, int> ttemp = make_pair(x[i], y[i]);
				if (map[x[i]][y[i]]) { // 벽이 있는 경우
					move[x[i]][y[i]] = nowmove + 1;
					dq.push_back(ttemp);
				}
				else { // 벽이 없는 경우
					move[x[i]][y[i]] = nowmove;
					dq.push_front(ttemp);
				}
			}
		}

		i++;
		if (y[i] < col) { // 위로 이동하는 경우
			if (!check[x[i]][y[i]]) { // 이전 방문 여부 체크
				check[x[i]][y[i]] = true;
				pair<int, int> ttemp = make_pair(x[i], y[i]);
				if (map[x[i]][y[i]]) { // 벽이 있는 경우
					move[x[i]][y[i]] = nowmove + 1;
					dq.push_back(ttemp);
				}
				else { // 벽이 없는 경우
					move[x[i]][y[i]] = nowmove;
					dq.push_front(ttemp);
				}
			}
		}

		i++;
		if (y[i] >= 0) { // 아래로 이동하는 경우
			if (!check[x[i]][y[i]]) { // 이전 방문 여부 체크
				check[x[i]][y[i]] = true;
				pair<int, int> ttemp = make_pair(x[i], y[i]);
				if (map[x[i]][y[i]]) { // 벽이 있는 경우
					move[x[i]][y[i]] = nowmove + 1;
					dq.push_back(ttemp);
				}
				else { // 벽이 없는 경우
					move[x[i]][y[i]] = nowmove;
					dq.push_front(ttemp);
				}
			}
		}


	}

	cout << move[row - 1][col - 1] << endl;

	return 0;
}