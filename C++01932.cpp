//1932번 정수 삼각형

#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int size;
	int temp;
	int** triangle = new int*[500];
	int** map = new int*[500];

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> size;

	for (int i = 0; i < size; i++) {
		triangle[i] = new int[size];
		map[i] = new int[size];
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> temp;
			triangle[i][j] = temp;
		}
	}

	map[0][0] = triangle[0][0];
	for (int i = 1; i < size; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) { // 왼쪽 변
				map[i][j] = map[i - 1][j] + triangle[i][j];
			}
			else if (j == i) { // 오른쪽 변
				map[i][j] = map[i - 1][j - 1] + triangle[i][j];
			}
			else { // 다른 모든 경우
				int big = max(map[i - 1][j - 1], map[i - 1][j]);
				map[i][j] = big + triangle[i][j];
			}
		}
	}
	
	int ans = 0;

	for (int i = 0; i < size; i++) {
		ans = max(ans, map[size - 1][i]);
	}

	cout << ans << '\n';

	return 0;
}