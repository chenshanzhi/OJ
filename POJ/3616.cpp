// =====================================================================================================================
// http://poj.org/problem?id=3616
// =====================================================================================================================

#include <algorithm>
#include <iostream>
using namespace std;

#define MAX_M 1000

typedef long long ll;

int N, M, R;
struct Interval {
  int a, b, w;
} T[MAX_M + 1];
bool operator<(const Interval &lhs, const Interval &rhs) { return lhs.b < rhs.b; }

ll dp[MAX_M + 1];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> R;
  for (int i = 0; i < M; ++i) {
    cin >> T[i].a >> T[i].b >> T[i].w;
    T[i].b += R;
  }
  sort(T, T + M);

  dp[0] = 0;
  for (int i = 0; i < M; ++i) {
    Interval e;
    e.b = T[i].a;
    Interval *p = upper_bound(T, T + i, e);
    int j = p - T;
    dp[i + 1] = max(dp[i], dp[j] + T[i].w);
  }
  cout << dp[M] << '\n';

  return 0;
}