// ============================================================================
// http://poj.org/problem?id=3171
// ============================================================================

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define MAX_T 86400
#define MAX_N 10000
#define MAX_S 500000L
#define MAX_COST (MAX_N * MAX_S)

typedef long long ll;

struct Cow {
  int t1, t2;
  ll s;
  bool operator<(const Cow &rhs) const {
    return t1 < rhs.t1 || (t1 == rhs.t1 && t2 < rhs.t2);
  }
};

vector<ll> data(MAX_T, MAX_COST);
vector<ll> tree(MAX_T * 4, MAX_COST);

void update(int i, ll x, int l, int r, int k) {
  if (l + 1 == r) {
    tree[k] = x;
    return;
  }
  int m = l + (r - l) / 2;
  if (i < m) {
    update(i, x, l, m, k * 2 + 1);
  } else {
    update(i, x, m, r, k * 2 + 2);
  }
  tree[k] = min(tree[k * 2 + 1], tree[k * 2 + 2]);
}

ll query(int a, int b, int l, int r, int k) {
  if (r <= a || b <= l) {
    return MAX_COST;
  } else if (a <= l && r <= b) {
    return tree[k];
  } else {
    int m = l + (r - l) / 2;
    ll vl = query(a, b, l, m, k * 2 + 1);
    ll vr = query(a, b, m, r, k * 2 + 2);
    return min(vl, vr);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, M, E;
  cin >> N >> M >> E;
  ++E;
  vector<Cow> cows(N);
  for (int i = 0; i < N; ++i) {
    cin >> cows[i].t1 >> cows[i].t2 >> cows[i].s;
    cows[i].t2++;
  }
  sort(cows.begin(), cows.end());

  data[M] = 0;
  update(M, 0, 0, E, 0);
  for (int i = 0; i < N; ++i) {
    int t1 = cows[i].t1;
    int t2 = cows[i].t2;
    ll s = cows[i].s;
    ll cost = query(t1, t2, 0, E, 0);
    if (data[t2] > cost + s) {
      data[t2] = cost + s;
      update(t2, cost + s, 0, E, 0);
    }
  }
  cout << (data[E] == MAX_COST ? -1 : data[E]) << '\n';
  return 0;
}
