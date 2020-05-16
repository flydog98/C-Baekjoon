// 1929번 소수 구하기

#include <iostream>

using namespace std;

int main(void) {
	int a = 0, b = 0;
	static int number[1000001];

	for (int i = 2; i < 1000001; i++) {
		if (!number[i]) {
			number[i] = 1;
			for (int j = i * 2; j < 1000001; j += i) {
				number[j] = 2;
			}
		}
	}

	cin >> a >> b;

	for (int i = a; i < b + 1; i++) {
		if (number[i] == 1) printf("%d\n", i);
	}

	return 0;
}