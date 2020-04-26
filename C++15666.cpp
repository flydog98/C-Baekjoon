// 15666¹ø N°ú M

#include <iostream>
#include <algorithm>

using namespace std;

void printprint(int* print, int M) {
	for (int i = 0; i < M; i++) {
		printf("%d ", print[i]);
	}
	printf("\n");

	return;
}

int main(void) {
	int N = 0, M = 0;
	int temp = 1;
	int input[8] = { 0, };
	int output[8] = { 0, };
	int print[8] = { 0, };

	scanf("%d", &N); scanf("%d", &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &input[i]);
	}
	sort(input, input + N);

	output[0] = input[0];
	for (int i = 1; i < N; i++) {
		if (!(input[i - 1] == input[i])) {
			output[temp] = input[i];
			temp++;
		}
	}

	for (int i = 0; i < temp; i++) {
		print[0] = output[i];
		if(M > 1)
		for (int j = i; j < temp; j++) {
			print[1] = output[j];
			if(M > 2)
			for (int k = j; k < temp; k++) {
				print[2] = output[k];
				if(M > 3)
				for (int l = k; l < temp; l++) {
					print[3] = output[l];
					if(M > 4)
					for (int m = l; m < temp; m++) {
						print[4] = output[m];
						if(M > 5)
						for (int n = m; n < temp; n++) {
							print[5] = output[n];
							if(M > 6)
							for (int o = n; o < temp; o++) {
								print[6] = output[o];
								if(M > 7)
								for (int p = o; p < temp; p++) {
									print[7] = output[p];
									printprint(print, M);
								}
								else printprint(print, M);
							}
							else printprint(print, M);
						}
						else printprint(print, M);
					}
					else printprint(print, M);
				}
				else printprint(print, M);
			}
			else printprint(print, M);
		}
		else printprint(print, M);
	}


	return 0;
}