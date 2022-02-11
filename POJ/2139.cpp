// =====================================================================================================================
// http://poj.org/problem?id=2139
// =====================================================================================================================
#include <numeric>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define MAX_C 90000

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, M;
  cin >> N >> M;

  vector<vector<int> > G(N, vector<int>(N, MAX_C));
  for (int k = 0; k < M; ++k) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        int a = v[i] - 1, b = v[j] - 1;
        G[a][b] = (a == b ? 0 : 1);
      }
    }
  }

  for (int k = 0; k < N; ++k) {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
      }
    }
  }

  int ret = INT_MAX;
  for (int i = 0; i < N; ++i) {
    ret = min(ret, accumulate(G[i].begin(), G[i].end(), 0));
  }
  ret *= 100;
  ret /= (N - 1);
  cout << ret << '\n';

  return 0;
}