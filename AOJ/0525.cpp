// =====================================================================================================================
// https://onlinejudge.u-aizu.ac.jp/problems/0525
// =====================================================================================================================

#include <bits/stdc++.h>
using namespace std;

#define MAX_C 10001

int R, C;
int G[MAX_C];

int solve() {
  int ret = INT_MAX;
  int mask = (1 << R) - 1;
  for (int i = 0; i <= mask; ++i) {
    int s = 0;
    for (int j = 0; j < C; ++j) {
      int a = __builtin_popcount((G[j] ^ i));
      int b = __builtin_popcount((~G[j] & mask) ^ i);
      s += min(a, b);
    }
    ret = min(ret, s);
  }
  return R * C - ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  while ((cin >> R >> C) && !(R == 0 && C == 0)) {
    fill(G, G + C, 0);
    for (int i = 0; i < R; ++i) {
      for (int j = 0; j < C; ++j) {
        int t;
        cin >> t;
        G[j] |= (t << i);
      }
    }
    cout << solve() << '\n';
  }

  return 0;
}