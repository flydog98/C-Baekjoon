// 2206�� �� �μ��� �̵��ϱ�

#include <iostream>
#include <queue>

using namespace std;

int main(void) {
	int y, x;
	char input;
	static int map[1000][1000];
	static int normal[1000][1000][2];
	queue<pair<int, int>> q;
	queue<int> broken;

	int xHard[4] = { -1, 1, 0, 0 };
	int yHard[4] = { 0, 0, 1, -1 };

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> y >> x;

	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			cin >> input;
			map[i][j] = input - '0';
		}
	}

	normal[0][0][0] = 1;
	q.push(make_pair(0, 0));
	broken.push(0);

	while (!q.empty()) {
		int nowx = q.front().second;
		int nowy = q.front().first;
		int nowbroken = broken.front();
		int nownum = normal[nowy][nowx][nowbroken];

		q.pop();
		broken.pop();

		for (int i = 0; i < 4; i++) {
			int nextx = nowx + xHard[i];
			int nexty = nowy + yHard[i];

			if (nextx >= 0 && nextx < x && nexty >= 0 && nexty < y) { // next�� ������ �������� üũ
				if (map[nexty][nextx]) { // ���� ���̶��
					if (!nowbroken) { // ���� �μ� ���� ����
						// ���� ���� �μ�
						normal[nexty][nextx][1] = nownum + 1;
						q.push(make_pair(nexty, nextx));
						broken.push(1);
					}
				}
				else { // ���� �ƴ϶��
					if (!nowbroken) { // ���� ���� �μ� ���� ����
						if (normal[nexty][nextx][0] == 0) { // ���� �μ��� �ʰ� �湮�� ���� ����
							normal[nexty][nextx][nowbroken] = nownum + 1;
							q.push(make_pair(nexty, nextx));
							broken.push(0);
						}
						else if (normal[nexty][nextx][0] > nownum + 1) { // ���� �μ��� �ʰ� �湮������, ������ �� ����
							normal[nexty][nextx][nowbroken] = nownum + 1;
							q.push(make_pair(nexty, nextx));
							broken.push(0);
						}
					}
					else { // �̹� ���� �ν���
						if (normal[nexty][nextx][0]) { // ���� �� �μ��� �湮�� �� ����
							if (normal[nexty][nextx][0] > nownum + 1) { // ���� �μ��� �湮�ϴ� �� �� ����
								if (normal[nexty][nextx][1] > nownum + 1) { // ���� �μ��� �湮�ϴ� �� �� ���� ����
									normal[nexty][nextx][1] = nownum + 1;
									q.push(make_pair(nexty, nextx));
									broken.push(1);
								}
							}
						}
						else { // ���� �� �μ���� ������ ���� ����
							if (normal[nexty][nextx][1] == 0) { // ���� �μ��� ������ ���� ����
								normal[nexty][nextx][1] = nownum + 1;
								q.push(make_pair(nexty, nextx));
								broken.push(1);
							}
							else if (normal[nexty][nextx][1] > nownum + 1) { // ���� �μ��� �湮�ϴ� �� �� ���� ����
								normal[nexty][nextx][1] = nownum + 1;
								q.push(make_pair(nexty, nextx));
								broken.push(1);
							}
						}
					}
				}
			}
		}

	}

	int res1 = normal[y - 1][x - 1][0];
	int res2 = normal[y - 1][x - 1][1];

	if (res1 == 0 && res2 == 0) cout << -1 << endl;
	else if (res1 == 0) cout << res2 << endl;
	else if (res2 == 0) cout << res1 << endl;
	else cout << min(res1, res2) << endl;

	return 0;
}