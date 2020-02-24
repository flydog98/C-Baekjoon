// 2108 ≈Î∞Ë«–

#include <iostream>

using namespace std;

int main(void) {
	//input amount
	int input = 0, h_input = 0;;
	//temporary values
	int temp = 0;
	int now = 0;
	//for mean
	long long sum = 0;
	double mean = 0;
	//for median
	int median = 0;
	int tick = 0;
	//for mode
	int mode = 0;
	//for range
	int min = -1, max = -1, range = 0;

	int store[8001];
	memset(store, 0, sizeof(store));

	cin >> input;
	h_input = input / 2;

	for (int i = 0; i < input; i++) {
		cin >> temp;
		store[temp + 4000]++;
	}

	for (int i = 0; i < 8001; i++) {
		now = store[i];
		for (int j = 0; j < now; j++) {
			sum += (i - 4000);
			if (tick == h_input) {
				median = i - 4000;
			}
			else tick++;
		}
		
	}



	return 0;
}