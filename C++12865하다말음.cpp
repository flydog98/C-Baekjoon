// 12865번 평범한 배낭

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int amount = 0, maxweight = 0;
	int value = 0, weight = 0;
	int maxvalue = 0;
	int storevalue[100001] = { 0, };
	static int order[100001][100];
	pair<int, int> pairtemp;
	vector<pair<int, int>> objects;

	cin >> amount >> maxweight;

	for (int i = 0; i < amount; i++) {
		cin >> weight >> value;
		pairtemp = make_pair(weight, value);
		objects.push_back(pairtemp);
	}

	for (int i = 1; i <= maxweight; i++) { // 현재 weight
		for (int j = 0; j < amount; j++) { // 몇 번째 object인지
			if (objects[j].first <= i && order[i - objects[j].first][j] == 0) {
				int a = storevalue[i];
				storevalue[i] = max(storevalue[i], objects[j].second + storevalue[i - objects[j].first]);
				if (a != storevalue[i]) { // 값이 바뀌었을 때
					for (int k = 0; k < amount; k++) {
						order[i][k] = order[i - objects[j].first][k];
					}
					order[i][j] = 1;
				}
				maxvalue = max(storevalue[i], maxvalue);
			}
		}
	}

	cout << maxvalue << endl;

	return 0;
}