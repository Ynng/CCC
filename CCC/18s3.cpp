#include <iostream>
using namespace std;
const int maxN = 105;
int n, m, b[maxN][maxN] = { 0 }, sh, sv;
char temp, a[maxN][maxN];
bool u, d, l, r;

void move(int h, int v, int step) {
	char current = a[h][v];
	if (current == 'W' || (b[h][v] != 0 && b[h][v] <= step)) {
		return;
	}
	else {
		switch (current) {
		case 'U':
			b[h][v] = step;
			move(h - 1, v, step);
			break;
		case 'D':
			b[h][v] = step;
			move(h + 1, v, step);
			break;
		case 'L':
			b[h][v] = step;
			move(h, v - 1, step);
			break;
		case 'R':
			b[h][v] = step;
			move(h, v + 1, step);
			break;
		case '.':
		case 'S':
			b[h][v] = step;
			move(h - 1, v, step + 1);
			move(h + 1, v, step + 1);
			move(h, v - 1, step + 1);
			move(h, v + 1, step + 1);
			break;
		}
	}

	/*if(direction!='u')move(h + 1, v, 'd');
	if (direction != 'd')move(h - 1, v, 'u');
	if (direction != 'l')move(h, v + 1, 'r');
	if (direction != 'r')move(h, v - 1, 'l');
	*/
}


int main() {

	u = d = l = r = true;
	//taking inputs
	scanf("%d %d", &n, &m);
	/*for (int i = 0; i <= m; i++) {
		scanf("%c", &temp);
	}
	for (int i = 0; i < n - 2; i++) {
		scanf("%c", &temp);
		for (int j = 0; j < m - 2; j++) {
			scanf("%c", &a[i][j]);
		}
		scanf("%c\n", &temp);
	}
	for (int i = 0; i <= m; i++) {
		scanf("%c", &temp);
	}*/
	for (int i = 0; i < n; i++) {
		scanf("%c", &temp);
		for (int j = 0; j < m; j++) {
			scanf("%c", &a[i][j]);
		}
	}


	//organizing map
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 'S') {
				sh = i;
				sv = j;
			}
			if (a[i][j] == 'C') {
				a[i][j] = 'W';
				for (int k = 1; k < maxN; k++) {
					/*if (d&&(a[i + k][j] == '.'||a[i + k][j] == 'S'))a[i + k][j] = 'W';
					if (u&&(a[i - k][j] == '.'||a[i - k][j] == 'S'))a[i - k][j] = 'W';
					if (r&&(a[i][j + k] == '.'||a[i][j + k] == 'S'))a[i][j + k] = 'W';
					if (l&&(a[i][j - k] == '.'||a[i][j - k] == 'S'))a[i][j - k] = 'W';
					if (a[i + k][j] == 'W')d = false;
					if (a[i - k][j]== 'W')u = false;
					if (a[i][j + k] == 'W')r = false;
					if (a[i][j - k] == 'W')l = false;
					if (!d&&!u&&!r&&!l)break;*/
					if (d && (a[i + k][j] == '.' || a[i + k][j] == 'S'))b[i + k][j] = -1;
					if (u && (a[i - k][j] == '.' || a[i - k][j] == 'S'))b[i - k][j] = -1;
					if (r && (a[i][j + k] == '.' || a[i][j + k] == 'S'))b[i][j + k] = -1;
					if (l && (a[i][j - k] == '.' || a[i][j - k] == 'S'))b[i][j - k] = -1;
					if (a[i + k][j] == 'W' || a[i + k][j] == 'C')d = false;
					if (a[i - k][j] == 'W' || a[i - k][j] == 'C')u = false;
					if (a[i][j + k] == 'W' || a[i][j + k] == 'C')r = false;
					if (a[i][j - k] == 'W' || a[i][j - k] == 'C')l = false;
					if (!d && !u && !r && !l)break;
				}
				d = u = r = l = true;
			}
		}
	}

	move(sh, sv, 0);
	//Output
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == '.') {
				if (b[i][j] != 0)printf("%d\n", b[i][j]);
				else printf("%d\n", -1);
			}
		}
	}

	return 0;
}
