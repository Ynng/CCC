#include <cmath>
#include <vector>
#include <iostream>

struct MyPoint
{
    double x;
    double y;
};

int signDouble(double input)
{
    if (std::signbit(input))
        return -1;
    else
        return 1;
}

//outputs input clamped between A and B
double clampAdvDouble(double input, double limitA, double limitB)
{
    double bigger = limitA >= limitB ? limitA : limitB;
    double smaller = limitA <= limitB ? limitA : limitB;
    if (input < smaller)
    {
        return smaller;
    }
    else if (input > bigger)
    {
        return bigger;
    }
    else
        return input;
}

double distanceBetween(MyPoint pointA, MyPoint pointB)
{
    return sqrt(pow(pointA.x - pointB.x, 2) + pow(pointA.y - pointB.y, 2));
}

struct TargetPoint
{
    double x;
    double y;
    double d;
    bool online;
};
struct MyLine
{
    MyPoint pointA;
    MyPoint pointB;
    //https://www.desmos.com/calculator/gqb45ium43
    TargetPoint getClosestPoint(MyPoint cur)
    {
        double m, x, y;
        if (pointB.x != pointA.x)
        {
            m = (pointB.y - pointA.y) / (pointB.x - pointA.x);                               //m for slope of the line
            x = (pow(m, 2) * pointA.x - m * pointA.y + cur.x + m * cur.y) / (pow(m, 2) + 1); //finds the x of where the lines meet
            x = clampAdvDouble(x, pointA.x, pointB.x);                                       //clamp it, line segment
            y = m * (x - pointA.x) + pointA.y;                                               //find the y
        }
        else
        {
            x = pointA.x;
            y = clampAdvDouble(cur.y, pointA.y, pointB.y);
        }
        return {x, y, distanceBetween(cur, {x, y}), true};
    }

    //cur must be on this line
    TargetPoint getLookAheadPoint(MyPoint cur, double lookAheadDistance)
    {
        double x, y, m, clamped;
        bool online = true;
        if (pointB.x != pointA.x)
        {
            //https://www.desmos.com/calculator/gqb45ium43
            m = (pointB.y - pointA.y) / (pointB.x - pointA.x); //m for slope of the line
            x = cur.x + signDouble(pointB.x - pointA.x) * fabs(sqrt(pow(lookAheadDistance, 2) / (1 + pow(m, 2))));
            clamped = clampAdvDouble(x, pointA.x, pointB.x);
            if (fabs(x - clamped) > 0.05)
                online = false;
            x = clamped;
            y = m * (x - pointA.x) + pointA.y;
        }
        else
        {
            x = pointA.x;
            y = cur.y + lookAheadDistance * signDouble(pointB.y - pointA.y);
            clamped = clampAdvDouble(y, pointA.y, pointB.y);
            if (fabs(y - clamped) > 0.05)
                online = false;
            y = clamped;
        }
        return {x, y, distanceBetween(cur, {x, y}), online};
    }
};

int main()
{
    double targetX, targetY;
    double minLookAhead = 1.5;
    double maxLookAhead = 5;
    std::vector<MyLine> pathToFollow;
    pathToFollow.push_back({{0, 10}, {0, 40}});
    pathToFollow.push_back({{0, 40}, {-30, 40}});
    pathToFollow.push_back({{-30, 40}, {-30, 10}});
    pathToFollow.push_back({{-30, 10}, {-5, 10}});

    // while (true)
    // {
    MyPoint robotPosition = {0, 0};
    TargetPoint tempTarget = pathToFollow[0].getClosestPoint(robotPosition);
    printf("x: %.2f, y: %.2f, d: %.2f, closest:%d\n", tempTarget.x, tempTarget.y, tempTarget.d, 0);

    TargetPoint closestTarget = tempTarget;
    int closestLineCount = 0;
    //finding the targetPoint with the least distance.....
    for (int i = 1; i < pathToFollow.size(); i++)
    {
        tempTarget = pathToFollow[i].getClosestPoint(robotPosition);
        if (tempTarget.d < closestTarget.d)
        {
            closestTarget = tempTarget;
            closestLineCount = i;
        }
        printf("x: %.2f, y: %.2f, d: %.2f, closest:%d\n", tempTarget.x, tempTarget.y, tempTarget.d, closestLineCount);
    }
    double lookAheadDistance = closestTarget.d < 3 ? (minLookAhead - maxLookAhead) / (3) * (closestTarget.d) + maxLookAhead : minLookAhead;

    TargetPoint lookAheadTarget = pathToFollow[closestLineCount].getLookAheadPoint({closestTarget.x,closestTarget.y}, lookAheadDistance);

    //if the target is already too far and is off the line
    if (!lookAheadTarget.online)
    {
        //and if this line is not the last line
        if (closestLineCount < pathToFollow.size() - 1)
        {
            //just jump to the next line
            closestLineCount += 1;
            closestTarget = pathToFollow[closestLineCount].getClosestPoint(robotPosition);
        }
    }

    //remove all the lines before this one
    for (int i = 0; i < closestLineCount; i++)
    {
        pathToFollow.erase(pathToFollow.begin());
    }

    //now we know our target, just go after it
    targetX = lookAheadTarget.x;
    targetY = lookAheadTarget.y;
    std::cout << targetX << " " << targetY << std::endl;
    std::cout << pathToFollow.size() << std::endl;
    // }
}