//10026�� ���ϻ���

#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int main(void) {
	int sizee = 0;
	int normal_amount = 0, cweak_amount = 0; // ������ �����ϴ� ����
	char temp = '0';
	pair<int, int> loctemp;
	char map[100][100]; // ������� ����ȴ�
	int normal[100][100]; // �Ϲ� ������� ����
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
			if (!normal[i][j]) { // �湮���� ���� ��쿡�� (�湮�� ��� 0�� �ƴ� ���� ����ȴ�)
				temp = map[i][j]; // �̹��� üũ�� ������ ������ ����
				normal_amount++; // count�� ������ ���� ����
				loctemp = make_pair(i, j);
				normal[i][j] = normal_amount;

				q.push(loctemp);
				while (!q.empty()) { // bfs�� �����Ѵ�
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

	//������࿡ �°� ���� ����
	for (int i = 0; i < sizee; i++) {
		for (int j = 0; j < sizee; j++) {
			if (map[i][j] == 'R') map[i][j] = 'G';
		}
	}

	//���� �̸��鸸 ������ �� �����߽��ϴ�.
	for (int i = 0; i < sizee; i++) {
		for (int j = 0; j < sizee; j++) {
			if (!cweak[i][j]) { // �湮���� ���� ��쿡�� (�湮�� ��� 0�� �ƴ� ���� ����ȴ�)
				temp = map[i][j]; // �̹��� üũ�� ������ ������ ����
				cweak_amount++; // count�� ������ ���� ����
				loctemp = make_pair(i, j);
				normal[i][j] = cweak_amount;

				q.push(loctemp);
				while (!q.empty()) { // bfs�� �����Ѵ�
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