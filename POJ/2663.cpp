// ============================================================================
// http://poj.org/problem?id=2663
// ============================================================================

#include <iostream>
using namespace std;

#define MAX_N 30

int dp[MAX_N + 1];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  dp[0] = 1;
  dp[2] = 3;
  for (int i = 4; i <= MAX_N; i += 2) {
    dp[i] = dp[i - 2] * 4 - dp[i - 4];
  }
  
  int x;
  while ((cin >> x) && (0 <= x && x <= MAX_N)) {
    cout << dp[x] << '\n';
  }
  return 0;
}
