// =====================================================================================================================
// https://onlinejudge.u-aizu.ac.jp/problems/2200
// =====================================================================================================================
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define MAX_T 200000

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, M;
  while ((cin >> N >> M) && !(N == 0 && M == 0)) {
    vector<vector<int>> L(N, vector<int>(N, MAX_T));
    vector<vector<int>> S(N, vector<int>(N, MAX_T));
    for (int i = 0; i < N; ++i) {
      L[i][i] = S[i][i] = 0;
    }
    for (int i = 0; i < M; ++i) {
      int x, y, t;
      string s;
      cin >> x >> y >> t >> s;
      --x; --y;
      if (s == "L") {
        L[x][y] = L[y][x] = t;
      } else {
        S[x][y] = S[y][x] = t;
      }
    }
    for (int k = 0; k < N; ++k) {
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
          L[i][j] = min(L[i][j], L[i][k] + L[k][j]);
          S[i][j] = min(S[i][j], S[i][k] + S[k][j]);
        }
      }
    }
    int R;
    cin >> R;
    vector<int> z(R);
    for (int i = 0; i < R; ++i) {
      cin >> z[i];
      z[i]--;
    }
    vector<vector<int>> dp(R, vector<int>(N, MAX_T));
    dp[0][z[0]] = 0;
    for (int i = 0; i + 1 < R; ++i) {
      for (int j = 0; j < N; ++j) {
        for (int k = 0; k < N; ++k) {
          if (k == j) {
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][k] + L[z[i]][z[i + 1]]);
          } else {
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][k] + L[z[i]][k] + S[k][j] + L[j][z[i + 1]]);
          }
        }
      }
    }
    cout << *min_element(dp[R - 1].begin(), dp[R - 1].end()) << '\n';
  }
  return 0;
}