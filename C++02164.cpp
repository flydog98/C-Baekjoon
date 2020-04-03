//2164¹ø Ä«µå2

#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	bool flag = true;
	int input = 0;
	int temp = 0;
	static int numbers[1000000] = { 0, };

	cin >> input;
	temp = input;

	for (int i = 0; i < input; i++) {
		numbers[i] = i + 1;
	}

	while (temp > 1) {
		for (int i = 0; i < input; i++) {
			if (numbers[i]) {
				if (flag) {
					numbers[i] = 0;
					temp--;
					flag = false;
				}
				else flag = true;
			}
		}
		if (!flag) {
			for (int i = 0; i < input; i++) {
				if (numbers[i]) {
					numbers[input] = numbers[i];
					numbers[i] = 0;
					input++;
					flag = true;
					break;
				}
			}
		}
	}

	for (int i = 0; i < input; i++) {
		if (numbers[i]) {
			temp = numbers[i];
			break;
		}
	}

	cout << temp << endl;

	return 0;
}