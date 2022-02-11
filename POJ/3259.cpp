// =====================================================================================================================
// http://poj.org/problem?id=3259
// =====================================================================================================================
#include <iostream>
#include <vector>
using namespace std;

#define MAX_T 10000

struct Edge {
  int s, e, t;
};

void solve() {
  int N, M, W;
  cin >> N >> M >> W;
  vector<vector<int> > G(N + 1, vector<int>(N + 1, MAX_T));
  for (int i = 0; i <= N; ++i) {
    G[i][i] = 0;
  }
  int s, e, t;
  for (int i = 0; i < M; ++i) {
    cin >> s >> e >> t;
    G[s][e] = min(G[s][e], t);
    G[e][s] = min(G[e][s], t);
  }
  for (int i = 0; i < W; ++i) {
    cin >> s >> e >> t;
    G[s][e] = -t;
  }
  for (int i = 1; i <= N; ++i) {
    G[0][i] = 0;
  }

  vector<Edge> edges;
  for (int i = 0; i <= N; ++i) {
    for (int j = 0; j <= N; ++j) {
      if (G[i][j] != MAX_T) {
        edges.push_back((Edge) { i, j, G[i][j] });
      }
    }
  }

  vector<int> d(N + 1, MAX_T);
  d[0] = 0;
  for (int i = 0; i <= N; ++i) {
    bool relaxed = false;
    for (int j = 0; j < edges.size(); ++j) {
      s = edges[j].s;
      e = edges[j].e;
      t = edges[j].t;
      if (d[s] + t < d[e]) {
        d[e] = d[s] + t;
        relaxed = true;
      }
    }
    if (i == N && relaxed) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int F;
  cin >> F;
  while (F--) {
    solve();
  }
  return 0;
}