//15969น๘ วเบน

#include <iostream>

using namespace std;

int main(void) {
	int temp = 0;
	int ttemp = 0;
	int max = -1;
	int min = 1001;

	cin >> temp;

	for (int i = 0; i < temp; i++) {
		cin >> ttemp;
		if (ttemp > max) max = ttemp;
		if (ttemp < min) min = ttemp;
	}
	cout << max - min << endl;


	return 0;
}