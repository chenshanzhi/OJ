// ============================================================================
// http://poj.org/problem?id=3685
// ============================================================================
#include <algorithm>
#include <iostream>
using namespace std;

typedef long long ll;

const ll C = 1E5;

ll T, N, M;

ll f(ll i, ll j) {
  return i * i + C * (i - j) + j * j + i * j;
}

bool pred(ll x) {
  ll s = 0;
  for (ll j = 1; j <= N; ++j) {
    ll l = 1;
    ll r = N + 1;
    while (l < r) {
      ll m = l + (r - l) / 2;
      if (f(m, j) < x) {
        l = m + 1;
      } else {
        r = m;
      }
    }
    s += (l - 1);
  }
  return s < M;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> T;
  while (T--) {
    cin >> N >> M;
    ll l = - C * N;
    ll r = N * N * 3 + C * N;
    while (l < r) {
      ll x = l + (r - l) / 2;
      if (pred(x)) {
        l = x + 1;
      } else {
        r = x;
      }
    }
    cout << (l - 1) << '\n';
  }
  return 0;
}
