// =====================================================================================================================
// http://poj.org/problem?id=3185
// =====================================================================================================================

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int solve(vector<int> &v, int n, int k) {
  int ret = 0;

  vector<int> dp(n);
  int s = 0;
  for (int i = 0; i + k <= n; ++i) {
    if ((s + v[i]) % 2 != 0) {
      ++ret;
      dp[i] = 1;
      ++s;
    }

    if (i - k + 1 >= 0) {
      s -= dp[i - k + 1];
    }
  }
  for (int i = n - k + 1; i < n; ++i) {
    if ((s + v[i]) % 2 != 0) {
      return INT_MAX;
    }
    if (i - k + 1 >= 0) {
      s -= dp[i - k + 1];
    }
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n = 20;
  int k = 3;

  vector<int> v(n + 2);
  for (int i = 1; i <= n; ++i) {
    cin >> v[i];
  }

  int res = INT_MAX;
  res = min(res, solve(v, n + 2, k));
  v[0] = 1, v[n + 1] = 0;
  res = min(res, solve(v, n + 2, k));
  v[0] = 0, v[n + 1] = 1;
  res = min(res, solve(v, n + 2, k));
  v[0] = 1, v[n + 1] = 1;
  res = min(res, solve(v, n + 2, k));
  cout << res << '\n';

  return 0;
}
