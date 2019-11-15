// 10250¹ø ACMÈ£ÅÚ

#include <iostream>

using namespace std;

int main(void) {
	int repeat = 0;
	int story = 0, room = 0, nth = 0;
	int x = 0, y = 0;
	int i = 0;

	cin >> repeat;

	for (int aaa = 0; aaa < repeat; aaa++) {
		cin >> story >> room >> nth;
		for (i = 0; nth > 0; i++) {
			nth -= story;
		}
		x = i;
		y = nth + story;
		cout << y;
		if (i < 10) cout << 0;
		cout << x << endl;
	}
	return 0;
}