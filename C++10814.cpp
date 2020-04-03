// 10814번 나이순 정렬

#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(void) {
	int amount = 0;
	queue<string> member[201];
	int age = 0;
	string name;

	cin >> amount;

	for (int i = 0; i < amount; i++) {
		cin >> age >> name;
		member[age].push(name);
	}

	for (int i = 1; i < 201; i++) {
		while (!member[i].empty()) {
			name = member[i].front(); member[i].pop();
			cout << i << ' ' << name << '\n';
		}
	}

	return 0;
}