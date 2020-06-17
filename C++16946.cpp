// 16946�� �� �μ��� �̵��ϱ� 4

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int check(vector<int> lists, int number) {
	for (int i = 0; i < lists.size(); i++) {
		if (lists[i] == number) return 0; // ���� �� �ִ�
	}
	return 1; // �����ϴ�
}

int main(void) {
	char input;
	int m = 0, n = 0;
	int** map, **number;
	int numbercount = 0;
	queue<pair<int, int>> q; // (y, x)
	vector<int> distlist;

	scanf("%d", &n);
	scanf("%c", &input);
	scanf("%d", &m);
	scanf("%c", &input);

	map = new int*[n];
	number = new int*[n];
	for (int i = 0; i < n; i++) {
		map[i] = new int[m];
		number[i] = new int[m];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%c", &input);
			map[i][j] = input - '0';
			if (input == '1') {
				number[i][j] = 0; // ������ 0 ��, ���̶�� �ǹ�
			}
			else {
				number[i][j] = -1; // ���� �� ���� ���� �׷��� ������ �������� ����
			}
		}
		scanf("%c", &input);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (number[i][j] == -1) { // -1 ��, �� ���� ���� �׷��� �������� �ʾҴٸ� bfs����
				q.push(make_pair(i, j));
				int maxx = 0;
				while (!q.empty()) {
					int y = q.front().first;
					int x = q.front().second;
					maxx++;
					number[y][x] = numbercount;
					q.pop();

					if (x > 0 && number[y][x - 1] == -1 && map[y][x - 1] == 0) {
						number[y][x - 1] = -2;
						q.push(make_pair(y, x - 1));
					}
					if (x < m - 1 && number[y][x + 1] == -1 && map[y][x + 1] == 0) {
						number[y][x + 1] = -2;
						q.push(make_pair(y, x + 1));
					}
					if (y > 0 && number[y - 1][x] == -1 && map[y - 1][x] == 0) {
						number[y - 1][x] = -2;
						q.push(make_pair(y - 1, x));
					}
					if (y < n - 1 && number[y + 1][x] == -1 && map[y + 1][x] == 0) {
						number[y + 1][x] = -2;
						q.push(make_pair(y + 1, x));
					}
				}
				distlist.push_back(maxx);
				numbercount++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!map[i][j]) cout << 0; // ���� �ƴ� ���
			else { // ���� ���
				int x = j, y = i; // ������ ����
				int ttemp = 0;
				vector<int> lists;
				if (x > 0 && map[y][x - 1] == 0) {
					ttemp = number[y][x - 1];
					lists.push_back(ttemp);
				}
				if (x < m - 1 && map[y][x + 1] == 0) {
					ttemp = number[y][x + 1];
					if (check(lists, ttemp)) { // �� ttemp�� ������ ���
						lists.push_back(ttemp);
					} // �������� ������ ���Ϳ� �߰� ����
				}
				if (y > 0 && map[y - 1][x] == 0) {
					ttemp = number[y - 1][x];
					if (check(lists, ttemp)) { // �� ttemp�� ������ ���
						lists.push_back(ttemp);
					} // �������� ������ ���Ϳ� �߰� ����
				}
				if (y < n - 1 && map[y + 1][x] == 0) {
					ttemp = number[y + 1][x];
					if (check(lists, ttemp)) { // �� ttemp�� ������ ���
						lists.push_back(ttemp);
					} // �������� ������ ���Ϳ� �߰� ����
				}

				ttemp = 0;
				for (int k = 0; k < lists.size(); k++) {
					ttemp += distlist[lists[k]];
				}
				cout << (ttemp + 1) % 10;
			}
		}
		cout << '\n';
	}

	return 0;
}