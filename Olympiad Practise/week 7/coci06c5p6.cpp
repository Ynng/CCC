#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
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

const ll MOD = 1e9 + 7, MX = 200000 + 5;

int N;
char str[MX];
ll hsh[MX];
ll p[MX];
ll base = 29;

struct hashpair
{
  ll first;
  int second;

  bool operator==(const hashpair &other) const
  {
    return (first == other.first);
  }
};

namespace std {
  template <>
  struct hash<hashpair>
  {
    std::size_t operator()(const hashpair& pair) const
    {
      return std::hash<ll>()(pair.first);
    }
  };
}

unordered_set<hashpair> seenHash;

ll getSubStrHash(int i, int len)
{
  return hsh[i] - (hsh[i - len] * p[len]);
}

int main()
{
  scanf("%d", &N);
  scanf("%s", str);

  p[0] = 1;

  for (int i = 1; i <= N; i++)
    hsh[i] = hsh[i - 1] * base + str[i - 1] - 'a' + 1;
  for (int i = 1; i <= N; i++)
    p[i] = p[i - 1] * base;

  int l = 1, r = N-1;
  int sL; //substring length

  int answer = 0;
  while (l <= r)
  {
    sL = (l + r) / 2;
    seenHash.clear();
    seenHash.insert({getSubStrHash(sL, sL), sL});
    bool found = false;
    for (int i = sL + 1; i <= N; i++)
    {
      ll hash = getSubStrHash(i, sL);
      auto it = seenHash.find({hash, i});
      if (it != seenHash.end())
      {
        int targetStringI = (*it).second;
        bool same = true;
        for (int j = 1; j <= sL; j++)
        {
          if(str[targetStringI - j]!=str[i - j]){
            same = false;
            break;
          }
        }
        if(same){
          found = true;
          break;
        }
      }
      seenHash.insert({hash, i});
    }

    if (found)
    {
      answer = sL;
      l = sL + 1;
    }
    else
    {
      r = sL - 1;
    }
  }

  printf("%d\n", answer);

  return 0;
}