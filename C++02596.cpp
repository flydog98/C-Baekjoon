// 2596번 비밀편지

#include <iostream>

using namespace std;

int a[8][6] = { 0, 0, 0, 0, 0, 0,
				0, 0, 1, 1, 1, 1,
				0, 1, 0, 0, 1, 1,
				0, 1, 1, 1, 0, 0,
				1, 0, 0, 1, 1, 0,
				1, 0, 1, 0, 0, 1,
				1, 1, 0, 1, 0, 1,
				1, 1, 1, 0, 1, 0 };

int decrypt(int* amount) {
	int map[8] = { 0, };
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 8; j++) {
			if (a[j][i] == amount[i]) {
				map[j]++;
			}
		}
	}
	for (int i = 0; i < 8; i++) {
		if (map[i] == 6) return i;
	}
	for (int i = 0; i < 8; i++) {
		if (map[i] == 5) return i;
	}
	return 8;
}

int main(void) {
	int amount = 0;
	char temp = 0;
	int ret[10] = { 0, };
	int ch[6] = { 0, };

	scanf("%c", &temp);
	amount = temp - '0';
	scanf("%c", &temp);

	for (int i = 0; i < amount; i++) {
		for (int j = 0; j < 6; j++) {
			scanf("%c", &temp);
			ch[j] = temp - '0';
		}
		ret[i] = decrypt(ch);
	}

	for (int i = 0; i < amount; i++) {
		if (ret[i] == 8) {
			cout << i + 1;
			return 0;
		}
	}
	for (int i = 0; i < amount; i++) {
		printf("%c", ret[i] + 65);
	}

	return 0;
}