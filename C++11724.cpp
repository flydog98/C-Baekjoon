// 11724번 연결 요소의 개수

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void) {
	int count = 0, pointamount = 0, lineamount = 0;
	int a = 0, b = 0;
	vector<vector<int>> points;
	vector<int> tteemmpp;
	queue<int> q;
	int map[1001] = { 0, };

	cin >> pointamount >> lineamount;

	for (int i = 0; i < pointamount + 1; i++) {
		points.push_back(tteemmpp);
	}

	for (int i = 0; i < lineamount; i++) {
		cin >> a >> b;

		points[a].push_back(b);
		points[b].push_back(a);
	}

	for (int i = 1; i < pointamount + 1; i++) {
		if (!map[i]) {
			//bfs
			count++;
			map[i] = count;
			q.push(i);
			while (!q.empty()) {
				int temp = q.front();
				q.pop();

				for (int j = 0; j < points[temp].size(); j++) {
					if (!map[points[temp][j]]) {
						map[points[temp][j]] = count;
						q.push(points[temp][j]);
					}
				}
			}

		}
	}

	cout << count << endl;

	return 0;
}