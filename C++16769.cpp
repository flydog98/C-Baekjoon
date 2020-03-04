//16769 Mixing Milk

#include <iostream>

using namespace std;

void pouring(long long* amounta, long long maxb, long long* amountb) {
	if (*amounta + *amountb > maxb) {
		*amounta = *amounta + *amountb - maxb;
		*amountb = maxb;
	}
	else {
		*amountb += *amounta;
		*amounta = 0;
	}
}

int main(void) {
	long long max1 = 0, max2 = 0, max3 = 0;
	long long amount1 = 0, amount2 = 0, amount3 = 0;

	cin >> max1 >> amount1;
	cin >> max2 >> amount2;
	cin >> max3 >> amount3;

	for (int i = 0; i < 33; i++) {
		pouring(&amount1, max2, &amount2);
		pouring(&amount2, max3, &amount3);
		pouring(&amount3, max1, &amount1);
	}
	pouring(&amount1, max2, &amount2);

	cout << amount1 << endl;
	cout << amount2 << endl;
	cout << amount3 << endl;

	return 0;

}