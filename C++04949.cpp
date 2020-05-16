// 4949번 균형잡힌 세상

#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	bool flag = true; // 균형을 이루었는가
	char input = 0;
	vector<bool> vec;

	while (1) {
		flag = true;
		scanf("%c", &input);
		if (input == '.') break;// .인경우 break 후 종료된다.

		while (input != '.') {
			if (flag) { // 균형이 맞는 중이라면 루프를 돈다
				if (input == '(') vec.push_back(false);
				else if (input == '[') vec.push_back(true);
				else if (input == ')') {
					if (vec.empty() || vec.back()) { // 균형잡히지 않음
						flag = false;
					}
					else {
						vec.pop_back();
					}
				}
				else if (input == ']') {
					if (vec.empty() || !vec.back()) { // 균형잡히지 않음
						flag = false;
					}
					else {
						vec.pop_back();
					}
				}

			}
			scanf("%c", &input);
		}
		scanf("%c", &input); // \n 처리

		if (!vec.empty()) flag = false; // 만약 벡터에 값이 있다면 균형x
		vec.clear();

		if (flag) printf("yes\n");
		else printf("no\n");
	}

	return 0;
}