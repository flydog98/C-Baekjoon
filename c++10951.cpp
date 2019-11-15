// 10951¹ø A + B - 4

#include <iostream>

using namespace std;

int main(void) {
	int a = 0, b = 0;
	while (1) {
		cin >> a >> b;
		if (cin.eof()) break;
		cout << a + b << '\n';
	}
	return 0;
}