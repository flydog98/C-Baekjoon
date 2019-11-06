#include <iostream>
#include <algorithm>
#include <time.h>

using namespace std;

int lan(int centimeters[], int lines, long long temp);

int main(void) {
	clock_t start, end; double res;
	int lines, goal;
	int centimeters[10000];
	long long temp = 0, tempWatcher = 0;
	int result = 0;
	bool flag = false;
	cin >> lines >> goal;
	for (int i = 0; i < lines; i++) {
		cin >> centimeters[i];
		temp = max(centimeters[i], (int)temp);
	}
	if (goal == 1) {
		cout << temp << endl;
		return 0;
	}
	temp = temp / 2;
	tempWatcher = temp;
	while (1) {
		result = lan(centimeters, lines, temp);
		if (result < goal) {
			tempWatcher /= 2;
			temp -= tempWatcher;
			if (tempWatcher == 0) {
				flag = true;
				break;
			}
		}
		else if (result > goal) {
			tempWatcher /= 2;
			temp += tempWatcher;
			if (tempWatcher == 0) {
				flag = true;
				break;
			}
		}
		else {
			break;
		}
	}

	int ttemp;

	if (flag) {
		if (result < goal) {
			while (1) {
				temp--;
				ttemp = lan(centimeters, lines, temp);
				if (ttemp >= goal) {
					cout << temp << endl;
					return 0;
				}
			}
		}
		else if (result > goal) {
			while (1) {
				temp++;
				ttemp = lan(centimeters, lines, temp);
				if (ttemp == goal) break;
				if (ttemp < goal) {
					cout << temp - 1 << endl;
					return 0;
				}
			}
		}
	}

	start = clock();
	while(1) {
		ttemp = lan(centimeters, lines, temp + 5000);
		if (ttemp < goal) break;
		result = ttemp;
		temp += 5000;
	}
	temp += 5000;
	while (1) {
		ttemp = lan(centimeters, lines, temp);
		if (ttemp == goal) break;
		temp--;
	}
	
	end = clock();
	res = end - start;
	//cout << res << endl;
	cout << temp << endl;

	return 0;
}

int lan(int centimeters[], int lines, long long temp) {
	int result = 0;
	for (int i = 0; i < lines; i++) {
		result += centimeters[i] / temp;
	}
	return result;
}