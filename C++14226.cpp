#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int main(void) {
	int input;
	static int dest[2000][2000];

	memset(dest, 0, sizeof(dest));
	int temp;
	int tempcli;
	queue<int> clip;
	queue<int> no;

	cin >> input;

	no.push(1);
	clip.push(0);
	while (!no.empty()) {
		temp = no.front();
		tempcli = clip.front();
		if (temp == input) break;
		int a = dest[temp][tempcli];
		no.pop();
		clip.pop();

		if (temp > 1 && (!dest[temp - 1][tempcli])) {
			dest[temp - 1][tempcli] = a + 1;
			no.push(temp - 1);
			clip.push(tempcli);
		}

		if (temp != tempcli && (!dest[temp][temp])) {
			dest[temp][temp] = a + 1;
			no.push(temp);
			clip.push(temp);
		}

		if (temp + tempcli < 2000 && (!dest[temp + tempcli][tempcli])) {
			dest[temp + tempcli][tempcli] = a + 1;
			no.push(temp + tempcli);
			clip.push(tempcli);
		}
	}

	cout << dest[temp][tempcli] << endl;

	return 0;
}