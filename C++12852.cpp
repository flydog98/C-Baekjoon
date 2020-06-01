// 12852�� 1�� ����� 2

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main(void) {
	int input = 0, ans = 0, now;
	static int dynamic[1000001]; // ������ �湮�� ��
	queue<int> q;
	stack<int> out;

	cin >> input;

	q.push(input);

	while (!q.empty()) {
		now = q.front();
		q.pop();
		if (!(now % 3) && now > 0 && !dynamic[now / 3]) {
			// ������ ��������, now�� 0�� �ƴϸ�, now / 3�� �湮�� �� ����
			dynamic[now / 3] = now;
			if (now / 3 == 1) break;
			q.push(now / 3);
			
		}
		if (!(now % 2) && now > 0 && !dynamic[now / 2]) {
			dynamic[now / 2] = now;
			if (now / 2 == 1) break;
			q.push(now / 2);
		}
		if (now > 1 && !dynamic[now - 1]) {
			dynamic[now - 1] = now;
			if (now - 1 == 1) break;
			q.push(now - 1);
		}
	}

	now = 1;
	out.push(now);
	while (!(now == input)) {
		ans++;
		now = dynamic[now];
		out.push(now);
	}

	cout << ans << '\n';
	while (!out.empty()) {
		cout << out.top() << ' ';
		out.pop();
	}
	cout << '\n';


	return 0;
}