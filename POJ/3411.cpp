// ============================================================================
// http://poj.org/problem?id=3411
// ============================================================================

#include <climits>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct edge {
  int a, b, c, p, r;
};

struct state {
  int index;
  int mask;
  state(int i, int m) : index(i), mask(m) {}
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, M;
  cin >> N >> M;
  vector<vector<edge> > G(N);
  for (int i = 0; i < M; ++i) {
    edge e;
    cin >> e.a >> e.b >> e.c >> e.p >> e.r;
    --e.a;
    --e.b;
    --e.c;
    G[e.a].push_back(e);
  }

  vector<vector<int> > dist(N, vector<int>(1 << N, INT_MAX));
  queue<state> Q;
  Q.push(state(0, 1));
  dist[0][1] = 0;
  while (!Q.empty()) {
    state s = Q.front();
    int a = s.index;
    int x = s.mask;
    Q.pop();

    for (int k = 0; k < (int)G[a].size(); ++k) {
      int b = G[a][k].b;
      int c = G[a][k].c;
      int p = G[a][k].p;
      int r = G[a][k].r;

      int y = (x | (1 << b));
      if (x & (1 << c)) {
        if (dist[b][y] > dist[a][x] + p) {
          dist[b][y] = dist[a][x] + p;
          Q.push(state(b, y));
        }
      } else {
        if (dist[b][y] > dist[a][x] + r) {
          dist[b][y] = dist[a][x] + r;
          Q.push(state(b, y));
        }
      }
    }
  }

  bool reached = false;
  int cost = INT_MAX;
  for (int i = 0; i < (1 << N); ++i) {
    if (dist[N - 1][i] != INT_MAX) {
      reached = true;
      cost = min(cost, dist[N - 1][i]);
    }
  }

  if (reached) {
    cout << cost << '\n';
  } else {
    cout << "impossible\n";
  }
  return 0;
}

