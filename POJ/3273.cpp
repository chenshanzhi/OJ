// ============================================================================
// http://poj.org/problem?id=3273
// ============================================================================
#include <iostream>
using namespace std;

#define MAX_N 100000

int N, M;
int S[MAX_N + 1];

int minMonth(int x) {
  int month = 0;
  int curr = 0;
  for (int i = 0; i < N; ++i) {
    if (curr + S[i] <= x) {
      curr += S[i];
    } else {
      ++month;
      curr = S[i];
    }
  }
  if (curr != 0) {
      ++month;
  }
  return month;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int l = 0, r = 1;
  cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    cin >> S[i];
    l = max(l, S[i]);
    r += S[i];
  }

  while (l < r) {
    int x = l + (r - l) / 2;
    if (minMonth(x) > M) {
      l = x + 1;
    } else {
      r = x;
    }
  }
  cout << l << '\n';

  return 0;
}
