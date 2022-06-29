// ============================================================================
// http://poj.org/problem?id=3579
// ============================================================================
#include <algorithm>
#include <cstdio>
using namespace std;

#define MAX_N 100000
int N;
int M;
int X[MAX_N + 1];

bool pred(int d) {
  int s = 0;
  for (int i = 0; i < N; ++i) {
    int *p = lower_bound(X + i + 1, X + N, X[i] + d);
    s += (p - (X + i + 1));
  }
  return s < M;
}

int main() {
  while (scanf("%d", &N) != EOF) {
    M = (N * (N - 1) / 2 + 1) / 2;
    for (int i = 0; i < N; ++i) {
      scanf("%d", &X[i]);
    }
    sort(X, X + N);

    int l = 0, r = X[N - 1] - X[0] + 1;
    while (l < r) {
      int x = l + (r - l) / 2;
      if (pred(x)) {
        l = x + 1;
      } else {
        r = x;
      }
    }
    printf("%d\n", l - 1);
  }

  return 0;
}
