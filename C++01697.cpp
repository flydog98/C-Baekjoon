#include <iostream>
#include <queue>

using namespace std;

int main(void) {
	int start = 0, end = 0;
	bool check[100001];
	int dist[100001];
	queue<int> q;
	
	for (int i = 0; i < 100001; i++) {
		check[i] = false;
		dist[i] = 0;
	}

	cin >> start >> end;
	check[start] = true;
	q.push(start);
	while (!(q.empty())) {
		int now = q.front();
		q.pop();
		if (now - 1 >= 0) {
			if (!check[now - 1]) {
				q.push(now - 1);
				check[now - 1] = true;
				dist[now - 1] = dist[now] + 1;
			}
		}
		if (now + 1 < 100001) {
			if (!check[now + 1]) {
				q.push(now + 1);
				check[now + 1] = true;
				dist[now + 1] = dist[now] + 1;
			}
		}
		if (now * 2 < 100001) {
			if (!check[now * 2]) {
				q.push(now * 2);
				check[now * 2] = true;
				dist[now * 2] = dist[now] + 1;
			}
		}
	}

	cout << dist[end] << endl;

	return 0;
}