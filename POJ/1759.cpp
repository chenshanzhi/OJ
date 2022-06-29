// ============================================================================
// http://poj.org/problem?id=1759
// ============================================================================
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long ll;

#define MAX_N 1000
double H[MAX_N + 1];

bool pred(int N, double h1, double h2) {
  H[1] = h1;
  H[2] = h2;
  for (int i = 3; i <= N; ++i) {
    H[i] = 2 * H[i - 1] - H[i - 2] + 2;
    if (H[i] < 0) {
      return false;
    }
  }
  return true;
}

int main() {
  int N;
  double A;
  scanf("%d%lf", &N, &A);

  double l_real = 0, r_real = A;
  ll l, r;
  memcpy(&l, &l_real, sizeof(ll));
  memcpy(&r, &r_real, sizeof(ll));
  while (l < r) {
    ll x = l + (r - l) / 2;
    double x_real;
    memcpy(&x_real, &x, sizeof(ll));
    if (!pred(N, A, x_real)) {
      l = x + 1;
    } else {
      r = x;
    }
  }
  double d;
  memcpy(&d, &l, sizeof(ll));
  pred(N, A, d);
  printf("%.2f\n", H[N]);
  return 0;
}
