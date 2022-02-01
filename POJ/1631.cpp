// =====================================================================================================================
// http://poj.org/problem?id=1631
// =====================================================================================================================
#include <algorithm>
#include <iostream>
using namespace std;

#define MAX_P 40000
int dp[MAX_P];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, p, e;
  cin >> n;
  while (n--) {
    cin >> p;
    fill(dp, dp + p, p + 1);
    for (int i = 0; i < p; ++i) {
      cin >> e;
      *lower_bound(dp, dp + p, e) = e;
    }
    cout << lower_bound(dp, dp + p, p + 1) - dp << '\n';
  }

  return 0;
}