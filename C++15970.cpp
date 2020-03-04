//15970번 화살표 그리기

#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

class info {
public:
	int loc;
	int color;
};

int main(void) {
	int amount = 0;
	int inputloc = 0, inputcolor = 0;
	int mina = 0, minb = 0;
	int nowcolor = 0, nowloc = 0;;
	int ret = 0;
	info spot[5000];

	cin >> amount;
	for (int i = 0; i < amount; i++) {
		scanf("%d %d", &inputloc, &inputcolor);
		spot[i].loc = inputloc;
		spot[i].color = inputcolor;
	}

	for (int i = 0; i < amount; i++) {
		mina = 1000000, minb = 1000000;
		nowcolor = spot[i].color;
		nowloc = spot[i].loc;
		for (int j = i + 1; j < amount; j++) {
			if (nowcolor == spot[j].color) {
				mina = min(mina, abs(spot[j].loc - nowloc));
			}
		}
		for (int j = i - 1; j >= 0; j--) {
			if (nowcolor == spot[j].color) {
				minb = min(minb, abs(spot[j].loc - nowloc));
			}
		}
		ret += min(mina, minb);
	}
	cout << ret;

	return 0;
}