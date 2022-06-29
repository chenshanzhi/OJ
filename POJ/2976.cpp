// ============================================================================
// http://poj.org/problem?id=2976
// ============================================================================
#include <algorithm>
#include <iostream>
using namespace std;

typedef long long ll;

#define MAX_N 1000
#define D 1000

int N, K;
ll A[MAX_N + 1];
ll B[MAX_N + 1];
ll C[MAX_N + 1];

bool pred(ll x) {
  for (int i = 0; i < N; ++i) {
    C[i] = A[i] * 100 * D - B[i] * x;
  }
  sort(C, C + N);
  ll s = 0;
  for (int i = K; i < N; ++i) {
    s += C[i];
  }
  return s >= 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while ((cin >> N >> K) && !(N == 0 && K == 0)) {
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
    }
    for (int i = 0; i < N; ++i) {
      cin >> B[i];
    }

    ll l = 0, r = 100 * D + 1;
    while (l < r) {
      ll x = l + (r - l) / 2;
      if (pred(x)) {
        l = x + 1;
      } else {
        r = x;
      }
    }
    cout << (ll)((double)(l - 1) / D + 0.5) << '\n';
  }

  return 0;
}
