//10804번 카드 역배치

#include <iostream>

using namespace std;

void change(int* a, int* b) {
	int temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main(void) {
	int from = 0, to = 0;
	int card[20];

	for (int i = 0; i < 20; i++) {
		card[i] = i + 1;
	}

	for (int i = 0; i < 10; i++) {
		cin >> from >> to;

		while (from < to) {
			change(&card[from - 1], &card[to - 1]);
			from++, to--;
		}

	}

	for (int i = 0; i < 20; i++) {
		printf("%d ", card[i]);
	}

	return 0;

}