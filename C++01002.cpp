#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
	int testCase;
	cin >> testCase;
	for (int i = 0; i < testCase; i++) {
		int x1, y1, r1, x2, y2, r2; // 입력값을 저장하는 곳
		double between;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		int big, small;
		if (r1 > r2) {
			big = r1;
			small = r2;
		}
		else {
			big = r2;
			small = r1;
		}
		between = sqrt((double)(pow(x1 - x2, 2) + pow(y1 - y2, 2)));
		if (x1 == x2 && y1 == y2 && r1 == r2) {
			cout << -1 << endl;
		}
		else if (between == r1 + r2 || r1 + between == r2 || r2 + between == r1) {
			cout << 1 << endl;
		}
		else if (r1 + r2 > between && big - small < between) {
			cout << 2 << endl;
		}
		else {
			cout << 0 << endl;
		}
	}
	return 0;
}