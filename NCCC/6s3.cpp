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

    // for (int i = 0; i < x; i++)
    // {
    //     for (int j = 0; j < y; j++)
    //     {
    //         winds[i][j] = false;
    //     }
    // }
    time = step(0, xs, ys, 0, 0);
    cout << time << endl;
    return 0;
}

int step(int time, int x, int y, int vx, int vy)
{
    //checking for the wind
    if (vx > 0)
    {
        for (int i = x; i < x + vx; i++)
        {
            if(it)
        }
    }
    else if (vx < 0)
    {
        for (int i = x; i > x - vx; i--)
        {
        }
    }
    if (vx > 0)
    {
        for (int i = x; i < x + vx; i++)
        {
        }
    }
    else if (vx < 0)
    {
        for (int i = x; i > x - vx; i--)
        {
        }
    }

    step()
}