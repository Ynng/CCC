#include <iostream>
using namespace std;
int x, y, n, xs, ys, xe, ye, winds[105][105], time, tempX, tempY;
int main()
{
    scanf("%d %d %d", &x, &y, &n);
    scanf("%d %d", &xs, &ys);
    scanf("%d %d", &xe, &ye);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &tempX, &tempY);
        winds[tempX][tempY] = true;
    }

    cout << time << endl;
    return 0;
}