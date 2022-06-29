// ============================================================================
// http://poj.org/problem?id=3258
// ============================================================================
#include <algorithm>
#include <iostream>
using namespace std;

#define MAX_N 50000

int L, N, M;
int R[MAX_N + 1];

int minDropCount(int x) {
  int ret = 0;
  int prev = 0;
  for (int i = 0; i < N; ++i) {
    if (prev + x <= R[i]) {
      prev = R[i];
    } else {
      ++ret;
    }
  }
  if (prev + x > L) {
    ++ret;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> L >> N >> M;
  for (int i = 0; i < N; ++i) {
    cin >> R[i];
  }
  sort(R, R + N);

  int l = 1, r = L + 1;
  while (l < r) {
    int x = l + (r - l) / 2;
    if (minDropCount(x) <= M) {
      l = x + 1;
    } else {
      r = x;
    }
  }
  cout << (l - 1) << '\n';
  return 0;
}
