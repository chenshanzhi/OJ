// =====================================================================================================================
// http://poj.org/problem?id=3046
// =====================================================================================================================

#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T, A, S, B;
  cin >> T >> A >> S >> B;
  vector<int> v(T + 1);
  for (int i = 0; i < A; ++i) {
    int e;
    cin >> e;
    v[e]++;
  }

  const int M = 1000000;
  vector<int> dp(B + 1);
  vector<int> ps(B + 1);
  dp[0] = 1;
  ps[0] = 1;
  for (int i = 1; i <= T; ++i) {
    for (int j = 1; j <= B; ++j) {
      ps[j] = (ps[j - 1] + dp[j]) % M;
      if (j <= v[i]) {
        dp[j] = ps[j];
      } else {
        dp[j] = (ps[j] - ps[j - v[i] - 1] + M) % M;
      }
    }
  }

  int ret = 0;
  for (int i = S; i <= B; ++i) {
    ret = (ret + dp[i]) % M;
  }
  cout << ret << '\n';

  return 0;
}