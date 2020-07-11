#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <string>
#include <climits>
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

#define MOD 1000000007

int M, N, K;
int a[30005][1005];
int main()
{
    scanf("%d %d %d", &M, &N, &K);
    for (int i = 0, x, y, r, b; i < K; i++)
    {
        scanf("%d %d %d %d", &x, &y, &r, &b);
        for (int j = max(1, x - r), t, upper, lower; j <= min(N, x + r); j++)
        {
            t = j - x;
            upper = sqrt(r * r - t * t);
            lower = -1 - upper;
            upper = min(M, y + upper);
            lower = max(0, y + lower);
            a[upper][j] += b;
            a[lower][j] -= b;
        }
    }

    int maxb = 0, maxOccur = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = M; j >= 1; j--)
        {
            a[j][i] += a[j + 1][i];
            if (a[j][i] > maxb)
            {
                maxOccur = 1;
                maxb = a[j][i];
            }
            else if (a[j][i] == maxb)
                maxOccur++;
        }
    }

    printf("%d\n%d", maxb, maxOccur);
    return 0;
}