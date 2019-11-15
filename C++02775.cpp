// 2775번 부녀회장이 될테야

#include <iostream>
#include <cstring>

using namespace std;

int main(void) {
	int tc = 0;
	int story = 0, nth = 0;
	long long apart[15][15];
	
	memset(apart, 0, sizeof(apart));
	for (int i = 1; i < 15; i++) {
		apart[0][i] = i;
	}
	for (int i = 1; i < 15; i++) {
		for (int j = 1; j < 15; j++) {
			for (int k = 1; k <= j; k++) {
				apart[i][j] += apart[i - 1][k];
			}
		}
	}

	cin >> tc;
	for (int i = 0; i < tc; i++) {
		cin >> story >> nth;
		cout << apart[story][nth] << endl;
	}
	return 0;
}