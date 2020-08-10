// 17143번 낚시왕

#include <iostream>

using namespace std;

class Shark {
public:
	int size;
	int dir; // 0 : 왼쪽, 1 : 오른쪽, 2 : 위쪽, 3 : 아래쪽
	int speed;

	Shark(int speed, int dir, int size) {
		this->speed = speed;
		this->dir = dir;
		this->size = size;
	}
};

pair<int, int> nextpoint(int a, int x, int d, int y) {
	int temp = x + y * d;
	int newdir = 1;
	if (temp < 0) {
		newdir = -1;
		temp = (-1) * temp;
		if (temp > a) {
			newdir = 1;
			temp = a - (temp - a);
		}
	}
	else if (temp > a) {
		newdir = -1;
		temp = a - (temp - a);
		if (temp < 0) {
			newdir = 1;
			temp = (-1) * temp;
		}
	}

	return make_pair(temp, newdir);
}


pair<int, int> nextloc(int r, int c, int nowr, int nowc, Shark* nowShark) { // 다음 위치를 pair로 리턴하고, shark 포인터를 이용해 방향을 직접 바꾼다
	int dir = nowShark->dir;
	int speed = nowShark->speed;
	pair<int, int> temp;
	if (dir == 0) {
		temp = nextpoint(c - 1, nowc, -1, speed);
		if (temp.second == -1) nowShark->dir = 1;
		return make_pair(nowr, temp.first);
	}
	else if (dir == 1) {
		temp = nextpoint(c - 1, nowc, 1, speed);
		if (temp.second == -1) nowShark->dir = 0;
		return make_pair(nowr, temp.first);
	}
	else if (dir == 2) {
		temp = nextpoint(r - 1, nowr, -1, speed);
		if (temp.second == -1) nowShark->dir = 3;
		return make_pair(temp.first, nowc);
	}
	else if (dir == 3) {
		temp = nextpoint(r - 1, nowr, 1, speed);
		if (temp.second == -1) nowShark->dir = 2;
		return make_pair(temp.first, nowc);
	}
}


