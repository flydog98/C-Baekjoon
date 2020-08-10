// 17143�� ���ÿ�

#include <iostream>

using namespace std;

class Shark {
public:
	int size;
	int dir; // 0 : ����, 1 : ������, 2 : ����, 3 : �Ʒ���
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


pair<int, int> nextloc(int r, int c, int nowr, int nowc, Shark* nowShark) { // ���� ��ġ�� pair�� �����ϰ�, shark �����͸� �̿��� ������ ���� �ٲ۴�
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
		//������ ����
		for (int j = 0; j < r; j++) {
			if (map[i][j][i] != NULL) {//i��° �õ��� y = j, x = i�� �� ���� ��
				count += map[i][j][i]->size;
				map[i][j][i] = NULL; // ������
				break;
			}
		}
		//��� �̵��ϴ� ����
		if (i == c - 1) break; // ������ ������ ��� ��� �̵� ���ص� ��
		for (int j = 0; j < r; j++) {
			for (int k = 0; k < c; k++) {
				if (map[i][j][k] != NULL) { // �̵��ؾ� �� �� �ִ� ���
					Shark* nowShark = map[i][j][k];
					dir = map[i][j][k]->dir;
					speed = map[i][j][k]->speed;
					size = map[i][j][k]->size;

					pair<int, int> temp = nextloc(r, c, j, k, nowShark); // ����� ������ �̹� �ٲ�� ����
					if (map[i + 1][temp.first][temp.second] != NULL) { // �̹� �� ����
						if (map[i + 1][temp.first][temp.second]->size < nowShark->size) { // �̹� ����� ����� �� ŭ
							map[i + 1][temp.first][temp.second] = nowShark;
						} // �� ���� ��� �̹� ���� �״´�
					}
					else {
						map[i + 1][temp.first][temp.second] = nowShark;
					}

					/*�����Ƽ�...�Ф�
					if (dir == 0) { // ����
						if (k - speed < 0) { // ������ȯ
							if (map[i + 1][j][speed - k] == NULL) {
								map[i + 1][j][speed - k] = nowShark;
								nowShark->dir = 1;
							}
							else { // �̹� �� ����
								if (map[i + 1][j][speed - k]->size < size) { // ���� �� �� ŭ
									map[i + 1][j][speed - k] = nowShark;
									nowShark->dir = 1;
								} // �� ���� ��� ���� ���� ���
							}
						}
						else { // ������ȯ ����
							if (map[i + 1][j][k - speed] == NULL) {
								map[i + 1][j][k - speed] = nowShark;
							}
							else { // �̹� �� ����
								if (map[i + 1][j][k - speed]->size < size) { // ���� �� �� ŭ
									map[i + 1][j][k - speed] = nowShark;
								} // �� ���� ��� ���� ���� ���
							}
						}
					}
					else if (dir == 1) { // ������
						if (k + speed >= c) {// ������ȯ
							if (map[i + 1][j][c - 1 - (speed + k - c)] == NULL) {
								map[i + 1][j][c - 1 - (speed + k - c)] = nowShark;
								nowShark->dir = 0;
							}
							else { // �̹� �� ����
								if (map[i + 1][j][c - 1 - (speed + k - c)]->size < size) { // ���� �� �� ŭ
									map[i + 1][j][c - 1 - (speed + k - c)] = nowShark;
									nowShark->dir = 0;
								} // �� ���� ��� ���� ���� ���
							}
						}
						else { // ������ȯ ����
							if (map[i + 1][j][k + speed] == NULL) {
								map[i + 1][j][k + speed] = nowShark;
							}
							else { // �̹� �� ����
								if (map[i + 1][j][k + speed]->size < size) { // ���� �� �� ŭ
									map[i + 1][j][k + speed] = nowShark;
								} // �� ���� ��� ���� ���� ���
							}
						}
					}
					else if (dir == 2) { // ����
						if (j - speed < 0) { // ������ȯ
							if (map[i + 1][speed - j][k] == NULL) {
								map[i + 1][speed - j][k] = nowShark;
								nowShark->dir = 3;
							}
							else { // �̹� �� ����
								if (map[i + 1][speed - j][k]->size < size) { // ���� �� �� ŭ
									map[i + 1][speed - j][k] = nowShark;
									nowShark->dir = 3;
								} // �� ���� ��� ���� ���� ���
							}
						}
						else { // ������ȯ ����
							if (map[i + 1][j - speed][k] == NULL) {
								map[i + 1][j - speed][k] = nowShark;
							}
							else { // �̹� �� ����
								if (map[i + 1][j - speed][k]->size < size) { // ���� �� �� ŭ
									map[i + 1][j - speed][k] = nowShark;
								} // �� ���� ��� ���� ���� ���
							}
						}
					}
					else if (dir == 3) { // �Ʒ���
						if (j + speed >= r) { // ������ȯ
							if (map[i + 1][r - 1 - (speed + j - r)][k] == NULL) {
								map[i + 1][r - 1 - (speed + j - r)][k] = nowShark;
								nowShark->dir = 2;
							}
							else { // �̹� �� ����
								if (map[i + 1][r - 1 - (speed + j - r)][k]->size < size) { // ���� �� �� ŭ
									map[i + 1][r - 1 - (speed + j - r)][k] = nowShark;
									nowShark->dir = 2;
								} // �� ���� ��� ���� ���� ���
							}
						}
						else { // ������ȯ ����
							if (map[i + 1][j + speed][k] == NULL) {
								map[i + 1][j + speed][k] = nowShark;
							}
							else { // �̹� �� ����
								if (map[i + 1][j + speed][k]->size < size) { // ���� �� �� ŭ
									map[i + 1][j + speed][k] = nowShark;
								} // �� ���� ��� ���� ���� ���
							}
						}
					} // end of elseif */

				} // �̹� ��� �̵� ��

			}
		} // r, c�� ���� ����


	}

	cout << count << '\n';

	return 0;
}