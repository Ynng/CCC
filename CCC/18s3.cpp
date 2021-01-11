#include <iostream>
using namespace std;
const int maxN = 105;
int n, m, dist[maxN][maxN] = { 0 }, ih, iv;
char temp, G[maxN][maxN];
bool u, d, l, r;

void move(int h, int v, int curDist) {
	char current = G[h][v];
	if (current == 'W' || (dist[h][v] != 0 && dist[h][v] <= curDist)) 
		return;
	else {
		switch (current) {
		case 'U':
			dist[h][v] = curDist;
			move(h - 1, v, curDist);
			break;
		case 'D':
			dist[h][v] = curDist;
			move(h + 1, v, curDist);
			break;
		case 'L':
			dist[h][v] = curDist;
			move(h, v - 1, curDist);
			break;
		case 'R':
			dist[h][v] = curDist;
			move(h, v + 1, curDist);
			break;
		case '.':
		case 'S':
			dist[h][v] = curDist;
			move(h - 1, v, curDist + 1);
			move(h + 1, v, curDist + 1);
			move(h, v - 1, curDist + 1);
			move(h, v + 1, curDist + 1);
			break;
		}
	}
}


int main() {

	u = d = l = r = true;
	//taking inputs
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%c", &temp);
		for (int j = 0; j < m; j++) {
			scanf("%c", &G[i][j]);
		}
	}


	//organizing map
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (G[i][j] == 'S') {
				ih = i;
				iv = j;
			}

			//Marking spots cameras can see with wall
			if (G[i][j] == 'C') {
				G[i][j] = 'W';
				for (int k = 1; k < maxN; k++) {
					if (d && (G[i + k][j] == '.' || G[i + k][j] == 'S'))dist[i + k][j] = -1;
					if (u && (G[i - k][j] == '.' || G[i - k][j] == 'S'))dist[i - k][j] = -1;
					if (r && (G[i][j + k] == '.' || G[i][j + k] == 'S'))dist[i][j + k] = -1;
					if (l && (G[i][j - k] == '.' || G[i][j - k] == 'S'))dist[i][j - k] = -1;
					if (G[i + k][j] == 'W' || G[i + k][j] == 'C')d = false;
					if (G[i - k][j] == 'W' || G[i - k][j] == 'C')u = false;
					if (G[i][j + k] == 'W' || G[i][j + k] == 'C')r = false;
					if (G[i][j - k] == 'W' || G[i][j - k] == 'C')l = false;
					if (!d && !u && !r && !l)break;
				}
				d = u = r = l = true;
			}
		}
	}

	move(ih, iv, 0);
	//Output
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (G[i][j] == '.') {
				if (dist[i][j] != 0)printf("%d\n", dist[i][j]);
				else printf("%d\n", -1);
			}
		}
	}

	return 0;
}
