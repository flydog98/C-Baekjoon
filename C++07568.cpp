#include <iostream>
#include <string.h>

using namespace std;

int main(void) {
	int peopleNum;
	cin >> peopleNum;
	int **heightNweight;
	heightNweight = new int*[peopleNum];
	for (int i = 0; i < peopleNum; i++) {
		heightNweight[i] = new int[3];
		memset(heightNweight[i], 0, sizeof(int) * 3);
	}
	for (int i = 0; i < peopleNum; i++) {
		cin >> heightNweight[i][0] >> heightNweight[i][1];
	}
	for (int i = 0; i < peopleNum; i++) {
		int tempHeight = heightNweight[i][0];
		int tempWeight = heightNweight[i][1];
		for (int j = 0; j < peopleNum; j++) {
			if (tempHeight < heightNweight[j][0] && tempWeight < heightNweight[j][1]) {
				heightNweight[i][2]++;
			}
		}
		heightNweight[i][2]++;
	}

	for (int i = 0; i < peopleNum - 1; i++) {
		cout << heightNweight[i][2] << " ";
	}
	cout << heightNweight[peopleNum - 1][2] << endl;

	return 0;

}