// ============================================================================
// UVa 11990
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3141
// ============================================================================

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

ll sum(vector<ll> &v, int n, int i) {
  ll s = 0;
  while (i > 0) {
    s += v[i];
    i -= i & -i;
  }
  return s;
}

void add(vector<ll> &v, int n, int i, ll x) {
  while (i <= n) {
    v[i] += x;
    i += i & -i;
  }
}

const int BUCKET_SZ = 500;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  while (cin >> n >> m) {
    vector<int> A(n), I(n + 1);

    const int nB = n / BUCKET_SZ + 1;

    vector<vector<int>> B(nB, vector<int>());
    vector<ll> tree(n + 1);
    ll n_inv = 0;
    for (int i = 0; i < n; ++i) {
      int t;
      cin >> t;

      A[i] = t;
      I[t] = i;
      B[i / BUCKET_SZ].push_back(t);

      n_inv += i - sum(tree, n, t);
      add(tree, n, t, 1);
    }

    for (int i = 0; i < nB; ++i) {
      sort(B[i].begin(), B[i].end());
    }

    for (int i = 0; i < m; ++i) {
      int t;
      cin >> t;
      cout << n_inv << '\n';

      int b = I[t] / BUCKET_SZ;
      ll delta = 0;
      for (int j = 0; j < b; ++j) {
        delta += B[j].end() - upper_bound(B[j].begin(), B[j].end(), t);
      }
      for (int j = b + 1; j < nB; ++j) {
        delta += lower_bound(B[j].begin(), B[j].end(), t) - B[j].begin();
      }
      for (int j = b * BUCKET_SZ; j < min((b + 1) * BUCKET_SZ, n); ++j) {
        if (A[j] == -1) {
          continue;
        }
        if ((j < I[t] && A[j] > t) || (j > I[t] && A[j] < t)) {
          ++delta;
        }
      }
      A[I[t]] = -1;
      vector<int>::iterator it = find(B[b].begin(), B[b].end(), t);
      B[b].erase(it);
      n_inv -= delta;
    }
  }
  return 0;
}
