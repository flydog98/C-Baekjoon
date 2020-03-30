//10816번 숫자 카드 2

#include <iostream>

using namespace std;

int main(void) {
	int cardAmount = 0, findAmount = 0;
	int temp;
	static int card[20000001];
	int* find = NULL;

	cin >> cardAmount;
	for (int i = 0; i < cardAmount; i++) {
		cin >> temp;
		card[temp + 10000000]++;
	}
	cin >> findAmount;
	find = new int[findAmount];
	for (int i = 0; i < findAmount; i++) {
		cin >> find[i];
	}
	for (int i = 0; i < findAmount; i++) {
		printf("%d ", card[find[i] + 10000000]);
	}

	delete[] find;

	return 0;
}