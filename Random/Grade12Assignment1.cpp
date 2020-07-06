#include <iostream>
using namespace std;
int main()
{
    int n, tempA, tempB, output, errorCount;
    tempB = errorCount=output= 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {
            tempB++;
            cin >> tempA;
            if (tempA != tempB)errorCount++;
        }
        if (errorCount>=output)output = errorCount;
        errorCount=0;
    }
    cout<<output<<endl;
    return 0;
}