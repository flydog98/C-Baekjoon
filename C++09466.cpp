// 9466번 텀 프로젝트

#include <iostream>

using namespace std;

int main(void) {
	int tc = 0, amount = 0, temp, answer = 0;
	int list[100001][2]; 
	//0 : 방문된 적 없음
	//1 : 이미 팀임
	//2 : 팀이 될 수 없음
	//3 : 판단 중

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> tc;

	for (int i = 0; i < tc; i++) {
		answer = 0;
		cin >> amount;

		for (int j = 1; j < amount + 1; j++) {
			list[j][1] = 0;
		}
		for (int j = 1; j < amount + 1; j++) {
			cin >> temp;
			list[j][0] = temp;
		}

		for (int j = 1; j < amount + 1; j++) {
			if (!list[j][1]) { // 방문된 적 없을 때,
				int now = j;
				int next = list[j][0];
				int dfsnow = 0;

				while (1) {
					list[now][1] = 3;

					if (list[next][1] == 0) { // keep going
						now = next;
						next = list[next][0]; // next의 next가 새 next
					}
					else if (list[next][1] == 1 || list[next][1] == 2) { // can't
						dfsnow = j; // 시작점부터 dfs를 진행한다. 재귀의 수가 매우 많을 것으로 예상하므로 while로 구현해본다
						while (1) {
							list[dfsnow][1] = 2; // 팀이 될 수 없다.
							if (dfsnow == now) break;
							dfsnow = list[dfsnow][0]; // next
						}
						break; // 이번 탐색 종료
					}
					else { // 3: cycle이 만들어진 만큼 성공이다
						//현재 next에 들어 있는 값 부터 성공이다.
						dfsnow = j;
						int token = 2; // dfsnow가 next를 만나기 전까지 dfs는 실패를 입력
						while (1) {
							if (dfsnow == next)
								if(list[dfsnow][1] == 3)token = 1; // 이 경우부터 dfs는 성공이다
								else break; // 3이 아니라는 것은 루프를 돌았다는 것이므로 종료
							list[dfsnow][1] = token;
							dfsnow = list[dfsnow][0]; // next;
						}
						break; // 이번 탐색 종료
					} // end of if/else
				} // end of while
			} // end of if
		} // end of for

		for (int j = 1; j < amount + 1; j++) { // 전체 탐색으로 1의 수 찾기
			if (list[j][1] == 2) answer++;
		}

		cout << answer << '\n';
	}

	return 0;
}