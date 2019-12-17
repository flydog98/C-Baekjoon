//1011¹ø Fly me to the Alpha Centauri

#include <iostream>

using namespace std;

int main(void) {
	int tc = 0, a = 0, b = 0;

	cin >> tc;
	for (int i = 0; i < tc; i++) {
		cin >> a >> b;
		int temp = b - a;
		int ret = 0, amount = 1, flag = 0;
		while (temp > 0) {
			temp -= amount;
			if (flag) {
				amount++;
				flag = 0;
			}
			else { flag = 1; }
			ret++;
		}

		cout << ret << endl;
	}

	return 0;
}