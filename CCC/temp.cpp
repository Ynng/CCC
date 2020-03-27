#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;
typedef long long ll;
int base = 131, base2 = 31;
const int mod = 1e9+7;
ll N;
string n, h;
ll a[27], pro[27];
map<string, bool> m;
bool flag = false;
ll cnt = 0;
ll hsh[200002], hsh2[200002];
char nee[200002], hay[200002];
set<pair<ll, ll>> ans; 
long long pow1(long long base, long long exp)
{
    long long ans = 1;
    for (base %= mod; exp; exp >>= 1, base = (base * base) % mod)
        if (exp&1)
            ans = (ans * base) % mod;
    return ans;
}
ll gethash(int r){
    int l = r-n.size()+1;
    return (hsh[r]%mod - (hsh[l-1]*pow1(base, n.size()))%mod+mod)%mod;
}
ll gethash2(int r){
    int l = r-n.size()+1;
    return (hsh2[r]%mod - (hsh2[l-1]*pow1(base2, n.size()))%mod+mod)%mod;
}
int main(){
    cin >> n >> h;
    memset(hsh, 0, sizeof(hsh)); memset(hsh2, 0, sizeof(hsh2)); 
    for(int i=1;i<=n.size();i++){
        nee[i] = n[i-1];
        a[nee[i]-'a']++;
    }
    for(int i=1;i<=h.size();i++){
        hay[i] = h[i-1];
        hsh[i] = ((hsh[i-1]*base + hay[i]-'a'+1)%mod+mod)%mod;
        hsh2[i] = ((hsh2[i-1]*base2 + hay[i] - 'a' + 1)%mod+mod)%mod;
        if(i<n.size()){
            pro[hay[i]-'a']++;
        }
    }
    for(int i=n.size();i<=h.size();i++){
        flag = false;
        pro[hay[i]-'a']++;
        if(i>n.size()) pro[hay[i-n.size()]-'a']--;
        for(int i=0;i<26;i++){
            if(a[i]!=pro[i]){
                flag = true; break;
            }
        }
        if(!flag){
            ans.insert({gethash(i), gethash2(i)});
        }
        
    }
    cout << ans.size() << endl;
    return 0;

}