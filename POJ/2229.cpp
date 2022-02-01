// =====================================================================================================================
// http://poj.org/problem?id=2229
// =====================================================================================================================

#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  const int MOD = 1000000000;

  int N;
  cin >> N;
  vector<int> dp(N + 1);
  dp[0] = 1;
  for (int i = 1; i <= N; ++i) {
    if (i % 2) {
      dp[i] = dp[i - 1];
    } else {
      dp[i] = (dp[i / 2] + dp[i - 1]) % MOD;
    }
  }
  cout << dp[N] << '\n';

  return 0;
}