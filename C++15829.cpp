// 15829¹ø Hashing

#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int amount = 0;
	string input;
	long long temp = 0, answer = 0;
	long long numbers[50];

	numbers[0] = 1;
	for (int i = 1; i < 50; i++) {
		numbers[i] = (numbers[i - 1] * 31) % 1234567891;
	}

	cin >> amount >> input;

	for (int i = 0; i < amount; i++) {
		temp = input[i] - 'a' + 1;
		temp *= numbers[i];
		answer += temp;
		answer = answer % 1234567891;
	}

	cout << answer;

	return 0;
}