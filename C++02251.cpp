// 2251¹ø ¹·Åë

#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

int main(void) {
	int a = 0, b = 0, c = 0;
	static bool check[201][201][201];
	bool checkc[201];
	queue<int> qa;
	queue<int> qb;
	queue<int> qc;

	memset(check, 0, sizeof(check));
	memset(checkc, 0, sizeof(checkc));

	cin >> a >> b >> c;

	check[0][0][c] = true;
	checkc[c] = true;

	qa.push(0);
	qb.push(0);
	qc.push(c);

	while (!qa.empty()) {
		int tempa = qa.front();
		int tempb = qb.front();
		int tempc = qc.front();

		qa.pop();
		qb.pop();
		qc.pop();

		if (tempa != 0) {
			//a -> b
			if (tempb != b) {
				int toa = max(tempa + tempb - b, 0);
				int tob = tempa - toa + tempb;
				if (!check[toa][tob][tempc]) {
					check[toa][tob][tempc] = true;
					if (toa == 0) checkc[tempc] = true;
					qa.push(toa);
					qb.push(tob);
					qc.push(tempc);
				}
			}

			//a -> c
			if (tempc != c) {
				int toa = max(tempa + tempc - c, 0);
				int toc = tempa - toa + tempc;
				if (!check[toa][tempb][toc]) {
					check[toa][tempb][toc] = true;
					if(toa == 0) checkc[toc] = true;
					qa.push(toa);
					qb.push(tempb);
					qc.push(toc);
				}
			}
		}

		if (tempb != 0) {
			//b -> a
			if (tempa != a) {
				int tob = max(tempb + tempa - a, 0);
				int toa = tempb - tob + tempa;
				if (!check[toa][tob][tempc]) {
					check[toa][tob][tempc] = true;
					if (toa == 0) checkc[tempc] = true;
					qa.push(toa);
					qb.push(tob);
					qc.push(tempc);
				}
			}

			//b -> c
			if (tempc != c) {
				int tob = max(tempb + tempc - c, 0);
				int toc = tempb - tob + tempc;
				if (!check[tempa][tob][toc]) {
					check[tempa][tob][toc] = true;
					if(tempa == 0) checkc[toc] = true;
					qa.push(tempa);
					qb.push(tob);
					qc.push(toc);
				}
			}
		}

		if (tempc != 0) {
			//c -> a
			if (tempa != a) {
				int toc = max(tempc + tempa - a, 0);
				int toa = tempc - toc + tempa;
				if (!check[toa][tempb][toc]) {
					check[toa][tempb][toc] = true;
					if(toa == 0) checkc[toc] = true;
					qa.push(toa);
					qb.push(tempb);
					qc.push(toc);
				}
			}

			//c -> b
			if (tempb != b) {
				int toc = max(tempc + tempb - b, 0);
				int tob = tempc - toc + tempb;
				if (!check[tempa][tob][toc]) {
					check[tempa][tob][toc] = true;
					if(tempa == 0) checkc[toc] = true;
					qa.push(tempa);
					qb.push(tob);
					qc.push(toc);
				}
			}
		}

	}

	for (int j = 0; j < 201; j++) {
		if (checkc[j]) {
			printf("%d ", j);
		}
	}


	return 0;
}