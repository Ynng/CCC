#include <iostream>
using namespace std;
int input[4][4];

void solveA()
{
    for (int i = 0; i < 3; i++)
    {
        if (input[i][3] == 1)
        {
            if (input[i][0] == 1000005)
            {
                input[i][0] = input[i][1] - (input[i][2] - input[i][1]);
                input[3][0]--;
            }
            else if (input[i][1] == 1000005)
            {
                input[i][1] = input[i][0] + (input[i][2] - input[i][0]) / 2;
                input[3][1]--;
            }
            else if (input[i][2] == 1000005)
            {
                input[i][2] = input[i][1] + (input[i][1] - input[i][0]);
                input[3][2]--;
            }

            input[i][3]--;
        }
        if (input[3][i] == 1)
        {
            if (input[0][i] == 1000005)
            {
                input[0][i] = input[1][i] - (input[2][i] - input[1][i]);
                input[0][3]--;
            }
            else if (input[1][i] == 1000005)
            {
                input[1][i] = input[0][i] + (input[2][i] - input[0][i]) / 2;
                input[1][3]--;
            }
            else if (input[2][i] == 1000005)
            {
                input[2][i] = input[1][i] + (input[1][i] - input[0][i]);
                input[2][3]--;
            }
            input[3][i]--;
        }
    }
}

bool checkA()
{
    for (int i = 0; i < 3; i++)
    {
        if (input[i][3] == 1)
        {
            return true;
        }
        if (input[3][i] == 1)
        {
            return true;
        }
    }
    return false;
}

void solveB()
{

    if (input[0][3] == 0 && input[3][0] == 0)
    {
        input[1][1] = input[0][1] + (input[1][0] - input[0][0]);
    }
    else if (input[2][3] == 0 && input[3][0] == 0)
    {
        input[1][1] = input[2][1] - (input[1][0] - input[0][0]);
    }
    else if (input[0][3] == 0 && input[3][2] == 0)
    {
        input[1][1] = input[0][1] + (input[1][2] - input[0][2]);
    }
    else if (input[2][3] == 0 && input[3][2] == 0)
    {
        input[1][1] = input[2][1] - (input[1][2] - input[0][2]);
    }
    input[1][3]--;
    input[3][1]--;
}

bool checkB()
{
    int countA = 0, countB = 0;
    for (int i = 0; i < 3; i++)
    {
        if (input[3][i] == 0)
        {
            countB++;
        }
        if (input[3][i] == 0)
        {
            countB++;
        }
        if (input[i][3] == 2)
        {
            countA++;
        }
        if (input[3][i] == 2)
        {
            countA++;
        }
    }
    if (countA == 4 && countB == 2)
        return true;
    else
        return false;
}

void solveC()
{
    if (input[1][1] == 1000005)
    {
        if (input[1][0] != 1000005)
            input[1][1] = input[1][0];
        else if (input[1][2] != 1000005)
            input[1][1] = input[1][2];
        else if (input[0][1] != 1000005)
            input[1][1] = input[0][1];
        else if (input[2][1] != 1000005)
            input[1][1] = input[2][1];
        input[1][3]--;
        input[3][1]--;
    }
    else
    {
        input[0][1] = input[1][1];
        input[0][3]--;
        input[1][3]--;
    }
}

bool checkC()
{
    int count = 0;
    for (int i = 0; i < 3; i++)
    {
        if (input[3][i] == 2)
        {
            count++;
        }
        if (input[3][i] == 2)
        {
            count++;
        }
    }
    if (count == 6)
        return true;
    else
        return false;
}

bool checkD()
{
    int countA = 0, countB = 0, conutC = 0; countD = 0;
    for (int i = 0; i < 3; i++)
    {
        if (input[3][i] == 0)
        {
            count++;
        }
        if (input[3][i] == 2)
        {
            count++;
        }
    }
    if (count == 6)
        return true;
    else
        return false;
}

int main()
{
    string temp;
    for (int i = 0; i < 3; i++)
    {
        input[i][3] = 0;
        input[3][i] = 0;
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cin >> temp;
            if (temp == "X")
            {
                input[i][j] = 1000005;
                input[i][3]++;
                input[3][j]++;
            }
            else
                input[i][j] = std::stoi(temp, nullptr);
        }
    }
    while (checkA())
    {
        solveA();
    }

    // printf("\n");
    // for (int i = 0; i < 4; i++)
    // {
    //     printf("%d %d %d %d\n", input[i][0], input[i][1], input[i][2], input[i][3]);
    // }

    if (checkB())
    {
        solveB();
        while (checkA())
        {
            solveA();
        }
    }

    if (checkC())
    {
        solveC();
        while (checkA())
        {
            solveA();
        }
    }

    if (checkD())
    {
        solveD();
        while (checkA())
        {
            solveA();
        }
    }

    // printf("\n");
    // for (int i = 0; i < 4; i++)
    // {
    //     printf("%d %d %d %d\n", input[i][0], input[i][1], input[i][2], input[i][3]);
    // }
    // printf("\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%d %d %d\n", input[i][0], input[i][1], input[i][2]);
    }
    return 0;
}