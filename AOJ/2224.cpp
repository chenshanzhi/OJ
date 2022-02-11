// =====================================================================================================================
// https://onlinejudge.u-aizu.ac.jp/problems/2224
// =====================================================================================================================
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

int find(vector<int> &ds, int i) {
  return ds[i] < 0 ? i : (ds[i] = find(ds, ds[i]));
}
void unite(vector<int> &ds, int i, int j) {
  if (ds[i] < ds[j]) {
    ds[j] = i;
  } else {
    if (ds[i] == ds[j]) {
      ds[j]--;
    }
    ds[i] = j;
  }
}

typedef long long ll;
struct Edge {
  int i, j;
  ll d2;
};
bool operator<(const Edge &lhs, const Edge &rhs) {
  return lhs.d2 > rhs.d2;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, M;
  cin >> N >> M;
  vector<ll> X(N), Y(N);
  for (int i = 0; i < N; ++i) {
    cin >> X[i] >> Y[i];
  }
  vector<Edge> es(M);
  for (int i = 0; i < M; ++i) {
    int p, q;
    cin >> p >> q;
    --p; --q;
    ll dx = X[p] - X[q];
    ll dy = Y[p] - Y[q];
    ll d2 = dx * dx + dy * dy;
    es[i].i = p;
    es[i].j = q;
    es[i].d2 = d2;
  }
  sort(es.begin(), es.end());
  
  double ret = 0.0;
  vector<int> ds(N, -1);
  for (int i = 0; i < M; ++i) {
    int a = find(ds, es[i].i);
    int b = find(ds, es[i].j);
    if (a != b) {
      unite(ds, a, b);
    } else {
      ret += sqrt(es[i].d2);
    }
  }
  cout << fixed << setprecision(3) << setfill('0') << ret << '\n';
  return 0;
}