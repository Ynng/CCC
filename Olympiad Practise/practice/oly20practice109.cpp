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

const int MOD = 1e9 + 7, MX = 1e5 + 5;

int N;
pair<int, string> students[MX];
string names[MX];
int main()
{
  scanf("%d", &N);

  for (int i = 0; i < N; i++)
  {
    string name;
    int score;

    cin >> name >> score;
    students[i] = {score, name};
  }

  sort(students, students + N);

  int mid = N / 2;
  int midscore = students[mid].first;
  int namei = 0;

  for (int i = mid; i < N; i++)
  {
    if (students[i].first == midscore)
    {
      names[namei] = students[i].second;
      namei++;
    }
    else
      break;
  }

  int midI = 0;
  for (int i = mid - 1; i >= 0; i--)
  {
    if (students[i].first == midscore)
    {
      names[namei] = students[i].second;
      namei++;
      midI++;
    }
    else
      break;
  }

  sort(names, names + namei);

  printf("%s\n", names[midI].c_str());

  return 0;
}