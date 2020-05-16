// 4949�� �������� ����

#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	bool flag = true; // ������ �̷���°�
	char input = 0;
	vector<bool> vec;

	while (1) {
		flag = true;
		scanf("%c", &input);
		if (input == '.') break;// .�ΰ�� break �� ����ȴ�.

		while (input != '.') {
			if (flag) { // ������ �´� ���̶�� ������ ����
				if (input == '(') vec.push_back(false);
				else if (input == '[') vec.push_back(true);
				else if (input == ')') {
					if (vec.empty() || vec.back()) { // ���������� ����
						flag = false;
					}
					else {
						vec.pop_back();
					}
				}
				else if (input == ']') {
					if (vec.empty() || !vec.back()) { // ���������� ����
						flag = false;
					}
					else {
						vec.pop_back();
					}
				}

			}
			scanf("%c", &input);
		}
		scanf("%c", &input); // \n ó��

		if (!vec.empty()) flag = false; // ���� ���Ϳ� ���� �ִٸ� ����x
		vec.clear();

		if (flag) printf("yes\n");
		else printf("no\n");
	}

	return 0;
}