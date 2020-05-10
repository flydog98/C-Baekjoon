// 10773¹ø Á¦·Î

#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int amount = 0, result = 0;
	int temp = 0;
	vector<int> store;

	cin >> amount;

	for (int i = 0; i < amount; i++) {
		cin >> temp;
		if (temp) store.push_back(temp);
		else store.pop_back();
	}

	for (int i = 0; i < store.size(); i++) {
		result += store[i];
	}

	cout << result << endl;

	return 0;
}