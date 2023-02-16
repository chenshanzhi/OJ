// ============================================================================
// http://poj.org/problem?id=3254
// ============================================================================

#include <iostream>
using namespace std;

#define MAX_M 12
#define MAX_N 12

#define MOD 100000000

int dp[2][1 << MAX_N];
int mask[MAX_M];

bool hasAdjBitSet(int k) {
  while (k) {
    if ((k & 0x3) == 0x3) {
      return true;
    }
    k >>= 1;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int M, N;
  cin >> M >> N;

  for (int i = 0; i < M; ++i) {
    int x = 0;
    for (int j = 0; j < N; ++j) {
      int t;
      cin >> t;
      x = (x << 1) | t;
    }
    mask[i] = x;
  }

  dp[0][0] = 1;
  int prev = 0, curr = 1;
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < (1 << N); ++j) {
      if (dp[prev][j] != 0) {
        for (int k = 0; k < (1 << N); ++k) {
          if (!hasAdjBitSet(k) && (j | k) == (j ^ k) && (k & mask[i]) == k) {
            dp[curr][k] += dp[prev][j];
            dp[curr][k] %= MOD;
          }
        }
        dp[prev][j] = 0;
      }
    }
    swap(prev, curr);
  }

  int ret = 0;
  for (int i = 0; i < (1 << N); ++i) {
    ret += dp[prev][i];
    ret %= MOD;
  }
  cout << ret << '\n';
  return 0;
}
