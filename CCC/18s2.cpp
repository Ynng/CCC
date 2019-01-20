#include <iostream>
using namespace std;
const int maxN = 105;
int a[maxN][maxN], N, base;
bool vertical, horizontal;
int main() {
	vertical = horizontal = true;
	//taking inputs
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	//determining its orientation
	base = a[0][0];
	for (int i = 1; i < N; i++) {
		if (a[0][i] <= base){
			horizontal = false;
			break;
		}
	}
	for (int i = 1; i < N; i++) {
		if (a[i][0] <= base) {
			vertical = false;
			break;
		}
	}
	//output
	if(horizontal&&vertical){
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N-1; j++) {
				printf("%d ", a[i][j]);
			}
			printf("%d\n", a[i][N-1]);
		}
	}else if (!horizontal&&vertical) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N - 1; j++) {
				printf("%d ", a[j][N - i - 1]);
			}
			printf("%d\n", a[N - 1][N - i - 1]);
		}
	}else if (horizontal&&!vertical) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N - 1; j++) {
				printf("%d ", a[N - j - 1][i]);
			}
			printf("%d\n", a[0][i]);
		}
	}else if (!horizontal && !vertical) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N - 1; j++) {
				printf("%d ", a[N - i - 1][N - j - 1]);
			}
			printf("%d\n", a[N - i - 1][0]);
		}
	}
	return 0;
}
