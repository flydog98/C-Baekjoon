// 2206�� �� �μ��� �̵��ϱ�

#include <iostream>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

int main(void) {
	int row = 0, col = 0;
	static bool map[1000][1000]; // ������ ����
	static int move[1000][1000]; // �̵� Ƚ���� ����
	string temp;
	queue<int> rr; // row�� ť�� �ǹ��Ѵ�
	queue<int> cc; // column�� ť�� �ǹ��Ѵ�
	queue<bool> broken; // ���� �μ��� �̵��ߴ����� ť�� ��Ÿ����
	// pair�� ���� ������� ť�� �������� �׳� ť�� �� �� �������� ������ ����� �ȴ�

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
		//i�� ������Ű�鼭 r[i], c[i]�� ���� �������� ��Ÿ���µ�
		//���� �̰� �������� ���� ���� �𸣰ڴ�
		//�ٸ� �ڵ带 �����ϱ⿣ �ſ� ���ϴ�


		if (nowR > 0 && !move[r[i]][c[i]]) { // ���� �̵� + �湮 ���� üũ
			if (map[r[i]][c[i]]) { // ���� �ִ� ���
				if (!isbroken) { // ���� �μ� ���� ���� ���
					rr.push(r[i]);
					cc.push(c[i]);
					broken.push(1); // ���� �ν����Ƿ� 1
					move[r[i]][c[i]] = move[nowR][nowC] + 1;
				}
				// ���� �μ� ���� �ִ� ��� ���
			}
			else { // ���� ���� ���
				rr.push(r[i]);
				cc.push(c[i]);
				if (!isbroken) { // ���� �μ� ���� ���� ���
					broken.push(0); // ���� �μ� �� �����Ƿ� 0
				}
				else {
					broken.push(1); // ���� �μ� �� �����Ƿ� 1
				}
				move[r[i]][c[i]] = move[nowR][nowC] + 1;
			}
		}
		
		i++;
		if (nowR < row && !move[r[i]][c[i]]) { // ������ �̵� + �湮 ���� üũ
			if (map[r[i]][c[i]]) { // ���� �ִ� ���
				if (!isbroken) { // ���� �μ� ���� ���� ���
					rr.push(r[i]);
					cc.push(c[i]);
					broken.push(1); // ���� �ν����Ƿ� 1
					move[r[i]][c[i]] = move[nowR][nowC] + 1;
				}
				// ���� �μ� ���� �ִ� ��� ���
			}
			else { // ���� ���� ���
				rr.push(r[i]);
				cc.push(c[i]);
				if (!isbroken) { // ���� �μ� ���� ���� ���
					broken.push(0); // ���� �μ� �� �����Ƿ� 0
				}
				else {
					broken.push(1); // ���� �μ� �� �����Ƿ� 1
				}
				move[r[i]][c[i]] = move[nowR][nowC] + 1;
			}
		}

		i++;
		if (nowC < col - 1 && !move[r[i]][c[i]]) { // (�Է� ����)�Ʒ��� �̵� + �湮 ���� üũ
			if (map[r[i]][c[i]]) { // ���� �ִ� ���
				if (!isbroken) { // ���� �μ� ���� ���� ���
					rr.push(r[i]);
					cc.push(c[i]);
					broken.push(1); // ���� �ν����Ƿ� 1
					move[r[i]][c[i]] = move[nowR][nowC] + 1;
				}
				// ���� �μ� ���� �ִ� ��� ���
			}
			else { // ���� ���� ���
				rr.push(r[i]);
				cc.push(c[i]);
				if (!isbroken) { // ���� �μ� ���� ���� ���
					broken.push(0); // ���� �μ� �� �����Ƿ� 0
				}
				else {
					broken.push(1); // ���� �μ� �� �����Ƿ� 1
				}
				move[r[i]][c[i]] = move[nowR][nowC] + 1;
			}
		}

		i++;
		if (nowC > 0 && !move[r[i]][c[i]]) { // (�Է� ����)���� �̵� + �湮 ���� üũ
			if (map[r[i]][c[i]]) { // ���� �ִ� ���
				if (!isbroken) { // ���� �μ� ���� ���� ���
					rr.push(r[i]);
					cc.push(c[i]);
					broken.push(1); // ���� �ν����Ƿ� 1
					move[r[i]][c[i]] = move[nowR][nowC] + 1;
				}
				// ���� �μ� ���� �ִ� ��� ���
			}
			else { // ���� ���� ���
				rr.push(r[i]);
				cc.push(c[i]);
				if (!isbroken) { // ���� �μ� ���� ���� ���
					broken.push(0); // ���� �μ� �� �����Ƿ� 0
				}
				else {
					broken.push(1); // ���� �μ� �� �����Ƿ� 1
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