// =====================================================================================================================
// http://poj.org/problem?id=1742
// =====================================================================================================================

#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  while ((cin >> n >> m) && !(n == 0 && m == 0)) {
    vector<int> A(n), C(n);
    for (int i = 0; i < n; ++i) {
      cin >> A[i];
    }
    for (int i = 0; i < n; ++i) {
      cin >> C[i];
    }

    vector<int> dp(m + 1, -1);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= m; ++j) {
        if (dp[j] >= 0) {
          dp[j] = C[i];
        } else if (j < A[i] || dp[j - A[i]] <= 0) {
          dp[j] = -1;
        } else {
          dp[j] = dp[j - A[i]] - 1;
        }
      }
    }
    int ret = 0;
    for (int i = 1; i <= m; ++i) {
      if (dp[i] != -1) {
        ++ret;
      }
    }
    cout << ret << '\n';
  }

  return 0;
}