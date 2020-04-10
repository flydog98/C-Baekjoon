// 1259번 팰린드롬수

#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string input;
	bool isPalin = false;

	cin >> input;
	while (input != "0") {
		isPalin = false;
		switch (input.length()) {
		case 5:
			if ((input[0] == input[4]) && (input[1] == input[3]))
				isPalin = true;
			break;
		case 4:
			if ((input[0] == input[3]) && (input[1] == input[2]))
				isPalin = true;
			break;
		case 3:
			if (input[0] == input[2])
				isPalin = true;
			break;
		case 2:
			if (input[0] == input[1])
				isPalin = true;
			break;
		case 1:
			isPalin = true;
			break;
		default:
			break;
		}
		if (isPalin) cout << "yes" << endl;
		else cout << "no" << endl;

		cin >> input;
	}

	return 0;
}