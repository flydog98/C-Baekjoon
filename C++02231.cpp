#include <iostream>
#include <cmath>

using namespace std;

int construct(int decompositionSum);

int main(void) {
	int decompositionSum;
	cin >> decompositionSum;
	cout << construct(decompositionSum) << endl;
	return 0;
}

int construct(int decompositionSum) {
	int i = 0;
	int constructor = 0;
	while (i < decompositionSum) {
		int temp = (int)log10(decompositionSum);
		int tempSum = i; //이번 루프에서의 sum
		double tempJari = i / pow(10, temp);
		for (int j = 0; j < temp + 1; j++) {
			int sumTemp = (int)tempJari;
			tempSum += sumTemp;
			tempJari -= sumTemp;
			tempJari *= 10;
			tempJari += 0.00000001;
		}
		if (tempSum == decompositionSum) {
			constructor = i;
			break;
		}

		i++;
	}

	return constructor;
}