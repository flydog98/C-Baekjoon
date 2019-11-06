#include <iostream>
#include <cmath>
#include <string>

using namespace std;

long long getLength(int number);

int main(void) {
	int inputN, inputK;
	cin >> inputN >> inputK;
	long long temp = getLength(inputN);
	int much = (int)ceil(inputN / 2);
	int muchWatcher = (int)ceil(inputN / 2);// temp보다 큰 수를 할지말지 결정한 후 더하거나 빼줄 수
	int number = 0;
	if (temp < inputK) {
		cout << -1 << endl;
		return 0;
	}
	while (1) {
		temp = getLength(much);
		if (temp < inputK) {
			muchWatcher = (int)ceil(muchWatcher / 2);
			if (!muchWatcher) muchWatcher++;
			much += muchWatcher;
		}
		else {
			if (temp - (int)log10(much) - 1 < inputK) {
				number = temp - inputK;
				break;
			}
			muchWatcher = (int)ceil(muchWatcher / 2);
			if (!muchWatcher) muchWatcher++;
			much -= muchWatcher;
		}
	}
	string goingresult = to_string(much);
	cout << goingresult[goingresult.size() - number - 1] << endl;
	return 0;
}

long long getLength(int number) {
	int i = 1;
	long long result = 0;
	for (i = 10; i <= number; i *= 10) {
		result += i * 0.9 * ((int)log10(i));
	}
	result += (number - i / 10 + 1) * ((int)log10(number) + 1);
	return result;
}