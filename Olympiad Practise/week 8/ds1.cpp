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

const int MOD = 1e9 + 7, MX = 100000 + 5;

int N, M;
ll arr[MX];
ll psa[MX];
ll bit[MX];
int freq[MX];
ll freqpsa[MX];
ll freqbit[MX];

ll getSumfreq(int r)
{
  ll sum = 0;
  while (r > 0)
  {
    sum += freqbit[r];
    r ^= (r & -r);
  }
  return sum;
}

ll getSum(int r)
{
  ll sum = 0;
  while (r > 0)
  {
    sum += bit[r];
    r ^= (r & -r);
  }
  return sum;
}

void updatefreq(int dif, int index)
{
  while (index <= MX)
  {
    freqbit[index] += dif;
    index += (index & -index);
  }
}

void update(int dif, int index)
{
  while (index <= N)
  {
    bit[index] += dif;
    index += (index & -index);
  }
}



int main()
{
  scanf("%d %d", &N, &M);
  for (int i = 1; i <= N; i++){
    scanf("%lld", arr + i);
    freq[arr[i]]++;
    psa[i] = arr[i] + psa[i - 1];
    bit[i] = psa[i] - psa[i - (i & -i)];
  }

  for (int i = 1; i < MX; i++)
  {
    freqpsa[i] = freq[i] + freqpsa[i-1];
    freqbit[i] = freqpsa[i] - freqpsa[i - (i & -i)];
  }

  for (int i = 0; i < M; i++)
  {
    char op;
    scanf(" %c", &op);
    switch (op)
    {
    case 'C':
      int index, val;
      scanf(" %d %d", &index, &val);
      update(val - arr[index], index);
      updatefreq(-1, arr[index]);
      updatefreq(1, val);
      arr[index] = val;
      break;
    case 'S':
      int l, r;
      scanf(" %d %d", &l, &r);
      printf("%lld\n", getSum(r) - getSum(l - 1));
      break;
    case 'Q':
      int v;
      scanf(" %d", &v);
      printf("%lld\n", getSumfreq(v));
    }
  }

  return 0;
}