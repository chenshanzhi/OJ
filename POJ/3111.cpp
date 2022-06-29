// ============================================================================
// http://poj.org/problem?id=3111
// ============================================================================
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

typedef long long ll;

#define MAX_N 100000
#define MAX_K 100000
int N, K;
int v[MAX_N + 1];
int w[MAX_N + 1];

double f[MAX_N + 1];
int idx[MAX_N + 1];
bool cmp(int i, int j) {
  return f[i] > f[j];
}

double maxSpecific;
int res[MAX_K + 1];

bool pred(double x) {
  for (int i = 0; i < N; ++i) {
    f[i] = v[i] - w[i] * x;
    idx[i] = i;
  }
  sort(idx, idx + N, cmp);
  double s = 0;
  for (int i = 0; i < K; ++i) {
    s += f[idx[i]];
  }

  if (s >= 0 && x > maxSpecific) {
    maxSpecific = x;
    for (int i = 0; i < K; ++i) {
      res[i] = idx[i];
    }
  }
  return s >= 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> K;
  for (int i = 0; i < N; ++i) {
    cin >> v[i] >> w[i];
  }

  maxSpecific = 0.0;
  for (int i = 0; i < K; ++i) {
    res[i] = i;
  }

  double l_real = 0, r_real = 1E7;
  ll l, r;
  memcpy(&l, &l_real, sizeof(double));
  memcpy(&r, &r_real, sizeof(double));
  while (l < r) {
    ll x = l + (r - l) / 2;
    double x_real;
    memcpy(&x_real, &x, sizeof(double));
    if (pred(x_real)) {
      l = x + 1;
    } else {
      r = x;
    }
  }
  for (int i = 0; i < K; ++i) {
    if (i != 0) {
      cout << ' ';
    }
    cout << (res[i] + 1);
  }

  return 0;
}
