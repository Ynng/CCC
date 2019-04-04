#include <iostream>
#include <vector>

using namespace std;

bool before[8][8];
bool globalDone = false;

void recur (int loc, vector <int> v2) {
    //cout << loc << endl;
    if (globalDone)
        return;

    if (loc == 7) {
        globalDone = true;
        for (int i = 0; i < 7; i++)
            cout << v2[i] << " ";
        return;
    }

    bool taken[8] = {0,0,0,0,0,0,0,0};
    bool done = false;

    for (int i = 0; i < v2.size(); i++)
        taken[v2[i]] = true;

    //next num
    for (int i = 1; i <= 7; i++) {
        if (taken[i] != true) {
            done = true;
            for (int j = 0; j < v2.size(); j++) {
                if (before[i][v2[j]]) {
                    done = false;
                    break;
                }
            }
            if (done) {
                v2.push_back(i);
                recur(loc+1,v2);
                v2.pop_back();
            }
        }
    }
    nope:;
    return;
}
int main()
{
    vector <int> v;
    int a = -1, b = -1;
    before[1][7] = true;
    before[1][4] = true;
    before[2][1] = true;
    before[3][4] = true;
    before[3][5] = true;

    do {
        cin >> a >> b;
        if (a == 0 && b == 0)
            break;
        before[a][b] = true;
    }while (a!=0 && b != 0);
    recur (0,v);
    if (!globalDone)
        cout << "Cannot complete these tasks. Going to bed." << endl;
}