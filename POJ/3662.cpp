// ============================================================================
// http://poj.org/problem?id=3662
// ============================================================================
#include <climits>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> PII;

#define MAX_N 1000
int N, P, K;
struct Edge {
  int dst;
  int len;
};
vector<Edge> G[MAX_N];
int dist[MAX_N];
int visited[MAX_N];

void Dijkstra(int s, int x) {
  fill(dist, dist + N, INT_MAX);
  fill(visited, visited + N, false);
  dist[s] = 0;
  priority_queue<PII, vector<PII>, greater<PII> > Q;
  Q.push(make_pair(0, s));
  while (!Q.empty()) {
    int a = Q.top().second;
    Q.pop();
    if (visited[a]) {
      continue;
    }
    visited[a] = true;
    for (int i = 0; i < G[a].size(); ++i) {
      int b = G[a][i].dst;
      int l = (G[a][i].len > x ? 1 : 0);
      if (dist[a] + l < dist[b]) {
        dist[b] = dist[a] + l;
        Q.push(make_pair(dist[b], b));
      }
    }
  }
}

bool pred(int x) {
  Dijkstra(0, x);
  return dist[N - 1] <= K;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> P >> K;
  for (int i = 0; i < P; ++i) {
    int a, b, l;
    cin >> a >> b >> l;
    --a;
    --b;
    G[a].push_back((Edge){ b, l });
    G[b].push_back((Edge){ a, l });
  }

  int l = 0, r = INT_MAX;
  while (l < r) {
    int x = l + (r - l) / 2;
    if (!pred(x)) {
      l = x + 1;
    } else {
      r = x;
    }
  }
  if (l == INT_MAX) {
    cout << -1 << '\n';
  } else {
    cout << l << '\n';
  }

  return 0;
}
