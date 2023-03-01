// ============================================================================
// http://poj.org/problem?id=3420
// ============================================================================

#include <iostream>
#include <vector>
using namespace std;

#define DIM 4

typedef long long ll;

vector<vector<ll> > mat_mul(const vector<vector<ll> > &a, const vector<vector<ll> > &b, const ll m) {
  vector<vector<ll> > r(DIM, vector<ll>(DIM));
  for (int i = 0; i < DIM; ++i) {
    for (int j = 0; j < DIM; ++j) {
      ll t = 0;
      for (int k = 0; k < DIM; ++k) {
        ll p = a[i][k] * b[k][j];
        while (p < 0) {
          p += m;
        }
        p %= m;
        t += p;
        t %= m;
      }
      r[i][j] = t;
    }
  }
  return r;
}

vector<vector<ll> > mat_pow(const vector<vector<ll> > &a, ll n, ll m) {
  if (n == 1) {
    return a;
  }
  vector<vector<ll> > t = mat_pow(a, n / 2, m);
  if (n % 2) {
    return mat_mul(a, mat_mul(t, t, m), m);
  } else {
    return mat_mul(t, t, m);
  }
}

ll X[DIM] = { 1, 1, 5, 11 };
ll A[DIM][DIM] = {
    { 1, 5, 1, -1 },
    { 1, 0, 0, 0 },
    { 0, 1, 0, 0 },
    { 0, 0, 1, 0 }
};
vector<ll> init_x() {
  vector<ll> ret(DIM);
  for (int i = 0; i < DIM; ++i) {
    ret[i] = X[i];
  }
  return ret;
}
vector<vector<ll> > init_a() {
  vector<vector<ll> > ret(DIM, vector<ll>(DIM));
  for (int i = 0; i < DIM; ++i) {
    for (int j = 0; j < DIM; ++j) {
      ret[i][j] = A[i][j];
    }
  }
  return ret;
}

ll solve(ll n, ll m) {
  vector<ll> x = init_x();
  if (n < DIM) {
    return x[n] % m;
  }
  vector<vector<ll> > a = init_a();
  vector<vector<ll> > r = mat_pow(a, n - DIM + 1, m);
  ll ret = 0;
  for (int k = 0; k < DIM; ++k) {
    ret += (r[0][k] % m) * (x[DIM - 1 - k] % m) % m;
    ret %= m;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll N, M;
  while ((cin >> N >> M) && !(N == 0 && M == 0)) {
    cout << solve(N, M) << '\n';
  }
  return 0;
}
