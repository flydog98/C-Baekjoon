// 12851번 숨바꼭질 2

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int main(void) {
	int start = 0, end = 0;
	int dest[100001];
	int result = 0;
	queue<int> q;

	memset(dest, -1, sizeof(dest));

	cin >> start >> end;

	dest[start] = 0;
	q.push(start);
	while (!q.empty()) {
		int temp = q.front();
		q.pop();

		if (temp > 0 && dest[temp - 1] == -1) {
			dest[temp - 1] = dest[temp] + 1;
			q.push(temp - 1);
		}

		if (temp < 100000 && dest[temp + 1] == -1) {
			dest[temp + 1] = dest[temp] + 1;
			q.push(temp + 1);
		}

		if (temp * 2 <= 100000 && dest[temp * 2] == -1) {
			dest[temp * 2] = dest[temp] + 1;
			q.push(temp * 2);
		}
	}

	cout << dest[end] << endl;


	cout << result << endl;

	return 0;
}