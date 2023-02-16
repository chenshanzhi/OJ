// ============================================================================
// http://poj.org/problem?id=2441
// ============================================================================

#include <vector>
#include <iostream>
using namespace std;

#define MAX_M 20
#define MAX_N 20

int dp[1 << MAX_M];
int P[MAX_N];
int B[MAX_N][MAX_M];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, M;
  cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    cin >> P[i];
    for (int j = 0; j < P[i]; ++j) {
      cin >> B[i][j];
    }
  }

  dp[0] = 1;
  for (int i = 0; i < N; ++i) {
    for (int t = (1 << M) -  1; t >= 0; --t) {
      if (dp[t] != 0) {
        for (int j = 0; j < P[i]; ++j) {
          int mask = (1 << (B[i][j] - 1));
          if ((t | mask) != t) {
            dp[t | mask] += dp[t];
          }
        }
        dp[t] = 0;
      }
    }
  }

  int s = 0;
  int t = (1 << N) - 1;
  while (t < (1 << M)) {
    s += dp[t];

    int x = t & -t;
    int y = t + x;
    t = ((t & ~y) / x >> 1) | y;
  }
  cout << s << '\n';

  return 0;
}
