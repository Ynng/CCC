#include <iostream>
#include <string>
using namespace std;
int main()
{
    bool horizontal, vertical;
    string input;
    input = "test";
    horizontal = vertical = false;
    std::getline(cin, input);
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == 'H')
            horizontal = !horizontal;
        else
            vertical = !vertical;
    }
    if ((!vertical) && (!horizontal))
    {
        cout << "1 2\n3 4";
    }
    else if (vertical && horizontal)
    {
        cout << "4 3\n2 1";
    }
    else if (vertical)
    {
        cout << "2 1\n4 3";
    }
    else
    {
        cout << "3 4\n1 2";
    }
    return 0;
}