// =====================================================================================================================
// http://poj.org/problem?id=3176
// =====================================================================================================================

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;
  vector<int> dp(N + 1, 0);
  for (int i = 1; i <= N; ++i) {
    for (int j = i; j >= 1; --j) {
      int e;
      cin >> e;
      dp[j] = max(dp[j - 1], dp[j]) + e;
    }
  }
  cout << *max_element(dp.begin(), dp.end()) << '\n';
  return 0;
}
