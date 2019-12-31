#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int smaller(int a, int b)
{
    return a < b ? a : b;
}
int larger(int a, int b)
{
    return a > b ? a : b;
}
int getDistance(int rTarget, int cTarget, int rMove, int cMove, int rObs, int cObs)
{
    int output = 0;
    if ((rTarget == rMove && rMove == rObs && smaller(cMove, cTarget) < cObs && cObs < larger(cMove, cTarget)) || (cTarget == cMove && cMove == cObs && smaller(rMove, rTarget) < rObs && rObs < larger(rMove, rTarget)))
    {
        output += 2;
    }
    output += abs(rTarget - rMove) + abs(cTarget - cMove);
    return output;
}
int main()
{
    int n, rs, cs, re, ce;
    int grid[17][17];
    int rTemp, cTemp, rTempA, cTempA, rTempB, cTempB, lengthA, lengthB;

    int rTarget, cTarget, rMove, cMove, rObs, cObs;
    int output = 0;
    scanf("%d %d %d %d %d", &n, &rs, &cs, &re, &ce);
    memset(grid, 0, sizeof(int) * 17 * 17);
    scanf("%d %d", &rTemp, &cTemp);
    grid[rTemp][cTemp] = 1;
    if (rTemp == rs && cTemp == cs)
    {
        scanf("%d %d", &rTemp, &cTemp);
        grid[rTemp][cTemp] = 1;
        rMove = rTemp;
        cMove = cTemp;
    }
    else
    {
        rMove = rTemp;
        cMove = cTemp;
        scanf("%d %d", &rTemp, &cTemp);
        grid[rTemp][cTemp] = 1;
    }
    rObs = rs;
    cObs = cs;
    grid[rs][cs] = 2;
    while (!(rObs == re && cObs == ce))
    {
        rTemp = re - rObs;
        cTemp = ce - cObs;
        //finding the target of the next step
        if (abs(rTemp) > abs(cTemp))
        {
            //move in r
            if (rTemp > 0)
            {
                //move down
                rTarget = rObs + 1;
                cTarget = cObs;
            }
            else
            {
                rTarget = rObs - 1;
                cTarget = cObs;
            }
        }
        else if (abs(rTemp) < abs(cTemp))
        {
            //move in c
            if (cTemp > 0)
            {
                //move right
                rTarget = rObs;
                cTarget = cObs + 1;
            }
            else
            {
                rTarget = rObs;
                cTarget = cObs - 1;
            }
        }
        else
        {
            //if they are equal
            //move in r
            if (rTemp > 0)
            {
                //move down
                rTempA = rObs + 1;
                cTempA = cObs;
            }
            else
            {
                rTempA = rObs - 1;
                cTempA = cObs;
            }
            //move in c
            if (cTemp > 0)
            {
                //move right
                rTempB = rObs;
                cTempB = cObs + 1;
            }
            else
            {
                rTempB = rObs;
                cTempB = cObs - 1;
            }
            if (getDistance(rTempA, cTempA, rMove, cMove, rObs, cObs) < getDistance(rTempB, cTempB, rMove, cMove, rObs, cObs))
            { 
                rTarget = rTempA;
                cTarget = cTempA;
            }
            else
            {
                rTarget = rTempB;
                cTarget = cTempB;
            }
        }
        //check if the path is obstructed
        output += getDistance(rTarget, cTarget, rMove, cMove, rObs, cObs);
        output += 1;
        //the marble moves over
        rMove = rObs;
        cMove = cObs;
        rObs = rTarget;
        cObs = cTarget;
        // printf("%d %d %d %d", rTarget, cTarget, rMove, cMove);
    }
    printf("%d", output);
    return 0;
}