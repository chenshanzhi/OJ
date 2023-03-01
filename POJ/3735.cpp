// ============================================================================
// http://poj.org/problem?id=3735
// ============================================================================

#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int N, M, K;

vector<vector<ll> > mat_one() {
  vector<vector<ll> > a(N + 1, vector<ll>(N + 1));
  for (int i = 0; i <= N; ++i) {
    a[i][i] = 1;
  }
  return a;
}

vector<vector<ll> > sparse_mat_mul(const vector<vector<ll> > &a, const vector<vector<ll> > &b) {
  vector<vector<ll> > r(N + 1, vector<ll>(N + 1));
  for (int i = 0; i <= N; ++i) {
    for (int k = 0; k <= N; ++k) {
      if (a[i][k] == 0) {
        continue;
      }
      for (int j = 0; j <= N; ++j) {
        r[i][j] += a[i][k] * b[k][j];
      }
    }
  }
  return r;
}

vector<vector<ll> > mat_pow(const vector<vector<ll> > &a, int n) {
  if (n == 0) {
    return mat_one();
  }
  vector<vector<ll> > t = mat_pow(a, n / 2);
  if (n % 2) {
    return sparse_mat_mul(a, sparse_mat_mul(t, t));
  } else {
    return sparse_mat_mul(t, t);
  }
}

vector<ll> sparse_vec_mul_mat(const vector<ll> &x, const vector<vector<ll> > &b) {
  vector<ll> r(N + 1);
  for (int j = 0; j <= N; ++j) {
    if (x[j] == 0) {
      continue;
    }
    for (int i = 0; i <= N; ++i) {
      r[i] += x[j] * b[j][i];
    }
  }
  return r;
}

void solve() {
  vector<vector<ll> > a = mat_one();
  for (int k = 0; k < K; ++k) {
    string s;
    ll i, j;
    cin >> s;
    if (s[0] == 'g') {
      cin >> i;
      a[0][i]++;
    } else if (s[0] == 'e') {
      cin >> i;
      for (int k = 0; k <= N; ++k) {
        a[k][i] = 0;
      }
    } else if (s[0] == 's') {
      cin >> i >> j;
      for (int k = 0; k <= N; ++k) {
        swap(a[k][i], a[k][j]);
      }
    }
  }

  a = mat_pow(a, M);

  vector<ll> x(N + 1);
  x[0] = 1;
  vector<ll> v = sparse_vec_mul_mat(x, a);
  for (ll i = 1; i <= N; ++i) {
    cout << v[i] << (i == N ? '\n' : ' ');
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while ((cin >> N >> M >> K) && !(!N && !M && !K)) {
    solve();
  }
  return 0;
}
