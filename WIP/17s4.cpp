#include <iostream>
#include <cstdio>
using namespace std;
int n, m, a, b;
    float c, d, pipes[100005][100005];
int main()
{
    
    //scanf("%d %d %f", &n, &m, &d);
    cin>>n>>m>>d;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %f", &a, &b, &c);
        pipes[a][b] = pipes[b][a] = c;
    }

    //making sure input is correct
    printf(" ");
    for (int i = 0; i < n; i++)
    {
        printf("%d", i+1);
    }
    for (int i = 0; i < n; i++)
    {
        printf("\n%d", i+1);
        for (int j = 0; j < n; j++)
        {
            printf("%f", pipes[i][j]);
        }
    }

    return 0;
}
