// 9466�� �� ������Ʈ

#include <iostream>

using namespace std;

int main(void) {
	int tc = 0, amount = 0, temp, answer = 0;
	int list[100001][2]; 
	//0 : �湮�� �� ����
	//1 : �̹� ����
	//2 : ���� �� �� ����
	//3 : �Ǵ� ��

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
			if (!list[j][1]) { // �湮�� �� ���� ��,
				int now = j;
				int next = list[j][0];
				int dfsnow = 0;

				while (1) {
					list[now][1] = 3;

					if (list[next][1] == 0) { // keep going
						now = next;
						next = list[next][0]; // next�� next�� �� next
					}
					else if (list[next][1] == 1 || list[next][1] == 2) { // can't
						dfsnow = j; // ���������� dfs�� �����Ѵ�. ����� ���� �ſ� ���� ������ �����ϹǷ� while�� �����غ���
						while (1) {
							list[dfsnow][1] = 2; // ���� �� �� ����.
							if (dfsnow == now) break;
							dfsnow = list[dfsnow][0]; // next
						}
						break; // �̹� Ž�� ����
					}
					else { // 3: cycle�� ������� ��ŭ �����̴�
						//���� next�� ��� �ִ� �� ���� �����̴�.
						dfsnow = j;
						int token = 2; // dfsnow�� next�� ������ ������ dfs�� ���и� �Է�
						while (1) {
							if (dfsnow == next)
								if(list[dfsnow][1] == 3)token = 1; // �� ������ dfs�� �����̴�
								else break; // 3�� �ƴ϶�� ���� ������ ���Ҵٴ� ���̹Ƿ� ����
							list[dfsnow][1] = token;
							dfsnow = list[dfsnow][0]; // next;
						}
						break; // �̹� Ž�� ����
					} // end of if/else
				} // end of while
			} // end of if
		} // end of for

		for (int j = 1; j < amount + 1; j++) { // ��ü Ž������ 1�� �� ã��
			if (list[j][1] == 2) answer++;
		}

		cout << answer << '\n';
	}

	return 0;
}