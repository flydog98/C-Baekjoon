//10866¹ø µ¦

#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int amount = 0;
	string command; int temp = 0;
	static int deque[20001];
	int head = 10000;
	int tail = 10000;

	cin >> amount;

	for (int i = 0; i < amount; i++) {
		cin >> command;
		if (command == "push_front") {
			cin >> temp;
			if(head != tail || deque[head] != 0) head--;
			deque[head] = temp;
		}
		else if (command == "push_back") {
			cin >> temp;
			if(head != tail || deque[tail] != 0) tail++;
			deque[tail] = temp;
		}
		else if (command == "pop_front") {
			if (head == tail && deque[head] == 0) {
				cout << -1 << endl;
			}
			else {
				cout << deque[head] << endl;
				deque[head] = 0;
				if (head != tail) head++;
			}
		}
		else if (command == "pop_back") {
			if (head == tail && deque[tail] == 0) {
				cout << -1 << endl;
			}
			else {
				cout << deque[tail] << endl;
				deque[tail] = 0;
				if (head != tail) tail--;
			}
		}
		else if (command == "size") {
			if (head == tail) {
				if(deque[head] != 0)
					cout << 1 << endl;
				else cout << 0 << endl;
			}
			else {
				cout << tail - head + 1<< endl;
			}
		}
		else if (command == "empty") {
			if (head == tail && deque[head] == 0)
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
		else if (command == "front") {
			if (deque[head] != 0)
				cout << deque[head] << endl;
			else
				cout << -1 << endl;
		}
		else if (command == "back") {
			if (deque[tail] != 0)
				cout << deque[tail] << endl;
			else
				cout << -1 << endl;
		}
	}

	return 0;
}