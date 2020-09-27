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

const int MOD = 1e9 + 7, MX = 1048576 + 5;

int N;
int R[MX];

struct input
{
  char cmd;
  int f;
  int r;
};

int bit[MX];

ll query(int r)
{
  ll sum = 0;
  while (r > 0)
  {
    sum += bit[r];
    r ^= (r & -r);
  }
  return sum;
}

void update(int dif, int index)
{
  while (index <= MX-5)
  {
    bit[index] += dif;
    index += (index & -index);
  }
}

//coordinate compression example

input inputs[MX];
vector<int> inputRatings;
unordered_map<int, int> comp;
int r2f[MX];
int f2r[MX];

int main()
{
  scanf("%d", &N);
  for (int i = 1; i <= N; i++)
  {
    char cmd;
    int x, r, k;
    scanf(" %c", &cmd);

    if (cmd == 'N' || cmd == 'M')
    {
      scanf("%d %d", &x, &r);
      inputs[i] = {cmd, x, r};
      inputRatings.push_back(r);
    }
    else if (cmd == 'Q')
    {
      scanf("%d", &k);
      inputs[i] = {cmd, 0, k};
    }
  }

  sort(inputRatings.begin(), inputRatings.end());
  int last = 0;
  int cc = 1;
  for (int i = inputRatings.size()-1; i >= 0; i--)
  {
    comp[inputRatings[i]] = cc;
    // printf("%d %d\n", inputRatings[i], cc);
    cc++;
  }

  for (int i = 1; i <= N; i++)
  {
    input cur = inputs[i];
    if (cur.cmd == 'N')
    {
      int rating = comp[cur.r];
      r2f[rating] = cur.f;
      f2r[cur.f] = rating;
      update(1, rating);
    }
    else if (cur.cmd == 'M')
    {
      int old = f2r[cur.f];
      update(-1, old);
      r2f[old] = 0;
      int rating = comp[cur.r];
      r2f[rating] = cur.f;
      f2r[cur.f] = rating;
      update(1, rating);
    }else if(cur.cmd=='Q'){
      int rank = cur.r;
      int pos = 0;
      int b = 1048576;
      int answer;
      while(b > 0){
        pos^=b;
        int q = query(pos);
        if(q>=rank)
          pos^=b;
        answer = pos;
        b>>=1;
      }
      printf("%d\n", r2f[answer+1]);
    }
  }

  return 0;
}