// 2863번 이게 분수?

#include <iostream>

using namespace std;
 
double swap(int a, int b, int c, int d) {
	double temp1 = 0, temp2 = 0;
	temp1 = a / c; temp2 = b / d;

	return temp1 + temp2;
}

int main(void) {
	int a = 0, b = 0, c = 0, d = 0;
	double ttemp = 0;
	double max = 0;
	int ret = 0;

	cin >> a >> b >> c >> d;

	ttemp = swap(b, d, a, c);
	if (ttemp > max) {
		max = ttemp;
		ret = 3;
	}
	ttemp = swap(d, c, b, a);
	if (ttemp > max) {
		max = ttemp;
		ret = 2;
	}
	ttemp = swap(c, a, d, b);
	if (ttemp > max) {
		max = ttemp;
		ret = 1;
	}
	ttemp = swap(a, b, c, d);
	if (ttemp > max) {
		max = ttemp;
		ret = 0;
	}
	//코드 중복을 막는 방법이 생각나지만 구현의 속도를 중시해서 복붙했다


	cout << ret;

	return 0;

}