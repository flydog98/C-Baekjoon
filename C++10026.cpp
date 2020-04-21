//10026번 적록색약

#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int main(void) {
	int sizee = 0;
	int normal_amount = 0, cweak_amount = 0; // 정답을 저장하는 변수
	char temp = '0';
	pair<int, int> loctemp;
	char map[100][100]; // 색상들이 저장된다
	int normal[100][100]; // 일반 사람들의 입장
	int cweak[100][100]; // color weakness
	queue<pair<int, int>> q;

	memset(map, 0, sizeof(map));
	memset(normal, 0, sizeof(normal));
	memset(cweak, 0, sizeof(cweak));

	cin >> sizee;

	for (int i = 0; i < sizee; i++) {
		for (int j = 0; j < sizee; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < sizee; i++) {
		for (int j = 0; j < sizee; j++) {
			if (!normal[i][j]) { // 방문되지 않은 경우에만 (방문된 경우 0이 아닌 수가 저장된다)
				temp = map[i][j]; // 이번에 체크할 구역의 종류를 저장
				normal_amount++; // count된 구역의 수가 증가
				loctemp = make_pair(i, j);
				normal[i][j] = normal_amount;

				q.push(loctemp);
				while (!q.empty()) { // bfs를 진행한다
					int y = q.front().first;
					int x = q.front().second;
					q.pop();
					

					if (x > 0 && map[y][x - 1] == temp && !normal[y][x - 1]) {
						normal[y][x - 1] = normal_amount;
						loctemp = make_pair(y, x - 1);
						q.push(loctemp);
					}
					if (x < (sizee - 1) && map[y][x + 1] == temp && !normal[y][x + 1]) {
						normal[y][x + 1] = normal_amount;
						loctemp = make_pair(y, x + 1);
						q.push(loctemp);
					}
					if (y > 0 && map[y - 1][x] == temp && !normal[y - 1][x]) {
						normal[y - 1][x] = normal_amount;
						loctemp = make_pair(y - 1, x);
						q.push(loctemp);
					}
					if (y < (sizee - 1) && map[y + 1][x] == temp && !normal[y + 1][x]) {
						normal[y + 1][x] = normal_amount;
						loctemp = make_pair(y + 1, x);
						q.push(loctemp);
					}
				}

			}
		}
	}

	//적녹색약에 맞게 맵을 변경
	for (int i = 0; i < sizee; i++) {
		for (int j = 0; j < sizee; j++) {
			if (map[i][j] == 'R') map[i][j] = 'G';
		}
	}

	//변수 이름들만 수정한 뒤 복붙했습니다.
	for (int i = 0; i < sizee; i++) {
		for (int j = 0; j < sizee; j++) {
			if (!cweak[i][j]) { // 방문되지 않은 경우에만 (방문된 경우 0이 아닌 수가 저장된다)
				temp = map[i][j]; // 이번에 체크할 구역의 종류를 저장
				cweak_amount++; // count된 구역의 수가 증가
				loctemp = make_pair(i, j);
				normal[i][j] = cweak_amount;

				q.push(loctemp);
				while (!q.empty()) { // bfs를 진행한다
					int y = q.front().first;
					int x = q.front().second;
					q.pop();

					if (x > 0 && map[y][x - 1] == temp && !cweak[y][x - 1]) {
						cweak[y][x - 1] = cweak_amount;
						loctemp = make_pair(y, x - 1);
						q.push(loctemp);
					}
					if (x < (sizee - 1) && map[y][x + 1] == temp && !cweak[y][x + 1]) {
						cweak[y][x + 1] = cweak_amount;
						loctemp = make_pair(y, x + 1);
						q.push(loctemp);
					}
					if (y > 0 && map[y - 1][x] == temp && !cweak[y - 1][x]) {
						cweak[y - 1][x] = cweak_amount;
						loctemp = make_pair(y - 1, x);
						q.push(loctemp);
					}
					if (y < (sizee - 1) && map[y + 1][x] == temp && !cweak[y + 1][x]) {
						cweak[y + 1][x] = cweak_amount;
						loctemp = make_pair(y + 1, x);
						q.push(loctemp);
					}
				}

			}
		}
	}

	cout << normal_amount << ' ' << cweak_amount << endl;

	return 0;
}