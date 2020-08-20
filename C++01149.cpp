//1149�� RGB�Ÿ�

#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int n = 0;
	int r = 0, g = 0, b = 0;
	int map[3][1000]; // r : 0, g : 1, b : 2��, x, y������ x���� y��° ����
	int mini[3][1000]; // 0: r�� ĥ �� �� �ּҰ�, 1 : g�� ĥ�� �� �ּҰ� ... 

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> r >> g >> b;
		map[0][i] = r;
		map[1][i] = g;
		map[2][i] = b;
	}

	mini[0][0] = map[0][0];
	mini[1][0] = map[1][0];
	mini[2][0] = map[2][0];

	for (int i = 1; i < n; i++) {
		mini[0][i] = map[0][i] + min(mini[1][i - 1], mini[2][i - 1]);
		mini[1][i] = map[1][i] + min(mini[0][i - 1], mini[2][i - 1]);
		mini[2][i] = map[2][i] + min(mini[1][i - 1], mini[0][i - 1]);
	}

	cout << min(min(mini[0][n - 1], mini[1][n - 1]), mini[2][n - 1]) << '\n';

	return 0;
}