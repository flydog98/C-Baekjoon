#include <iostream>

using namespace std;

int main(void) {
	int numbers[10001];
	int temp, loop;
	for (int i = 0; i < 10001; i++) {
		numbers[i] = 0;
	}
	scanf("%d", &loop);
	for (int i = 0; i < loop; i++) {
		scanf("%d", &temp);
		numbers[temp]++;
	}
	for (int i = 0; i < 10001; i++) {
		for (int j = 0; j < numbers[i]; j++) {
			printf("%d\n", i);
		}
	}
	return 0;
}