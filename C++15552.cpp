// 15552¹ø ºü¸¥ A + B

#include <iostream>

using namespace std;

int main(void) {
	int test = 0;
	int a = 0, b = 0;

	scanf("%d", &test);

	for (int i = 0; i < test; i++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", a + b);
	}
	return 0;
}