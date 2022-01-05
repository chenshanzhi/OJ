// =====================================================================================================================
// http://poj.org/problem?id=3050
// =====================================================================================================================

#include <iostream>
#include <set>
using namespace std;

int G[5][5];
set<int> S;

int dy[] = { -1, 0, 0, 1 };
int dx[] = { 0, -1, 1, 0 };

void dfs(int i, int j, int n, int val) {
  val *= 10;
  val += G[i][j];
  if (n == 5) {
    S.insert(val);
    return;
  }
  for (int k = 0; k < 4; ++k) {
    int u = i + dy[k];
    int v = j + dx[k];
    if (u >= 0 && u < 5 && v >= 0 && v < 5) {
      dfs(u, v, n + 1, val);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      cin >> G[i][j];
    }
  }

  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      dfs(i, j, 0, 0);
    }
  }
  cout << S.size() << '\n';
  return 0;
}