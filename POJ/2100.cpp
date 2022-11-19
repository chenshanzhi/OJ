// =====================================================================================================================
// http://poj.org/problem?id=2100
// =====================================================================================================================
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll t;
  cin >> t;

  ll l = 1, r = 1, s = 0;
  vector<pair<ll, ll> > v;
  for (;;) {
    while (r * r <= t && s < t) {
      s += (r * r);
      ++r;
    }
    if (s < t) {
      break;
    }
    if (s == t) {
      v.push_back(make_pair(r - l, l));
    }
    s -= (l * l);
    ++l;
  }
  sort(v.begin(), v.end(), greater<pair<ll, ll> >());

  cout << v.size() << '\n';
  for (int i = 0; i < v.size(); ++i) {
    ll N = v[i].first, L = v[i].second;
    cout << N;
    for (ll j = L; j < L + N; ++j) {
      cout << ' ' << j;
    }
    cout << '\n';
  }
  return 0;
}
