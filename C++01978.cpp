// 1978번 소수 찾기

#include <iostream>

using namespace std;

int main(void) {
	int amount = 0, temp = 0, ans = 0;
	int numbers[1001] = { 2, 2, 0 }; //0 아직안감, 1 소수, 2 소수아님

	for (int i = 2; i < 1001; i++) {
		if (!numbers[i]) { //아직안감
			numbers[i] = 1;
			for (int j = 2 * i; j < 1001; j += i) {
				numbers[j] = 2;
			}
		}
		//이론 상 이미 1인 경우는 없음, 2인 경우는 루프를 패스
	}

	cin >> amount;

	for (int i = 0; i < amount; i++) {
		cin >> temp;
		if (numbers[temp] == 1) ans++;
	}

	cout << ans << endl;

	return 0;
}