#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int cardQuantity, goalNo;
	int result = 0;
	bool flag = false;
	cin >> cardQuantity >> goalNo;

	int *cards = new int[cardQuantity];
	for (int i = 0; i < cardQuantity; i++) {
		cin >> cards[i];
	}
	for (int i = 0; i < cardQuantity - 2; i++) {
		for (int j = i + 1; j < cardQuantity - 1; j++) {
			for (int k = j + 1; k < cardQuantity; k++) {
				int temp = cards[i] + cards[j] + cards[k];
				if (temp > goalNo) continue;
				if (temp == goalNo) flag = true;
				result = max(result, temp);
				if (flag) break;
			}
			if (flag) break;
		}
		if (flag) break;
	}

	cout << result << endl;

	return 0;
}