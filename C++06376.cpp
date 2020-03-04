// 6376¹ø e °è»ê

#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	double temp = 2.5;
	int fact = 2;
	printf("n e\n");
	printf("- -----------\n");
	printf("0 1\n");
	printf("1 2\n");
	printf("2 2.5\n");
	for (int i = 3; i < 10; i++) {
		fact *= i;
		temp += (double)1 / (double)fact;
		printf("%d %.9f\n", i, temp);
	}


	return 0;
}