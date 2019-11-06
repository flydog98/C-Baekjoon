// 1261�� �˰���

#include <iostream>
#include <string>
#include <cstring>
#include <deque>
#include <utility>

using namespace std;

int main(void) {
	int row = 0, col = 0;
	int map[100][100]; // 0�� 1�� �����ϴ� ����
	int move[100][100]; // ������ �ش� ��ǥ�� �̵�Ƚ���� �����ϴ� ��
	char check[100][100]; // �湮 ���θ� �����ϴ� �迭
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
		//deque�� �̿���, �� ������ ��� ���ʿ� push, ���� ��� ���ʿ� push�Ѵ�
		//�ٸ� BFSó�� ó���Ǵ� ��ǥ�� �̵� Ƚ���� ������� �����ϸ� 000...0 111...1 222...2
		//�̷������� �����ϴ� �������� ó���ȴ�.
		pair<int, int> now = dq.front();
		dq.pop_front();
		int nowmove = move[now.first][now.second];
		int x[4] = { now.first - 1, now.first + 1, now.first, now.first};
		int y[4] = { now.second, now.second, now.second + 1, now.second - 1 };

		int i = 0;

		if (x[i] >= 0) { // ���� �̵��ϴ� ���
			if (!check[x[i]][y[i]]) { // ���� �湮 ���� üũ
				check[x[i]][y[i]] = true;
				pair<int, int> ttemp = make_pair(x[i], y[i]);
				if (map[x[i]][y[i]]) { // ���� �ִ� ���
					move[x[i]][y[i]] = nowmove + 1;
					dq.push_back(ttemp);
				}
				else { // ���� ���� ���
					move[x[i]][y[i]] = nowmove;
					dq.push_front(ttemp);
				}
			}
		}

		i++;
		if (x[i] < row) { // ������ �̵��ϴ� ���
			if (!check[x[i]][y[i]]) { // ���� �湮 ���� üũ
				check[x[i]][y[i]] = true;
				pair<int, int> ttemp = make_pair(x[i], y[i]);
				if (map[x[i]][y[i]]) { // ���� �ִ� ���
					move[x[i]][y[i]] = nowmove + 1;
					dq.push_back(ttemp);
				}
				else { // ���� ���� ���
					move[x[i]][y[i]] = nowmove;
					dq.push_front(ttemp);
				}
			}
		}

		i++;
		if (y[i] < col) { // ���� �̵��ϴ� ���
			if (!check[x[i]][y[i]]) { // ���� �湮 ���� üũ
				check[x[i]][y[i]] = true;
				pair<int, int> ttemp = make_pair(x[i], y[i]);
				if (map[x[i]][y[i]]) { // ���� �ִ� ���
					move[x[i]][y[i]] = nowmove + 1;
					dq.push_back(ttemp);
				}
				else { // ���� ���� ���
					move[x[i]][y[i]] = nowmove;
					dq.push_front(ttemp);
				}
			}
		}

		i++;
		if (y[i] >= 0) { // �Ʒ��� �̵��ϴ� ���
			if (!check[x[i]][y[i]]) { // ���� �湮 ���� üũ
				check[x[i]][y[i]] = true;
				pair<int, int> ttemp = make_pair(x[i], y[i]);
				if (map[x[i]][y[i]]) { // ���� �ִ� ���
					move[x[i]][y[i]] = nowmove + 1;
					dq.push_back(ttemp);
				}
				else { // ���� ���� ���
					move[x[i]][y[i]] = nowmove;
					dq.push_front(ttemp);
				}
			}
		}


	}

	cout << move[row - 1][col - 1] << endl;

	return 0;
}