// 2096번 내려가기

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	int amount = 0;
	vector<vector<int>> map;

	int higha = 0, highb = 0, highc = 0;
	int lowa = 0, lowb = 0, lowc = 0;

	int new_higha = 0, new_highb = 0, new_highc = 0;
	int new_lowa = 0, new_lowb = 0, new_lowc = 0;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> amount;

	for (int i = 0; i < 3; i++) {
		vector<int> temp;
		map.push_back(temp);
	}

	for (int i = 0; i < amount; i++) {
		for (int j = 0; j < 3; j++) {
			int temp;
			cin >> temp;
			map[j].push_back(temp);
		}
	}

	higha = map[0][0]; highb = map[1][0]; highc = map[2][0];
	lowa = map[0][0]; lowb = map[1][0]; lowc = map[2][0];

	for (int i = 1; i < amount; i++) {
		new_higha = map[0][i] + max(higha, highb);
		new_highb = map[1][i] + max(highc, max(higha, highb));
		new_highc = map[2][i] + max(highc, highb);

		higha = new_higha;
		highb = new_highb;
		highc = new_highc;

		new_lowa = map[0][i] + min(lowa, lowb);
		new_lowb = map[1][i] + min(lowc, min(lowa, lowb));
		new_lowc = map[2][i] + min(lowc, lowb);

		lowa = new_lowa;
		lowb = new_lowb;
		lowc = new_lowc;
	}

	int ans1 = max(max(higha, highb), highc);
	int ans2 = min(min(lowa, lowb), lowc);

	cout << ans1 << ' ' << ans2 << '\n';

	return 0;
}