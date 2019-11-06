#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int input = 0;
	int two = 0, five = 0;
	cin >> input;
	for (int i = 1; i < input + 1; i++) {
		int j = i, k = i;
		while (1) {
			if (j % 2 == 0) {
				j /= 2;
				two++;
			}
			else break;
		}
		while (1) {
			if (k % 5 == 0) {
				k /= 5;
				five++;
			}
			else break;
		}
	}
	cout << min(two, five) << endl;

	return 0;
}