#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int n, average, tempA, tempB;
    cin >> n;
    tempA = 0;
    for (int i = 0; i < n; i++)
    {
        cin>>tempB;
        tempB*=10;
        tempA+=tempB;
    }
    average=tempA;
    average/=n;
    cout<<(average-average%10)/10<<"."<<average%10<<endl;
    return 0;
}