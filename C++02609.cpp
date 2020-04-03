//2609번 최대공약수와 최소공배수

#include <iostream>
#include <algorithm>

using namespace std;

void priming(int* prime, int number) {
	for (int i = 2; i < 10000; i++) {
		while (!(number % i)) {
			number /= i;
			prime[i]++;
			if (number == 1) return;
		}
	}
}

int getGCD(int* primeA, int* primeB) {
	int ret = 1;
	int temp = 0;
	for (int i = 0; i < 10000; i++) {
		if (primeA[i] && primeB[i]) {
			temp = 1;
			for (int j = 0; j < min(primeA[i], primeB[i]); j++) {
				temp *= i;
			}
			ret *= temp;
		}
	}

	return ret;
}

int getLCM(int* primeA, int* primeB) {
	int ret = 1;
	int temp = 0;
	for (int i = 0; i < 10000; i++) {
		if (primeA[i] || primeB[i]) {
			temp = 1;
			for (int j = 0; j < max(primeA[i], primeB[i]); j++) {
				temp *= i;
			}
			ret *= temp;
		}
	}

	return ret;
}

int main(void) {
	int a = 0, b = 0;
	int primeA[10000] = { 0, };
	int primeB[10000] = { 0, };

	cin >> a >> b;

	priming(primeA, a);
	priming(primeB, b);

	cout << getGCD(primeA, primeB) << endl;
	cout << getLCM(primeA, primeB) << endl;

	return 0;
}