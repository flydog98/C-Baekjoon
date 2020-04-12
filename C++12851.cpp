// 12851¹ø ¼û¹Ù²ÀÁú 2

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int main(void) {
	int start = 0, end = 0;
	int dest[100001];
	int count[100001];
	int result = 0;
	queue<int> q;

	memset(dest, -1, sizeof(dest));
	memset(count, 0, sizeof(count));

	cin >> start >> end;

	dest[start] = 0;
	count[start] = 1;
	q.push(start);
	while (!q.empty()) {
		int temp = q.front();
		q.pop();

		if (dest[end] != -1 && dest[temp] > dest[end]) break;

		if (temp > 0) {
			if (dest[temp - 1] == -1) {
				dest[temp - 1] = dest[temp] + 1;
				count[temp - 1] += count[temp];
				q.push(temp - 1);
			}
			else if (dest[temp - 1] == dest[temp] + 1) {
				count[temp - 1] += count[temp];
			}

		}

		if (temp < 100000) {
			if (dest[temp + 1] == -1) {
				dest[temp + 1] = dest[temp] + 1;
				count[temp + 1] += count[temp];
				q.push(temp + 1);
			}
			else if (dest[temp + 1] == dest[temp] + 1) {
				count[temp + 1] += count[temp];
			}
		}

		if (temp * 2 <= 100000) {
			if (dest[temp * 2] == -1) {
				dest[temp * 2] = dest[temp] + 1;
				count[temp * 2] += count[temp];
				q.push(temp * 2);
			}
			else if (dest[temp * 2] == dest[temp] + 1) {
				count[temp * 2] += count[temp];
			}
		}

	}


	cout << dest[end] << endl;


	cout << count[end] << endl;

	return 0;
}