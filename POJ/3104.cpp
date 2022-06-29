// ============================================================================
// http://poj.org/problem?id=3104
// ============================================================================

#include <algorithm>
#include <iostream>
using namespace std;

typedef long long ll;

#define MAX_N 100000
int N, K;
int A[MAX_N + 1];

bool pred(int t) {
  ll r = 0;
  for (int i = 0; i < N; ++i) {
    if (A[i] > t) {
      int x = A[i] - t;
      int m = K - 1;
      r += x / m + (x % m != 0 ? 1 : 0);
      // An integer overflow might occur if `r` is an `int`.
      // A[i] is at most 10^9.
      // `N` is at most 10^5.
      // `r` is at most 10^9 * 10^5 = 10^14.
    }
  }
  return r <= t;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int val = 0;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
    val = max(val, A[i]);
  }
  cin >> K;
  if (K == 1) {
    cout << val << '\n';
    return 0;
  }

  int l = 1, r = val + 1;
  while (l < r) {
    int x = l + (r - l) / 2;
    if (!pred(x)) {
      l = x + 1;
    } else {
      r = x;
    }
  }
  cout << l << '\n';

  return 0;
}
