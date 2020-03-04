// 04641¹ø Doubles

#include <iostream>

using namespace std;

int finding(int* number, int now) {
	int ret = 0;
	int temp = 0;
	for (int i = 0; i < now; i++) {
		temp = number[i];
		for (int j = 0; j < now; j++) {
			if (temp * 2 == number[j]) {
				ret++;
				break;
			}
		}
	}

	return ret;
}

int main(void) {
	int number[15];
	int now = 0;
	int temp = 0;
	int ret = 0;

	while (1) {
		cin >> temp;
		if (!temp) {
			number[now] = temp;
			ret = finding(number, now);
			printf("%d\n", ret);
			now = 0;
		}
		else if (temp == -1) break;
		else {
			number[now++] = temp;
		}
	}

	return 0;
}