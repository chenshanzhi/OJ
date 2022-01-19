// =====================================================================================================================
// http://poj.org/problem?id=3040
// =====================================================================================================================

#include <algorithm>
#include <cstring>
#include <iostream>
#include <numeric>
#include <limits>
#include <vector>
using namespace std;

typedef long long ll;

#define MAX_N 21
ll N, C;
ll V[MAX_N];
ll B[MAX_N];
ll idx[MAX_N];
bool cmp(int i, int j) { return V[i] >= V[j]; }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> C;
  for (ll i = 0; i < N; ++i) {
    cin >> V[i] >> B[i];
    idx[i] = i;
  }
  sort(idx, idx + N, cmp);

  ll ret = 0;
  ll t;
  for (t = 0; t < N; ++t) {
    ll i = idx[t];
    if (V[i] < C) {
      break;
    }
    ret += B[i];
    B[i] = 0;
  }

  while (true) {
    ll U[MAX_N];
    memset(U, 0, sizeof(U));
    ll R = C;
    for (ll k = t; k < N && R > 0; ++k) {
      ll i = idx[k];
      ll x = min(B[i], R / V[i]);
      if (x > 0) {
        R -= V[i] * x;
        B[i] -= x;
        U[i] += x;
      }
    }

    for (ll k = N - 1; k >= t && R > 0; --k) {
      ll i = idx[k];
      ll x = min(B[i], R / V[i]  + (R % V[i] == 0 ? 0 : 1));
      if (x > 0) {
        R -= V[i] * x;
        B[i] -= x;
        U[i] += x;
      }
    }

    if (R <= 0) {
      ++ret;
      ll minCount = numeric_limits<ll>::max();
      for (ll i = 0; i < MAX_N; ++i) {
        if (U[i] > 0) {
          minCount = min(minCount, B[i] / U[i]);
        }
      }
      ret += minCount;
      for (ll i = 0; i < MAX_N; ++i) {
        if (U[i] > 0) {
          B[i] -= U[i] * minCount;
        }
      }
    } else {
      break;
    }
  }
  cout << ret << '\n';
  return 0;
}
