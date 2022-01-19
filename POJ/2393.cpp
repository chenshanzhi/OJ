// =====================================================================================================================
// http://poj.org/problem?id=2393
// =====================================================================================================================
#include <algorithm>
#include <iostream>
#include <limits>
using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll n, s;
  cin >> n >> s;
  ll val = numeric_limits<ll>::max();
  ll ret = 0;
  for (ll i = 0; i < n; ++i) {
    ll c, y;
    cin >> c >> y;
    val = min(val, c - i * s);
    ret += y * (val + i * s);
  }
  cout << ret << '\n';

  return 0;
}