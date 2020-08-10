// 11660 구간 합 구하기 5

#include <iostream>

using namespace std;

int main(void) {
	int n = 0, m = 0;
	int sum = 0;
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	int** map = new int*[1025];

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n + 1; i++) {
		map[i] = new int[1025];
	}

	for (int i = 0; i < n; i++) {
		sum = 0;
		map[i + 1][0] = sum;
		for (int j = 0; j < n; j++) {
			int temp;
			cin >> temp;
			sum += temp;
			map[i + 1][j + 1] = sum;
		}
	}

	for (int i = 0; i < m; i++) {
		sum = 0;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = x1; j <= x2; j++) {
			sum += map[j][y2] - map[j][y1 - 1];
		}

		cout << sum << '\n';
	}

	return 0;
}