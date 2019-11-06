#include <iostream>
#include <cmath>
#include <time.h>

using namespace std;

int main(void) {
	time_t start, end;
	start = clock();
	int result = 0;
	int testCase;
	int x1, y1, x2, y2;
	cin >> testCase;
	for (int i = 0; i < testCase; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		int system;
		cin >> system;
		for (int j = 0; j < system; j++) {
			int tempx, tempy, r;
			double between1, between2;
			cin >> tempx >> tempy >> r;
			between1 = sqrt(pow(tempx - x1, 2) + pow(tempy - y1, 2));
			between2 = sqrt(pow(tempx - x2, 2) + pow(tempy - y2, 2));
			if ((between1 > r && between2 < r) || (between1 < r && between2 > r)) {
				result++;
			}
		}
		cout << result << endl;
		result = 0;
	}

	end = clock();
	cout << end - start << endl;

	return 0;
}