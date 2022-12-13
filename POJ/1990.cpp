// ============================================================================
// http://poj.org/problem?id=1990
// ============================================================================

#include <algorithm>
#include <iostream>
using namespace std;

#define MAX_N 20000
#define MAX_X 20000

typedef long long ll;

struct Cow {
  int v;
  int x;
  bool operator<(const Cow &rhs) const {
    return v < rhs.v;
  }
};
Cow cows[MAX_N + 1];

ll num[MAX_X + 1];
ll pos[MAX_X + 1];

ll sum(ll *a, int i) {
  ll s = 0;
  while (i > 0) {
    s += a[i];
    i -= (i & -i);
  }
  return s;
}

void add(ll *a, int n, int i, ll x) {
  while (i <= n) {
    a[i] += x;
    i += (i & -i);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  for (int i = 0; i < N; ++i) {
    cin >> cows[i].v >> cows[i].x;
  }
  sort(cows, cows + N);

  ll ret = 0;
  for (int i = 0; i < N; ++i) {
    int v = cows[i].v;
    int x = cows[i].x;

    ll nL = sum(num, x);
    ll nR = i - nL;

    ll sL = sum(pos, x);
    ll sR = sum(pos, MAX_X) - sL;

    ret += v * (x * nL - sL);
    ret += v * (sR - x * nR);

    add(num, MAX_X, x, 1);
    add(pos, MAX_X, x, x);
  }
  cout << ret << '\n';
  return 0;
}

