// =====================================================================================================================
// http://poj.org/problem?id=3187
// =====================================================================================================================

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 11

int binomial[MAX_N][MAX_N];
void init() {
  binomial[0][0] = 1;
  for (int i = 1; i < MAX_N; ++i) {
    binomial[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      binomial[i][j] = binomial[i - 1][j - 1] + binomial[i - 1][j];
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  init();

  int N, S;
  cin >> N >> S;
  vector<int> v(N);
  for (int i = 0; i < N; ++i) {
    v[i] = i + 1;
  }
  do {
    int sum = 0;
    for (int i = 0; i < N; ++i) {
      sum += v[i] * binomial[N - 1][i];
    }
    if (sum == S) {
      break;
    }
  } while (next_permutation(v.begin(), v.end()));

  for (int i = 0; i < N; ++i) {
    cout << v[i] << (i == N - 1 ? '\n' : ' ');
  }

  return 0;
}