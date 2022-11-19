// =====================================================================================================================
// http://poj.org/problem?id=2566
// =====================================================================================================================
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

struct Node {
  int ps, index;
  Node(int s = 0, int i = 0) : ps(s), index(i) {}
  bool operator<(const Node &rhs) const { return ps < rhs.ps; }
};

void solve(vector<Node> &v, int n, int t) {
  int D = INT_MAX;
  int S, A, B;

  int l = 0, r = 0, s = 0;
  for (;;) {
    if (l == r) {
      ++r;
    }

    while (r <= n && (s = v[r].ps - v[l].ps) < t) {
      if (abs(s - t) < D) {
        D = abs(s - t);
        S = s;
        A = v[r].index;
        B = v[l].index;
      }
      ++r;
    }
    if (r > n) {
      break;
    }

    if (abs(s - t) < D) {
      D = abs(s - t);
      S = s;
      A = v[r].index;
      B = v[l].index;
    }

    ++l;
  }

  cout << S << ' ' << min(A, B) + 1 << ' ' << max(A, B) << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  while ((cin >> n >> k) && !(n == 0 && k == 0)) {
    vector<Node> v(n + 1);
    for (int i = 1; i <= n; ++i) {
      cin >> v[i].ps;
      v[i].ps += v[i - 1].ps;
      v[i].index = i;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < k; ++i) {
      int t;
      cin >> t;
      solve(v, n, t);
    }
  }
  return 0;
}
