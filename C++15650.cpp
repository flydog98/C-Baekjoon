// 15650�� N�� M(2)

#include <iostream>
#include <vector>

using namespace std;

void vprint(vector<int> vec) {
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << ' ';
	}
	cout << '\n';
	return;
}

void depthing(int n, int now, int remain, vector<int> store) {
	if (now > n && remain != 0) return;
	if (remain == 0) {
		vprint(store);
	}
	else {
		store.push_back(now);
		depthing(n, now + 1, remain - 1, store); // �̹� ���ڸ� ����

		store.pop_back();
		depthing(n, now + 1, remain, store); // �̹� ���ڸ� �ǳ� ��
	}

	return;
}

int main(void) {
	int m = 0, n = 0;
	vector<int> store;

	cin >> n >> m;

	depthing(n, 1, m, store);


	return 0;
}