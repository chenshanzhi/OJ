// =====================================================================================================================
// http://poj.org/problem?id=3421
// =====================================================================================================================
#include <iostream>
#include <map>
using namespace std;

typedef long long ll;

ll factorial(int n) {
  ll ret = 1;
  for (int i = 2; i <= n; ++i) {
    ret *= i;
  }
  return ret;
}

void solve(int x) {
  map<int, int> m;
  for (int i = 2; i * i <= x; ++i) {
    while (x % i == 0) {
      m[i]++;
      x /= i;
    }
  }
  if (x != 1) {
    m[x]++;
  }

  int max_len = 0;
  for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it) {
    max_len += it->second;
  }

  ll num = factorial(max_len);
  for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it) {
    num /= factorial(it->second);
  }

  cout << max_len << ' ' << num << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int x;
  while (cin >> x) {
    solve(x);
  }

  return 0;
}