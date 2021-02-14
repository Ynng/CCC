#include <iostream>
// #include <bits/stdc++.h>
using namespace std;
int n, w;
long long int wt[105];
long long int prof[105];
int main() {
    // ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> w;
    long long int s[n+1][w+1];
    for (int i = 0; i < n; ++i) {
        cin >> wt[i] >> prof[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1;j <=w; ++j) {
            if (wt[i-1] <=j) {
                s[i][j] = max(prof[i-1]+s[i-1][j-wt[i-1]], s[i-1][j]);
            } else{
                s[i][j] = s[i-1][j];
            }
        }
    }
    cout << s[n][w] << endl;
}