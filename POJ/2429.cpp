// =====================================================================================================================
// http://poj.org/problem?id=2429
// =====================================================================================================================
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

typedef unsigned long long ull;

ull multi(ull a, ull b, ull m) {
  ull ret = 0;
  while (b) {
    if (b & 1) {
      ret = (ret + a) % m;
    }
    a = (a + a) % m;
    b >>= 1;
  }
  return ret;
}

ull binpower(ull b, ull e, ull m) {
  ull ret = 1;
  while (e) {
    if (e & 1) {
      ret = multi(ret, b, m);
    }
    b = multi(b, b, m);
    e >>= 1;
  }
  return ret;
}

bool check_composite(ull n, ull a, ull d, int s) {
  ull x = binpower(a, d, n);
  if (x == 1 || x == n - 1) {
    return false;
  }
  for (int r = 1; r < s; ++r) {
    x = multi(x, x, n);
    if (x == n - 1) {
      return false;
    }
  }
  return true;
}

bool MillerRabin(ull n) {
  if (n < 2) {
    return false;
  }
  int s = 0;
  ull d = n - 1;
  while ((d & 1)) {
    d >>= 1;
    ++s;
  }
  // For testing 64-bit integer, it's enough to check the first 12 prime bases.
  ull base[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 };  
  for (ull i = 0; i < sizeof(base) / sizeof(*base); ++i) {
    ull a = base[i];
    if (n == a) {
      return true;
    }
    if (check_composite(n, a, d, s)) {
      return false;
    }
  }
  return true;
}

ull f(ull x, ull c, ull m) {
  return (multi(x, x, m) + c) % m;
}

ull gcd(ull a, ull b) {
  while (b) {
    ull r = a % b;
    a = b;
    b = r;
  }
  return a;
}

ull Pollard_rho(ull n, ull x0 = 2, ull c = 1) {
  if (n == 1) {
    return 1;
  }
  if (n % 2 == 0) {
    return 2;
  }
  ull x = x0;
  ull y = x0;
  ull g = 1;
  while (g == 1) {
    x = f(x, c, n);
    y = f(y, c, n);
    y = f(y, c, n);
    g = gcd(max(x, y) - min(x, y), n);
  }
  return g;
}

void factor_map(ull n, map<ull, ull> &m) {
  if (n < 2) {
    return;
  }
  if (MillerRabin(n)) {
    m[n]++;
    return;
  }
  ull g = Pollard_rho(n);
  while (g == 1 || g == n) {
    ull c = rand() % (n - 1) + 1;
    g = Pollard_rho(n, 2, c);
  }
  factor_map(g, m);
  factor_map(n / g, m);
}

vector<ull> factors(ull n) {
  map<ull, ull> m;
  factor_map(n, m);
  vector<ull> ret(m.size(), 1);
  ull t = 0;
  for (map<ull, ull>::iterator it = m.begin(); it != m.end(); ++it) {
    for (ull i = 0; i < it->second; ++i) {
      ret[t] *= it->first;
    }
    ++t;
  }
  return ret;
}

ull N;
ull A;
ull minS;
void dfs(vector<ull> &v, ull i, ull a) {
  if (i == v.size()) {
    if (a + N / a < minS) {
      minS = a + N / a;
      A = a;
    }
    return;
  }
  dfs(v, i + 1, a * v[i]);
  dfs(v, i + 1, a);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ull g, l;
  while ((cin >> g >> l) && g) {
    N = l / g;
    vector<ull> v = factors(N);
    minS = N + 1;
    A = 1;
    dfs(v, 0, 1);
    A = min(A, N / A);
    cout << A * g << ' ' << l / A << '\n';
  }
  return 0;
}