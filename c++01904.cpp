#include <iostream>

using namespace std;

int main(void) {
	int input = 0;
	static int store[1000001];
	store[0] = 0; store[1] = 1; store[2] = 2;
	
	cin >> input;

	for (int i = 3; i <= input; i++) {
		store[i] = store[i - 1] % 15746 + store[i - 2] % 15746;
	}

	cout << store[input] % 15746 << endl;

	return 0;
}