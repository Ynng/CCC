#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n, counter;
    char oldChar;
    string input, output;
    output = "";
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        counter = 0;
        oldChar = input[0];
        for (int j = 0; j < input.length(); j++)
        {
            if (oldChar == input[j])
            {
                counter++;
            }
            else
            {
                output = output + std::to_string(counter) + ' ' + oldChar + ' ';
                oldChar = input[j];
                counter = 1;
            }
        }
        output = output + std::to_string(counter) + ' ' + oldChar + ' ';
        output = output + "\n";
    }
    cout << output;

    return 0;
}