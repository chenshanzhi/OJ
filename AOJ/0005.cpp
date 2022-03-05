// =====================================================================================================================
// https://onlinejudge.u-aizu.ac.jp/problems/0005
// =====================================================================================================================
#include <iostream>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
  ll r;
  while ((r = a % b) != 0) {
    a = b;
    b = r;
  }
  return b;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll a, b;
  while (cin >> a >> b) {
    ll x = gcd(a, b);
    ll y = a * b / x;
    cout << x << ' ' << y << '\n';
  }
  return 0;
}