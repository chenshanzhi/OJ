// =====================================================================================================================
// http://poj.org/problem?id=2385
// =====================================================================================================================

#include <iostream>
using namespace std;

#define MAX_W 32
#define MAX_T 1002

int T;
int W;
int a[MAX_T];
int dp[MAX_T][MAX_W][2];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T >> W;
  for (int i = 0; i < T; ++i) {
    cin >> a[i];
  }

  // dp[T][*][*] = 0
  for (int i = T - 1; i >= 0; --i) {
    dp[i][0][0] = (a[i] == 1 ? 1 : 0) + dp[i + 1][0][0];
    dp[i][0][1] = (a[i] == 2 ? 1 : 0) + dp[i + 1][0][1];
    for (int j = 1; j <= W; ++j) {
      for (int k = 0; k <= 1; ++k) {
        int u = (a[i] == k + 1 ? 1 : 0) + dp[i + 1][j][k];
        int v = (a[i] != k + 1 ? 1 : 0) + dp[i + 1][j - 1][1 - k];
        dp[i][j][k] = max(u, v);
      }
    }
  }

  cout << dp[0][W][0] << '\n';
  return 0;
}
