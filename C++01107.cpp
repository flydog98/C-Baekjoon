#include <iostream>
#include <algorithm>

using namespace std;

int check(int broken[], int i);

int main(void) {
	int goal = 0;
	int numbers = 0;
	int broken[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	cin >> goal;
	cin >> numbers;
	for (int i = 0; i < numbers; i++) {
		int temp = 0;
		cin >> temp;
		broken[temp] = 1;
	}

	int mini = max(goal, 100) - min(goal, 100);

	for (int i = 0; i < 10000000; i++) {
		int keynumbers = check(broken, i);
		if (!keynumbers) continue;
		int temp = max(goal, i) - min(goal, i) + keynumbers;
		mini = min(temp, mini);
	}

	cout << mini << endl;
	return 0;
}

int check(int broken[], int i) {
	int result = 0;
	int temp = i;
	if (temp == 0 && !broken[0]) return 1;
	while (temp != 0) {
		int ttemp = temp % 10;
		if (broken[ttemp]) {
			result = 0;
			break;
		}
		temp /= 10;
		result++;
	}
	return result;
}