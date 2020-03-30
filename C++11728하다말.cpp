//11728번 배열 합치기

#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int amounta = 0, amountb = 0;
	long long temp1 = 0;
	static vector<long long> arra[1000000];
	static vector<long long> arrb[1000000];

	scanf("%d %d", &amounta, &amountb);

	for (int i = 0; i < amounta; i++) {
		cin >> temp1;
		arra->push_back(temp1);
	}

	for (int i = 0; i < amountb; i++) {
		cin >> temp1;
		arrb->push_back(temp1);
	}


}