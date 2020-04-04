// 4153번 직각삼각형

#include <iostream>

using namespace std;

int main(void) {
	int a = 1, b = 1, c = 1;

	cin >> a >> b >> c;

	while (!(a == 0 && b == 0 && c == 0)) {
		a *= a;
		b *= b;
		c *= c;

		if (a == b + c) printf("right\n");
		else if (b == a + c) printf("right\n");
		else if (c == a + b) printf("right\n");
		else printf("wrong\n");

		cin >> a >> b >> c;
	}

	return 0;
}