//10870번 피보나치 수 5

#include <iostream>

using namespace std;

int fibo(int a) {
	if (a == 1) {
		return 1;
	}
	else if (a == 0) {
		return 0;
	}
	else {
		return fibo(a - 1) + fibo(a - 2);
	}
}

int main(void) {
	int a = 0;

	cin >> a;

	a = fibo(a);

	cout << a << endl;

	return 0;
}