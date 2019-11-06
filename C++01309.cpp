#include <iostream>

using namespace std;

int main(void) {
	/*arr[i][0] = arr[i - 1][0] + arr[i - 1][1]
	arr[i][1] = arr[i - 1][0] * 2 + arr[i - 1][1];*/

	int input = 0;
	int result = 0;
	cin >> input;

	int cage[100000][2];
	for (int i = 0; i < input; i++) {#include <iostream>

using namespace std;

int main(void) {
	/*arr[i][0] = arr[i - 1][0] + arr[i - 1][1]
	arr[i][1] = arr[i - 1][0] * 2 + arr[i - 1][1];*/

	int input = 0;
	int result = 0;
	cin >> input;

	int cage[100000][2];
	for (int i = 0; i < input; i++) {
		cage[i][0] = 0;
		cage[i][1] = 0;
	}
	cage[0][0] = 1;
	cage[0][1] = 2;

	for (int i = 1; i < input; i++ ) {
		cage[i][0] = (cage[i - 1][0] + cage[i - 1][1]) % 9901;
		cage[i][1] = (cage[i - 1][0] * 2 + cage[i - 1][1]) % 9901; 
	}

	result = (cage[input - 1][0] + cage[input - 1][1]) % 9901;

	cout << result << endl;
	
	return 0;

}
		cage[i][0] = 0;
		cage[i][1] = 0;
	}
	cage[0][0] = 1;
	cage[0][1] = 2;

	for (int i = 1; i < input; i++ ) {
		cage[i][0] = (cage[i - 1][0] + cage[i - 1][1]) % 9901;
		cage[i][1] = (cage[i - 1][0] * 2 + cage[i - 1][1]) % 9901; 
	}

	result = (cage[input - 1][0] + cage[input - 1][1]) % 9901;

	cout << result << endl;
	
	return 0;

}