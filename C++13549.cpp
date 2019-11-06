// 13549¹ø ¼û¹Ù²ÀÁú 3

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int main(void) {
	int start = 0, goal = 0;
	static int dest[100001];
	static bool check[100001];
	memset(dest, 0, sizeof(dest));
	memset(check, 0, sizeof(check));
	queue<int> q;

	cin >> start >> goal;

	q.push(start);
	dest[start] = 0;
	check[start] = 1;

	while (!q.empty() && !check[goal]) {
		int now = q.front();
		q.pop();

		if (now != 0) {
			for (int i = now; i < 100001; i *= 2) {
				if (!check[i]) {
					check[i] = true;
					q.push(i);
					dest[i] = dest[now];
				}
			}
		}

		if (now >= 1) {
			if (!check[now - 1]) {
				check[now - 1] = true;
				dest[now - 1] = dest[now] + 1;
				q.push(now - 1);
			}
		}

		if (now <= 99999) {
			if (!check[now + 1]) {
				check[now + 1] = true;
				dest[now + 1] = dest[now] + 1;
				q.push(now + 1);
			}
		}
	}

	cout << dest[goal] << endl;

	return 0;
}