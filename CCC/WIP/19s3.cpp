#include <iostream>
using namespace std;
int input[3][3], conter;
bool xory = true;
int solveX(int x, int y)
{
    int xp;
    switch (x)
    {
    case 0:
        if (input[1][y] == -1 && input[2][y] == -1)
            break;
        if (input[1][y] != -1 && input[2][y] != -1)
        {
            input[x][y] = input[1][y] - (input[2][y] - input[1][y]);
            xp = 2;
            break;
        }
        else if (input[1][y] != -1)
            input[x][y] = input[1][y];
        else if (input[2][y] != -1)
            input[x][y] = input[2][y];
        xp = 1;
        break;

    case 1:
        if (input[0][y] == -1 && input[2][y] == -1)
            break;
        if (input[0][y] != -1 && input[2][y] != -1)
        {
            input[x][y] = (input[2][y] - input[0][y]) / 2 + input[0][y];
            xp = 2;
            break;
        }
        else if (input[0][y] != -1)
            input[x][y] = input[0][y];
        else if (input[2][y] != -1)
            input[x][y] = input[2][y];
        xp = 1;
        break;

    case 2:
        if (input[0][y] == -1 && input[1][y] == -1)
            break;
        if (input[0][y] != -1 && input[1][y] != -1)
        {
            input[x][y] = input[1][y] + (input[1][y] - input[0][y]);
            xp = 2;
            break;
        }
        else if (input[0][y] != -1)
            input[x][y] = input[0][y];
        else if (input[1][y] != -1)
            input[x][y] = input[1][y];
        xp = 1;
        break;
    }
    return xp;
}

int solveY(int x, int y)
{
    int yp;
    switch (y)
    {
    case 0:
        if (input[x][1] == -1 && input[x][2] == -1)
            break;
        if (input[x][1] != -1 && input[x][2] != -1)
        {
            input[x][y] = input[x][1] - (input[x][2] - input[x][1]);
            yp = 2;
            break;
        }
        else if (input[x][1] != -1)
            input[x][y] = input[x][1];
        else if (input[x][2] != -1)
            input[x][y] = input[x][2];
        yp = 1;
        break;

    case 1:
        if (input[x][0] == -1 && input[x][2] == -1)
            break;
        if (input[x][0] != -1 && input[x][2] != -1)
        {
            input[x][y] = (input[x][2] - input[x][0]) / 2 + input[x][0];
            yp = 2;
            break;
        }
        else if (input[x][0] != -1)
            input[x][y] = input[x][0];
        else if (input[x][2] != -1)
            input[x][y] = input[x][2];
        yp = 1;
        break;

    case 2:
        if (input[x][0] == -1 && input[x][1] == -1)
            break;
        if (input[x][0] != -1 && input[x][1] != -1)
        {
            input[x][y] = input[x][1] + (input[x][1] - input[x][0]);
            yp = 2;
            break;
        }
        else if (input[x][0] != -1)
            input[x][y] = input[x][0];
        else if (input[1][y] != -1)
            input[x][y] = input[x][1];
        yp = 1;
        break;
    }
    return yp;
}

bool checkX(int y)
{
    if (!(input[0][y] != -1 && input[1][y] != -1 && input[2][y] != -1))
        return true;
    if (input[1][y] - input[0][y] == input[2][y] - input[1][y])
        return true;
    else
        return false;
}

bool checkY(int x)
{
    if (!(input[x][0] != -1 && input[x][1] != -1 && input[x][2] != -1))
        return true;
    if (input[x][1] - input[x][0] == input[x][2] - input[x][1])
        return true;
    else
        return false;
}

void solve(int x, int y)
{
    int xp, yp;
    if (xory)
    {
        xp = solveX(x, y);
        if (checkY(x))
            xp = 3;
        yp = solveY(x, y);
        if (checkX(y))
            yp = 3;
    }
    else
    {
        yp = solveY(x, y);
        if (checkX(y))
            yp = 3;
        xp = solveX(x, y);
        if (checkY(x))
            xp = 3;
    }

    if (xp > yp)
    {
        solveX(x, y);
    }
    else if (yp > xp)
    {
        solveY(x, y);
    }
}

void solveMain()
{
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            if (input[x][y] == -1)
            {
                solve(x, y);
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (!checkX(i))
        {
            xory = !xory;
            solveMain();
            conter++;
            break;
        }
        if (!checkY(i))
        {
            xory = !xory;
            solveMain();
            conter++;
            break;
        }
        if (conter > 3)
            return;
    }
}

int main()
{
    string temp;
    conter = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> temp;
            if (temp == "X")
                input[i][j] = -1;
            else
                input[i][j] = std::stoi(temp, nullptr);
        }
    }
    solveMain();
    for (int i = 0; i < 3; i++)
    {
        printf("%d %d %d\n", input[i][0], input[i][1], input[i][2]);
    }
    return 0;
}