#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int main()
{
    string a, b;
    int counter = 0;
    cin >> a;
    cin >> b;
    for (int i = 0; i < a.length(); i++)
    {
        if (a.at(i) != b.at(i))
            counter++;
    }
    if(counter==1){
        cout<<"LARRY IS SAVED!";
    }else{
        cout<<"LARRY IS DEAD!";
    }
    return 0;
}