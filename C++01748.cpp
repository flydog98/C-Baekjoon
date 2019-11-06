#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
	long long result = 0;

	int input = 0;
	int i = 0;
	cin >> input;
	for (i = 10; i < input; i *= 10) {
		result += (log10(i)) * 9 * i / 10;
	}
	if(i != 1) i /= 10;
	result += (input - i + 1) * (log10(i) + 1);
	for (int j = 1; j < 9; j++) {
		if (input == pow(10, j))
			result++;
	}
	cout << result << endl;

	return 0;
}