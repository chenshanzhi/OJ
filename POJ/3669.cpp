// =====================================================================================================================
// http://poj.org/problem?id=3669
// =====================================================================================================================
#include <climits>
#include <iostream>
#include <queue>
using namespace std;

#define MAX_T 1001
#define MAX_N 302

int M;
int G[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

const int dx[4] = { 0, -1, 1, 0 };
const int dy[4] = { 1, 0, 0, -1 };

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  fill(G[0], G[MAX_N], INT_MAX);

  cin >> M;
  for (int i = 0; i < M; ++i) {
    int x, y, t;
    cin >> x >> y >> t;
    G[x][y] = min(G[x][y], t);
    for (int k = 0; k < 4; ++k) {
      int u = x + dx[k];
      int v = y + dy[k];
      if (u >= 0 && u < MAX_N && v >= 0 && v < MAX_N) {
        G[u][v] = min(G[u][v], t);
      }
    }
  }

  queue<int> Qx, Qy;
  if (G[0][0] != 0) {
    Qx.push(0);
    Qy.push(0);
    visited[0][0] = true;
  }

  for (int t = 0; t < MAX_T && !Qx.empty(); ++t) {
    int sz = Qx.size();
    for (int i = 0; i < sz; ++i) {
      int x = Qx.front();
      int y = Qy.front();
      Qx.pop();
      Qy.pop();
      if (G[x][y] == INT_MAX) {
        cout << t << '\n';
        return 0;
      }

      for (int k = 0; k < 4; ++k) {
        int u = x + dx[k];
        int v = y + dy[k];
        if (u >= 0 && u < MAX_N && v >= 0 && v < MAX_N && t + 1 < G[u][v] && !visited[u][v]) {
          Qx.push(u);
          Qy.push(v);
          visited[u][v] = true;
        }
      }
    }
  }
  cout << "-1\n";

  return 0;
}