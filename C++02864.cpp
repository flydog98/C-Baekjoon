// 2864번 5와 6의 차이

#include <iostream>
#include <cmath>

using namespace std;

int change(int input, int from, int to) {
	int ret = 0;
	int temp = input;
	int ttemp = 0;

	for (int i = 0; temp != 0; i++) {
		ttemp = temp % 10;
		if (ttemp == from) ttemp = to;
		ttemp *= (int)pow(10, i);
		ret += ttemp;
		temp /= 10;
	}

	return ret;
}

int main(void) {
	int input1 = 0, input2 = 0;
	int temp1 = 0, temp2 = 0;
	int max = 0, min = 20000000;

	cin >> input1 >> input2;

	temp1 = change(input1, 5, 6);
	temp2 = change(input2, 5, 6);

	max = temp1 + temp2;

	temp1 = change(input1, 6, 5);
	temp2 = change(input2, 6, 5);

	min = temp1 + temp2;

	cout << min << ' ' << max << endl;

	return 0;
}