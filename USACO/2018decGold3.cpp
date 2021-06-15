#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MM = 10005, MK = 1005;
ll n, k, a[MM];
pair<ll, ll> dp[MK], pre[MK];
ll best[MM], pre2;
ll tmp;
int main()
{
    ifstream cin("teamwork.in");
    ofstream cout("teamwork.out");
    memset(dp, 0, sizeof dp);
    memset(pre, 0, sizeof pre);
    cin >> n >> k;
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    for (ll i = 1; i <= n; i++)
    {
        dp[1].first = best[i - 1] + a[i];
        dp[1].second = a[i];
        best[i] = dp[1].first;
        for (ll j = 2; j <= k; j++)
        {
            if (j > i)
                break;
            tmp = pre[j - 1].second;
            pre2 = pre[j - 1].first - tmp * (j - 1);
            tmp = max(tmp, a[i]);
            dp[j].first = pre2 + tmp * j;
            dp[j].second = tmp;
            best[i] = max(best[i], dp[j].first);
        }
        swap(dp, pre);
    }
    ll ans = 0;
    for (ll i = 1; i <= k; i++)
    {
        ans = max(ans, pre[i].first);
    }
    cout << ans << "\n";
    return 0;
}