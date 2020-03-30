//11050번 이항 계수 1

#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int n = 0, k = 0;
	int ans = 1;

	cin >> n >> k;

	if (k > (n / 2)) k = n - k;
	for (int i = 0; i < k; i++) {
		ans *= (n - i);
	}
	for (int i = 0; i < k; i++) {
		ans /= (i + 1);
	}

	cout << ans << endl;

	return 0;
}