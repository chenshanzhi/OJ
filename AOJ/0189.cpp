// =====================================================================================================================
// https://onlinejudge.u-aizu.ac.jp/problems/0189
// =====================================================================================================================
#include <algorithm>
#include <numeric>
#include <iostream>
#include <vector>
using namespace std;

#define MAX_C 1000
#define MAX_V 10

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  while ((cin >> N) && N) {
    vector<vector<int>> G(MAX_V, vector<int>(MAX_V, MAX_C));
    for (int i = 0; i < N; ++i) {
      int a, b, c;
      cin >> a >> b >> c;
      G[a][a] = G[b][b] = 0;
      G[a][b] = G[b][a] = c;
    }
    vector<int> V;
    for (int i = 0; i < MAX_V; ++i) {
      if (G[i][i] == 0) {
        V.push_back(i);
      }
    }

    int n = V.size();
    vector<vector<int>> dp(n, vector<int>(n, MAX_C));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        dp[i][j] = G[V[i]][V[j]];
      }
    }
    for (int k = 0; k < n; ++k) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
        }
      }
    }

    int dist = MAX_C, index = 0;
    for (int i = 0; i < n; ++i) {
      int d = accumulate(dp[i].begin(), dp[i].end(), 0);
      if (d < dist) {
        dist = d;
        index = i;
      }
    }
    cout << V[index] << ' ' << dist << '\n';
  }
  return 0;
}