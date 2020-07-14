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
#define MAXN 100005
#define L(i) (i > N ? i - N : i)

int N, K;
ll arr[MAXN];
ll answer = 0;
set<ll> s;

int main()
{

    scanf("%d %d", &N, &K);
    for (int i = 1; i <= N; i++)
    {
        scanf("%lld", arr + i);
        arr[i] += arr[i - 1];
    }

    for (int i = N - K; i < N; i++)
        s.insert(arr[i] - arr[N]);

    set<ll>::iterator it;
    ll sum;

    for (ll i = 1; i <= N; i++)
    {
        if (i + N - K - 1 <= N)
            it = s.find(arr[i + N - K - 1] - arr[N]);
        else
            it = s.find(arr[i - K - 1]);

        if (it != s.end())
            s.erase(it);
        s.insert(arr[i - 1]);

        sum = arr[i] - *(s.begin());

        if (sum > answer)
            answer = sum;
    }

    printf("%lld", answer);

    return 0;
}