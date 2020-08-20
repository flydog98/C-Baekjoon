// 9465번 스티커

#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int testcase = 0;
	int n = 0;
	int temp = 0;
	static int sticker[2][100000];
	static int dp[2][100000];

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> testcase;

	for (int q = 0; q < testcase; q++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> temp;
			sticker[0][i] = temp;
		}
		for (int i = 0; i < n; i++) {
			cin >> temp;
			sticker[1][i] = temp;
		}

		dp[0][0] = sticker[0][0];
		dp[1][0] = sticker[1][0];

		if (n > 1) {
			dp[0][1] = sticker[0][1] + dp[1][0];
			dp[1][1] = sticker[1][1] + dp[0][0];
		}

		for (int i = 2; i < n; i++) {
			dp[0][i] = sticker[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
			dp[1][i] = sticker[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
		}

		cout << max(dp[0][n - 1], dp[1][n - 1]) << '\n';
	}

	return 0;
}