int main(void) {
	int count = 0;
	int r = 0, c = 0, m = 0;
	int sr = 0, sc = 0, speed = 0, dir = 0, size = 0;
	static Shark* map[100][100][100];
	int mapping[5] = { 0, 2, 3, 1, 0 };

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			for (int k = 0; k < 100; k++) {
				map[i][j][k] = NULL;
			}
		}
	}

	cin >> r >> c >> m;

	for (int i = 0; i < m; i++) {
		cin >> sr >> sc >> speed >> dir >> size;
		if(dir == 0 || dir == 1)
			speed = speed % ((c - 1) * 2);
		else 
			speed = speed % ((r - 1) * 2);
		Shark* tempShark = new Shark(speed, mapping[dir], size);
		map[0][sr - 1][sc - 1] = tempShark;
	}

	for (int i = 0; i < c; i++) {
		//상어잡는 과정
		for (int j = 0; j < r; j++) {
			if (map[i][j][i] != NULL) {//i번째 시도의 y = j, x = i에 상어가 있을 때
				count += map[i][j][i]->size;
				map[i][j][i] = NULL; // 상어쥬금
				break;
			}
		}
		//상어 이동하는 과정
		if (i == c - 1) break; // 마지막 루프인 경우 상어 이동 안해도 됨
		for (int j = 0; j < r; j++) {
			for (int k = 0; k < c; k++) {
				if (map[i][j][k] != NULL) { // 이동해야 할 상어가 있는 경우
					Shark* nowShark = map[i][j][k];
					dir = map[i][j][k]->dir;
					speed = map[i][j][k]->speed;
					size = map[i][j][k]->size;

					pair<int, int> temp = nextloc(r, c, j, k, nowShark); // 상어의 방향은 이미 바뀌어 있음
					if (map[i + 1][temp.first][temp.second] != NULL) { // 이미 상어가 있음
						if (map[i + 1][temp.first][temp.second]->size < nowShark->size) { // 이번 상어의 사이즈가 더 큼
							map[i + 1][temp.first][temp.second] = nowShark;
						} // 더 작은 경우 이번 상어는 죽는다
					}
					else {
						map[i + 1][temp.first][temp.second] = nowShark;
					}

					/*귀찮아서...ㅠㅠ
					if (dir == 0) { // 왼쪽
						if (k - speed < 0) { // 방향전환
							if (map[i + 1][j][speed - k] == NULL) {
								map[i + 1][j][speed - k] = nowShark;
								nowShark->dir = 1;
							}
							else { // 이미 상어가 있음
								if (map[i + 1][j][speed - k]->size < size) { // 지금 상어가 더 큼
									map[i + 1][j][speed - k] = nowShark;
									nowShark->dir = 1;
								} // 더 작은 경우 지금 상어는 쥬금
							}
						}
						else { // 방향전환 안함
							if (map[i + 1][j][k - speed] == NULL) {
								map[i + 1][j][k - speed] = nowShark;
							}
							else { // 이미 상어가 있음
								if (map[i + 1][j][k - speed]->size < size) { // 지금 상어가 더 큼
									map[i + 1][j][k - speed] = nowShark;
								} // 더 작은 경우 지금 상어는 쥬금
							}
						}
					}
					else if (dir == 1) { // 오른쪽
						if (k + speed >= c) {// 방향전환
							if (map[i + 1][j][c - 1 - (speed + k - c)] == NULL) {
								map[i + 1][j][c - 1 - (speed + k - c)] = nowShark;
								nowShark->dir = 0;
							}
							else { // 이미 상어가 있음
								if (map[i + 1][j][c - 1 - (speed + k - c)]->size < size) { // 지금 상어가 더 큼
									map[i + 1][j][c - 1 - (speed + k - c)] = nowShark;
									nowShark->dir = 0;
								} // 더 작은 경우 지금 상어는 쥬금
							}
						}
						else { // 방향전환 안함
							if (map[i + 1][j][k + speed] == NULL) {
								map[i + 1][j][k + speed] = nowShark;
							}
							else { // 이미 상어가 있음
								if (map[i + 1][j][k + speed]->size < size) { // 지금 상어가 더 큼
									map[i + 1][j][k + speed] = nowShark;
								} // 더 작은 경우 지금 상어는 쥬금
							}
						}
					}
					else if (dir == 2) { // 위쪽
						if (j - speed < 0) { // 방향전환
							if (map[i + 1][speed - j][k] == NULL) {
								map[i + 1][speed - j][k] = nowShark;
								nowShark->dir = 3;
							}
							else { // 이미 상어가 있음
								if (map[i + 1][speed - j][k]->size < size) { // 지금 상어가 더 큼
									map[i + 1][speed - j][k] = nowShark;
									nowShark->dir = 3;
								} // 더 작은 경우 지금 상어는 쥬금
							}
						}
						else { // 방향전환 안함
							if (map[i + 1][j - speed][k] == NULL) {
								map[i + 1][j - speed][k] = nowShark;
							}
							else { // 이미 상어가 있음
								if (map[i + 1][j - speed][k]->size < size) { // 지금 상어가 더 큼
									map[i + 1][j - speed][k] = nowShark;
								} // 더 작은 경우 지금 상어는 쥬금
							}
						}
					}
					else if (dir == 3) { // 아래쪽
						if (j + speed >= r) { // 방향전환
							if (map[i + 1][r - 1 - (speed + j - r)][k] == NULL) {
								map[i + 1][r - 1 - (speed + j - r)][k] = nowShark;
								nowShark->dir = 2;
							}
							else { // 이미 상어가 있음
								if (map[i + 1][r - 1 - (speed + j - r)][k]->size < size) { // 지금 상어가 더 큼
									map[i + 1][r - 1 - (speed + j - r)][k] = nowShark;
									nowShark->dir = 2;
								} // 더 작은 경우 지금 상어는 쥬금
							}
						}
						else { // 방향전환 안함
							if (map[i + 1][j + speed][k] == NULL) {
								map[i + 1][j + speed][k] = nowShark;
							}
							else { // 이미 상어가 있음
								if (map[i + 1][j + speed][k]->size < size) { // 지금 상어가 더 큼
									map[i + 1][j + speed][k] = nowShark;
								} // 더 작은 경우 지금 상어는 쥬금
							}
						}
					} // end of elseif */

				} // 이번 상어 이동 끝

			}
		} // r, c를 도는 루프


	}

	cout << count << '\n';

	return 0;
}