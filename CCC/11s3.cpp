#include <iostream>
using namespace std;

bool question(int m, int mtop, int x, int y)
{
    if (((x/pow(5,m-1)) % 5 == 1 && y % 5 == 0) || (x % 5 == 2 && y % 5 == 0) || (x % 5 == 3 && y % 5 == 0) || (x % 5 == 2 && y % 5 == 1))
        return 1;
    else if ((x % 5 == 1 && y % 5 == 1) || (x % 5 == 3 && y % 5 == 1) || (x % 5 == 2 && y % 5 == 2))
        return -1;
    else
        return question
}

int main()
{
    int t, m, x, y, answers[15];
    scanf("%d", &t);
    for (int testcase = 0; testcase < t; testcase++)
    {
        scanf("%d %d %d", &m, &x, &y);
        answers[testcase] = question(1,m, x, y);
    }
    for (int testcase = 0; testcase < t; testcase++)
    {
        if (answers[testcase] == -1)
            printf("empty");
        else
            printf("crystal");
    }
    return 0;
}
