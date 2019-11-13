// 9461번 파도반 수열

#include <iostream>

using namespace std;

int main(void) {
	int repeat = 0, input = 0;
	long long number[101] = { 0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9, };
	for (int i = 11; i <= 100; i++) {
		number[i] = number[i - 1] + number[i - 5];
	}

	cin >> repeat;

	for (int j = 0; j < repeat; j++) {
		cin >> input;
		cout << number[input] << endl;
	}
	return 0;
}