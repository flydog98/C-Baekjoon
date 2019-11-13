// 2206번 벽 부수고 이동하기

#include <iostream>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

int main(void) {
	int row = 0, col = 0;
	static bool map[1000][1000]; // 지도를 저장
	static int move[1000][1000]; // 이동 횟수를 저장
	string temp;
	queue<int> rr; // row의 큐를 의미한다
	queue<int> cc; // column의 큐를 의미한다
	queue<bool> broken; // 벽을 부수고 이동했는지의 큐를 나타낸다
	// pair과 같은 방법으로 큐를 구성할지 그냥 큐를 두 개 구성할지 굉장히 고민이 된다

	memset(map, 0, sizeof(map));
	memset(move, 0, sizeof(move));

	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		temp = "";
		cin >> temp;
		for (int j = 0; j < col; j++) {
			map[i][j] = temp[j] - '0';
		}
	}

	move[0][0] = 1;
	rr.push(0);
	cc.push(0);
	broken.push(0);

	while (!rr.empty()) {
		int nowR = rr.front();
		int nowC = cc.front();
		bool isbroken = broken.front();
		rr.pop(); cc.pop(); broken.pop();
		int r[4] = { nowR - 1, nowR + 1, nowR, nowR };
		int c[4] = { nowC, nowC, nowC + 1, nowC - 1 };
		int i = 0;
		//i를 증가시키면서 r[i], c[i]를 통해 순서쌍을 나타내는데
		//과연 이게 가독성에 좋을 지는 모르겠다
		//다만 코드를 복붙하기엔 매우 편하다


		if (nowR > 0 && !move[r[i]][c[i]]) { // 왼쪽 이동 + 방문 여부 체크
			if (map[r[i]][c[i]]) { // 벽이 있는 경우
				if (!isbroken) { // 벽을 부순 적이 없는 경우
					rr.push(r[i]);
					cc.push(c[i]);
					broken.push(1); // 벽을 부쉈으므로 1
					move[r[i]][c[i]] = move[nowR][nowC] + 1;
				}
				// 벽을 부순 적이 있는 경우 통과
			}
			else { // 벽이 없는 경우
				rr.push(r[i]);
				cc.push(c[i]);
				if (!isbroken) { // 벽을 부순 적이 없는 경우
					broken.push(0); // 벽을 부순 적 없으므로 0
				}
				else {
					broken.push(1); // 벽을 부순 적 있으므로 1
				}
				move[r[i]][c[i]] = move[nowR][nowC] + 1;
			}
		}
		
		i++;
		if (nowR < row && !move[r[i]][c[i]]) { // 오른쪽 이동 + 방문 여부 체크
			if (map[r[i]][c[i]]) { // 벽이 있는 경우
				if (!isbroken) { // 벽을 부순 적이 없는 경우
					rr.push(r[i]);
					cc.push(c[i]);
					broken.push(1); // 벽을 부쉈으므로 1
					move[r[i]][c[i]] = move[nowR][nowC] + 1;
				}
				// 벽을 부순 적이 있는 경우 통과
			}
			else { // 벽이 없는 경우
				rr.push(r[i]);
				cc.push(c[i]);
				if (!isbroken) { // 벽을 부순 적이 없는 경우
					broken.push(0); // 벽을 부순 적 없으므로 0
				}
				else {
					broken.push(1); // 벽을 부순 적 있으므로 1
				}
				move[r[i]][c[i]] = move[nowR][nowC] + 1;
			}
		}

		i++;
		if (nowC < col - 1 && !move[r[i]][c[i]]) { // (입력 기준)아래쪽 이동 + 방문 여부 체크
			if (map[r[i]][c[i]]) { // 벽이 있는 경우
				if (!isbroken) { // 벽을 부순 적이 없는 경우
					rr.push(r[i]);
					cc.push(c[i]);
					broken.push(1); // 벽을 부쉈으므로 1
					move[r[i]][c[i]] = move[nowR][nowC] + 1;
				}
				// 벽을 부순 적이 있는 경우 통과
			}
			else { // 벽이 없는 경우
				rr.push(r[i]);
				cc.push(c[i]);
				if (!isbroken) { // 벽을 부순 적이 없는 경우
					broken.push(0); // 벽을 부순 적 없으므로 0
				}
				else {
					broken.push(1); // 벽을 부순 적 있으므로 1
				}
				move[r[i]][c[i]] = move[nowR][nowC] + 1;
			}
		}

		i++;
		if (nowC > 0 && !move[r[i]][c[i]]) { // (입력 기준)위쪽 이동 + 방문 여부 체크
			if (map[r[i]][c[i]]) { // 벽이 있는 경우
				if (!isbroken) { // 벽을 부순 적이 없는 경우
					rr.push(r[i]);
					cc.push(c[i]);
					broken.push(1); // 벽을 부쉈으므로 1
					move[r[i]][c[i]] = move[nowR][nowC] + 1;
				}
				// 벽을 부순 적이 있는 경우 통과
			}
			else { // 벽이 없는 경우
				rr.push(r[i]);
				cc.push(c[i]);
				if (!isbroken) { // 벽을 부순 적이 없는 경우
					broken.push(0); // 벽을 부순 적 없으므로 0
				}
				else {
					broken.push(1); // 벽을 부순 적 있으므로 1
				}
				move[r[i]][c[i]] = move[nowR][nowC] + 1;
			}
		}

	}

	int result = move[row - 1][col - 1];
	if (result) cout << result << endl;
	else cout << -1 << endl;

	return 0;
}