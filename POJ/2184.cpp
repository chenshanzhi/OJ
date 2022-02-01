// =====================================================================================================================
// http://poj.org/problem?id=2184
// =====================================================================================================================

#include <climits>
#include <iostream>
#include <vector>
using namespace std;

#define DP_BASE 100000
#define DP_SIZE 200001

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  vector<int> S(N);
  vector<int> F(N);
  vector<int> dp(DP_SIZE, INT_MIN);
  dp[DP_BASE] = 0;

  for (int i = 0; i < N; ++i) {
    cin >> S[i] >> F[i];

    vector<int> t(dp);
    for (int j = 0; j < DP_SIZE; ++j) {
      if (dp[j] != INT_MIN) {
        t[j + S[i]] = max(t[j + S[i]], dp[j] + F[i]);
      }
    }
    swap(dp, t);
  }

  int ret = 0;
  for (int i = DP_BASE; i < DP_SIZE; ++i) {
    if (dp[i] >= 0) {
      ret = max(ret, dp[i] + i - DP_BASE);
    }
  }
  cout << ret << '\n';

  return 0;
}