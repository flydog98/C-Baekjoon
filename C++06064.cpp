// 6064¹ø Ä«À× ´Þ·Â

#include <iostream>

using namespace std;

int main(void) {
	int tc = 0;
	int M = 0, N = 0;
	int x = 0, y = 0;
	int nowx = 1, nowy = 1;
	long long realYear = 1;

	cin >> tc;
	for (int i = 0; i < tc; i++) {
		cin >> M >> N >> x >> y;
		if (N > M) {
			int temp = M; M = N; N = temp;
			temp = x; x = y; y = temp;
		}
		realYear = x;
		nowx = x; nowy = x;
		nowy = nowy % N;
		if (nowy == 0) nowy = N;
		while (nowy != y){
			nowy += M; realYear += M;
			nowy = nowy % N;
			if (nowy == 0) nowy = N;
			if (realYear > M * N) {
				realYear = -1;
				break;
			}
		}
		cout << realYear << endl;
	}
	return 0;
}