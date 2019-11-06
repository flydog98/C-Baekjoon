#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//A : 97, Z : 122

int main(void) {
	string input;
	cin >> input;
	vector<string> str(input.size());
	int bracket_count = 0;
	int bracket_max = 0;
	int bracket_temp = 0;

	vector<string>::iterator iter = str.begin();

	for (int i = 0; i < input.size(); i++) {
		str[i] = input[i];
		if (input[i] == '(') {
			bracket_count++;
			bracket_temp++;
			bracket_max = max(bracket_temp, bracket_max);
		}
		if (input[i] = ')') {
			bracket_temp--;
		}

	}

	while (bracket_count) {
		vector<int> temp_bracket_start(bracket_max);
		
		bool max_bracket_on = false;
		for (int strcount = 0; strcount < str.size(); strcount++) {
			//strcount == 현재 조사 중인 str의 위치
			string temp = str[strcount];
			if (temp == "(") temp_bracket_start.push_back(strcount);

			if (temp == ")") {
				str.erase(iter + strcount);
				str.erase(iter + temp_bracket_start.back());
				strcount -= 2;
				for (int i = temp_bracket_start.back(); i < strcount; i++) {
					string bracket_temp = str[i];

					if (bracket_temp == "+" || bracket_temp == "-") {
						str[i - 1] += str[i + 1] + bracket_temp;
						iter = str.begin();
						str.erase(iter + i, iter + i + 2);
						i--;
						strcount -= 2;
					}
				}
				temp_bracket_start.pop_back();
				bracket_count--;
				while (strcount != 0 && (str[strcount - 1] == "*" || str[strcount - 1] == "/")) {
					str[strcount - 2] += str[strcount] + str[strcount - 1];
					iter = str.begin();
					str.erase(iter + strcount - 1, iter + strcount + 1);
					strcount -= 2;
				}
			}


			if (temp == "*" || temp == "/") {
				if (str[strcount - 1] != ")" && str[strcount + 1] != "(") {
					str[strcount - 1] += str[strcount + 1] + temp;
					iter = str.begin();
					str.erase(iter + strcount, iter + strcount + 2);//삭제가 일어났으므로 다시 원래 자리로 옮김
					strcount--;
					temp = str[strcount];//일관성을 위해 다시 만든다
				}
			}
		}
	}

	for (int i = 0; i < str.size(); i++) {
		string temp = str[i];
		if (temp == "*" || temp == "/") {
			str[i - 1] += str[i + 1] + temp;
			iter = str.begin();
			str.erase(iter + i, iter + i + 2);
			i--;
		}
	}

	for (int i = 0; i < str.size(); i++) {
		string temp = str[i];
		if (temp == "+" || temp == "-") {
			str[i - 1] += str[i + 1] + temp;
			iter = str.begin();
			str.erase(iter + i, iter + i + 2);
			i--;
		}
	}


	cout << str[0] << endl;


	
	return 0;
}