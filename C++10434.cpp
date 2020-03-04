//10434 행복한 소수

#include <iostream>

using namespace std;

int numbercalc(int number) {
	int ret = 0, temp = 0;
	while (number != 0) {
		temp = number % 10;
		ret += temp * temp;
		number /= 10;
	}

	return ret;
}

int ishappy(int number, int* happy) {
	switch (happy[number]) {
	case 0:
		happy[number] = 3;
		happy[number] = ishappy(numbercalc(number), happy);
		return happy[number];
	case 1:
		happy[number] = 1;
		return 1;
	case 2:
		happy[number] = 2;
		return 2;
	case 3:
		happy[number] = 2;
		return 2;
	}
}

int main(void) {
	//0 : 판별안됨 혹은 소수, 1 : 합성수, 2 : 0 혹은 1
	int prime[10001] = { 0, };
	//0 : 모르는거, 1 : 행복한 수, 2 : 행복한 수 아님, 3 : 현재 판별 중
	int happy[10001] = { 0, };

	prime[0] = 2, prime[1] = 2;
	happy[0] = 2, happy[1] = 1;

	for (int i = 2; i < 100; i++) {
		if (!prime[i]) {
			for (int j = i + i; j <= 10000; j += i) {
				prime[j] = 1;
			}
		}
	}

	for (int i = 2; i <= 10000; i++) {
		if (!happy[i]) {
			ishappy(i, happy);
		}
	}

	int loop = 0;
	int no = 0, number = 0;
	cin >> loop;
	for (int i = 0; i < loop; i++) {
		scanf("%d %d", &no, &number);
		printf("%d %d ", no, number);
		if ((!prime[number]) && happy[number] == 1) printf("YES\n");
		else printf("NO\n");
	}


	return 0;
}