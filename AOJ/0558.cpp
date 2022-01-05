
// =====================================================================================================================
// https://onlinejudge.u-aizu.ac.jp/problems/0558
// =====================================================================================================================

#include <bits/stdc++.h>
using namespace std;

const int d[4][2] = {{ -1, 0 }, { 0, -1 }, { 0, 1 }, { 1, 0 }};
int H, W, N;
vector<string> G;

int bfs(int &si, int &sj, int ch) {
  vector<vector<int>> visited(H, vector<int>(W, false));
  queue<pair<int, int>> Q;
  visited[si][sj] = true;
  Q.push({si, sj});

  int t = 0;
  while (!Q.empty()) {
    int sz = Q.size();
    while (sz--) {
      auto [i, j] = Q.front();
      Q.pop();
      if (G[i][j] == ch) {
        si = i;
        sj = j;
        return t;
      }

      for (int k = 0; k < 4; ++k) {
        int u = i + d[k][0];
        int v = j + d[k][1];
        if (0 <= u && u < H && 0 <= v && v < W && G[u][v] != 'X' && !visited[u][v]) {
          visited[u][v] = true;
          Q.push({u, v});
        }
      }
    }
    ++t;
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> H >> W >> N;
  G.resize(H);
  int si, sj;
  for (int i = 0; i < H; ++i) {
    cin >> G[i];
    for (int j = 0; j < W; ++j) {
      if (G[i][j] == 'S') {
        si = i;
        sj = j;
      }
    }
  }

  int ret = 0;
  for (int ch = '1'; ch <= '9'; ++ch) {
    ret += bfs(si, sj, ch);
  }
  cout << ret << '\n';

  return 0;
}